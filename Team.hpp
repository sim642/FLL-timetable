#ifndef TEAM_H
#define TEAM_H

#include "csv/common.hpp"
#include <string>
#include <vector>

class Row;

class Team
{
	public:
		Team(const csv::row_t &row);
		virtual ~Team();

		std::string name;
		std::vector<Row*> rows;
};

#endif // TEAM_H
