#include "State.hpp"
#include <algorithm>

void State::create_rows()
{
	for (auto &block : blocks)
	{
		if (!block.parent_name.empty())
		{
			auto it = std::find_if(blocks.begin(), blocks.end(), [&block](const Block &other)
			{
				return other.name == block.parent_name;
			});
			if (it == blocks.end())
				throw std::runtime_error("State::create_rows: no parent found");
			block.start_time = it->end_time();
		}

		block.create_rows(teams.size());
	}
}
