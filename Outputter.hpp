#ifndef OUTPUTTER_H
#define OUTPUTTER_H

#include <string>
#include <vector>
#include "Team.hpp"
#include "Block.hpp"

class Outputter
{
	public:
		Outputter(std::vector<Team> &n_teams, std::vector<Block> &n_blocks);
		virtual ~Outputter();

		virtual void output(const std::string &filename) = 0;

	protected:
		std::vector<Team> &teams;
		std::vector<Block> &blocks;
};

#endif // OUTPUTTER_H
