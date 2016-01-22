#ifndef MULTIGENERATOR_H
#define MULTIGENERATOR_H

#include "AbstractGenerator.hpp"
#include <functional>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>

class MultiGenerator : public AbstractGenerator
{
	public:
		typedef std::function<void(std::thread::id, bool)> ret_func_t;

		MultiGenerator(State &n_s, ret_func_t n_ret_func = ret_func_t());
		virtual ~MultiGenerator();

		virtual bool generate();

	private:
		void run();

		std::vector<std::thread> threads;

		std::mutex ret_func_mutex;
		ret_func_t ret_func;

		std::mutex done_mutex;
		std::condition_variable done_cv;
		std::atomic<bool> done;
};

#endif // MULTIGENERATOR_H
