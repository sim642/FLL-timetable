#ifndef GENERATOR_H
#define GENERATOR_H

#include "AbstractGenerator.hpp"
#include <random>

class Generator : public AbstractGenerator
{
	public:
		Generator(State &n_s, float n_discard);
		virtual ~Generator();

		virtual bool generate();

	private:
		bool generate_(int i, int j);

		decltype(State::teams) &teams;
		decltype(State::blocks) &blocks;

		std::mt19937 g;

		float discard;
};

#endif // GENERATOR_H
