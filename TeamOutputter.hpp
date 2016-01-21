#ifndef TEAMOUTPUTTER_H
#define TEAMOUTPUTTER_H

#include "Outputter.hpp"

class TeamOutputter : public Outputter
{
	public:
		TeamOutputter(std::vector<Team> &n_teams, std::vector<Block> &n_blocks);
		virtual ~TeamOutputter();

		virtual void output(const std::string &filename);
};

#endif // TEAMOUTPUTTER_H
