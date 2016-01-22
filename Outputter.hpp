#ifndef OUTPUTTER_H
#define OUTPUTTER_H

#include <string>
#include "State.hpp"

class Outputter
{
	public:
		Outputter(State &n_s);
		virtual ~Outputter();

		virtual void output(const std::string &filename) = 0;

	protected:
		State &s;

		decltype(State::teams) &teams;
		decltype(State::blocks) &blocks;
};

#endif // OUTPUTTER_H
