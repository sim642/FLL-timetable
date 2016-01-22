#ifndef MULTIGENERATOR_H
#define MULTIGENERATOR_H

#include "AbstractGenerator.hpp"
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>

class MultiGenerator : public AbstractGenerator
{
	public:
		MultiGenerator(State &n_s);
		virtual ~MultiGenerator();

		virtual bool generate();

	private:
		void run();

		std::vector<std::thread> threads;

		std::mutex done_mutex;
		std::condition_variable done_cv;
		std::atomic<bool> done;
};

#endif // MULTIGENERATOR_H
