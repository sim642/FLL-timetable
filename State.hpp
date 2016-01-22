#ifndef STATE_H
#define STATE_H

#include "Team.hpp"
#include "Block.hpp"
#include <vector>

class State
{
	public:
		std::vector<Team> teams;
		std::vector<Block> blocks;
};

#endif // STATE_H
