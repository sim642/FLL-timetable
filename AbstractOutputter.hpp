#ifndef ABSTRACTOUTPUTTER_H
#define ABSTRACTOUTPUTTER_H

#include <string>
#include "State.hpp"

class AbstractOutputter
{
	public:
		AbstractOutputter(State &n_s);
		virtual ~AbstractOutputter();

		virtual void output(const std::string &filename) = 0;

	protected:
		State &s;

		decltype(State::teams) &teams;
		decltype(State::blocks) &blocks;
};

#endif // ABSTRACTOUTPUTTER_H
