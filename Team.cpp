#include "Team.hpp"

Team::Team(const csv::row_t &row)
{
	name = row.find("name")->second;
}

Team::~Team()
{

}
