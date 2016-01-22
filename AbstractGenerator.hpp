#ifndef ABSTRACTGENERATOR_H
#define ABSTRACTGENERATOR_H

#include "State.hpp"

class AbstractGenerator
{
	public:
		AbstractGenerator(State &n_s);
		virtual ~AbstractGenerator();

		virtual bool generate() = 0;

	protected:
		State &s;
};

#endif // ABSTRACTGENERATOR_H
