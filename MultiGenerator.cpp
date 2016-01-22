#include "MultiGenerator.hpp"
#include "Generator.hpp"
#include <memory>

MultiGenerator::MultiGenerator(State &n_s, ret_func_t n_ret_func) : AbstractGenerator(n_s), ret_func(n_ret_func), done(false)
{

}

MultiGenerator::~MultiGenerator()
{

}

bool MultiGenerator::generate()
{
	threads.emplace_back(&MultiGenerator::run, this);

	for (auto &thread : threads)
		thread.join();

	std::unique_lock<std::mutex> lk(done_mutex);
	done_cv.wait(lk, [this]{ return done.load(); });
	return true;
}

void MultiGenerator::run()
{
	bool r;
	do
	{
		std::unique_ptr<AbstractGenerator> g(new Generator(s));
		r = g->generate();

		{
			std::lock_guard<std::mutex> lk(ret_func_mutex);
			ret_func(std::this_thread::get_id(), r);
		}
	}
	while (!done && !r);

	if (r)
	{
		std::lock_guard<std::mutex> lk(done_mutex);
		done = true;
		done_cv.notify_all();
	}
}
