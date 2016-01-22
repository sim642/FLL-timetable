#ifndef GENERATOR_H
#define GENERATOR_H

#include "State.hpp"
#include <random>

class Generator
{
	public:
		Generator(State &n_s);
		virtual ~Generator();

		bool generate(int i = 0, int j = 0);

	private:
		decltype(State::teams) &teams;
		decltype(State::blocks) &blocks;

		std::mt19937 g;
};

#endif // GENERATOR_H
