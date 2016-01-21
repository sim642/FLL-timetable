#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include "Team.hpp"
#include "Block.hpp"

class Generator
{
	public:
		Generator(std::vector<Team> &n_teams, std::vector<Block> &n_blocks);
		virtual ~Generator();

		bool generate(int i = 0, int j = 0);

	private:
		std::vector<Team> &teams;
		std::vector<Block> &blocks;
};

#endif // GENERATOR_H
