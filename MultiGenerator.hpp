#ifndef MULTIGENERATOR_H
#define MULTIGENERATOR_H

#include "Generator.hpp"
#include "State.hpp"
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>

class MultiGenerator
{
	public:
		MultiGenerator(State &n_s);
		virtual ~MultiGenerator();

		bool generate();

	private:
		void run();

		State &s;

		std::vector<std::thread> threads;

		std::mutex done_mutex;
		std::condition_variable done_cv;
		std::atomic<bool> done;
};

#endif // MULTIGENERATOR_H
