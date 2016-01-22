#include "Block.hpp"
#include <cmath>
#include "common.hpp"

Block::Block(const csv::row_t &row)
{
	name = row.find("name")->second;
	columns = stoi(row.find("columns")->second);
	start_time = strptime(row.find("start_time")->second, time_format);
	setup_time = std::chrono::minutes(stoi(row.find("setup_time")->second));
	row_time = std::chrono::minutes(stoi(row.find("row_time")->second));
	cleanup_time = std::chrono::minutes(stoi(row.find("cleanup_time")->second));
}

Block::Block(const Block &other) : name(other.name), columns(other.columns), start_time(other.start_time), setup_time(other.setup_time), row_time(other.row_time), cleanup_time(other.cleanup_time)
{
	for (auto &row : other.rows)
		rows.emplace_back(row, *this);
}

Block::~Block()
{

}

void Block::create_rows(unsigned int teamcnt)
{
	unsigned int rowcnt = std::ceil(float(teamcnt) / columns);
	for (unsigned int i = 0; i < rowcnt; i++)
		rows.emplace_back(*this, i);
}
