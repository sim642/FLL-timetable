#ifndef ABSTRACTGENERATOR_H
#define ABSTRACTGENERATOR_H

#include "State.hpp"
#include <atomic>

class AbstractGenerator
{
	public:
		AbstractGenerator(State &n_s);
		virtual ~AbstractGenerator();

		virtual bool generate() = 0;

		std::atomic<bool> *cancel;
	protected:
		bool should_cancel() const;

		State &s;
};

#endif // ABSTRACTGENERATOR_H
