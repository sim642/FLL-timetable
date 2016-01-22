#include "MultiGenerator.hpp"
#include "Generator.hpp"
#include <memory>

MultiGenerator::MultiGenerator(State &n_s) : AbstractGenerator(n_s), done(false)
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
	}
	while (!done && !r);

	if (r)
	{
		std::lock_guard<std::mutex> lk(done_mutex);
		done = true;
		done_cv.notify_all();
	}
}
