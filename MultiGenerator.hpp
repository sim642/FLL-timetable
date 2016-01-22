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
		typedef std::function<AbstractGenerator*(State&)> gen_func_t;
		typedef std::function<void(unsigned int, bool)> ret_func_t;

		MultiGenerator(State &n_s, unsigned int n_threadcnt, gen_func_t n_gen_func = gen_func_t(), ret_func_t n_ret_func = ret_func_t());
		virtual ~MultiGenerator();

		virtual bool generate();

	private:
		void run(unsigned int thread_i);

		const unsigned int threadcnt;
		std::vector<std::thread> threads;

		gen_func_t gen_func;

		std::mutex ret_func_mutex;
		ret_func_t ret_func;

		std::mutex done_mutex;
		std::condition_variable done_cv;
		std::atomic<bool> done;
};

#endif // MULTIGENERATOR_H
