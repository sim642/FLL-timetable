#include "Block.hpp"
#include <cmath>
#include "common.hpp"

Block::Block(const csv::row_t &row)
{
	name = row.find("name")->second;
	columns = stoi(row.find("columns")->second);
	try
	{
		start_time = strptime(row.find("start_time")->second, time_format);
		parent_name = boost::none;
	}
	catch (const std::runtime_error &e)
	{
		start_time = system_clock::time_point::min();
		parent_name = row.find("start_time")->second;
	}
	setup_time = std::chrono::minutes(stoi(row.find("setup_time")->second));
	row_time = std::chrono::minutes(stoi(row.find("row_time")->second));
	cleanup_time = std::chrono::minutes(stoi(row.find("cleanup_time")->second));
	after_name = row.find("after_name")->second;
	if (after_name->empty())
		after_name = boost::none;
}

Block::Block(const Block &other) : name(other.name), columns(other.columns), start_time(other.start_time), parent_name(other.parent_name), setup_time(other.setup_time), row_time(other.row_time), cleanup_time(other.cleanup_time), after_name(other.after_name)
{
	for (auto &row : other.rows)
		rows.emplace_back(row, *this);
}

Block::~Block()
{

}

system_clock::time_point Block::end_time() const
{
	if (!rows.empty())
		return rows.back().end_time();
	else
		return start_time;
}

void Block::create_rows(unsigned int teamcnt)
{
	unsigned int rowcnt = std::ceil(float(teamcnt) / columns);
	for (unsigned int i = 0; i < rowcnt; i++)
		rows.emplace_back(*this, i);
}
