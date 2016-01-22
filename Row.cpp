#include "Row.hpp"
#include "Block.hpp"

Row::Row(const Block &n_block, int i) : block(n_block)
{
	start_time = block.start_time + i * (block.row_time + block.cleanup_time);
}

Row::Row(const Row &other, const Block &n_block) : block(n_block), start_time(other.start_time), teams(other.teams)
{

}

Row::~Row()
{

}

system_clock::time_point Row::end_time() const
{
	return start_time + block.row_time + block.cleanup_time;
}

bool Row::during(const system_clock::time_point& tp) const
{
	return (start_time - block.setup_time <= tp) && (tp < start_time + block.row_time);
}

bool Row::conflicts(const Row& other) const
{
	return during(other.start_time) || other.during(start_time);
}

bool Row::any_conflicts(const std::vector<Row*>& others) const
{
	for (auto &other : others)
	{
		if (conflicts(*other))
			return true;
	}
	return false;
}
