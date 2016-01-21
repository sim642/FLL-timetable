#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
	public:
		typedef std::chrono::high_resolution_clock clock;
		typedef clock::duration duration;

		Timer();
		virtual ~Timer();

		duration get() const;
		duration reset();

	private:
		clock::time_point start;
};

#endif // TIMER_H
