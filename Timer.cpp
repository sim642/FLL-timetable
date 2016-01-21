#include "Timer.hpp"

Timer::Timer()
{
	reset();
}

Timer::~Timer()
{

}

Timer::duration Timer::get() const
{
	return clock::now() - start;
}

Timer::duration Timer::reset()
{
	auto dur = get();
	start = clock::now();
	return dur;
}
