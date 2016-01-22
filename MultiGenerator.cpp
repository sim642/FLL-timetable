#include "MultiGenerator.hpp"
#include <memory>

MultiGenerator::MultiGenerator(State &n_s, unsigned int n_threadcnt, gen_func_t n_gen_func, ret_func_t n_ret_func) : AbstractGenerator(n_s), threadcnt(n_threadcnt == 0 ? std::thread::hardware_concurrency() : n_threadcnt), gen_func(n_gen_func), ret_func(n_ret_func), done(false)
{

}

MultiGenerator::~MultiGenerator()
{

}

bool MultiGenerator::generate()
{
	for (unsigned int i = 0; i < threadcnt; i++)
		threads.emplace_back(&MultiGenerator::run, this, i);

	for (auto &thread : threads)
		thread.join();

	std::unique_lock<std::mutex> lk(done_mutex);
	done_cv.wait(lk, [this]{ return done.load(); });
	return true;
}

void MultiGenerator::run(unsigned int thread_i)
{
	State local_s(s);

	bool r;
	do
	{
		std::unique_ptr<AbstractGenerator> g(gen_func(local_s));
		r = g->generate();

		{
			std::lock_guard<std::mutex> lk(ret_func_mutex);
			ret_func(thread_i, r);
		}
	}
	while (!done && !r);

	if (r)
	{
		std::lock_guard<std::mutex> lk(done_mutex);
		done = true;
		s = std::move(local_s); // TODO: confirm this doesn't break anything
		done_cv.notify_all();
	}
}
