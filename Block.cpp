#include "Block.hpp"
#include <cmath>

Block::Block(const csv::row_t &row)
{
	name = row.find("name")->second;
	columns = stoi(row.find("columns")->second);
	start_time = strptime(row.find("start_time")->second, "%Y-%m-%d %H:%M");
	setup_time = std::chrono::minutes(stoi(row.find("setup_time")->second));
	row_time = std::chrono::minutes(stoi(row.find("row_time")->second));
	cleanup_time = std::chrono::minutes(stoi(row.find("cleanup_time")->second));
}

Block::~Block()
{

}

void Block::create_rows(int teamcnt)
{
	int rowcnt = std::ceil(float(teamcnt) / columns);
	for (int i = 0; i < rowcnt; i++)
		rows.emplace_back(*this, i);
}
