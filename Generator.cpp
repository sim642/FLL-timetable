#include "Generator.hpp"
#include <algorithm>

Generator::Generator(State &n_s, float n_discard) : AbstractGenerator(n_s), teams(s.teams), blocks(s.blocks), g(std::random_device()()), discard(n_discard)
{

}

Generator::~Generator()
{

}

bool Generator::generate()
{
	return generate_(0, 0);
}

bool Generator::generate_(size_t i, size_t j)
{
	if (i == teams.size())
		return true;
	else if (j == blocks.size())
		return generate_(i + 1, 0);
	else
	{
		Team &team = teams[i];

		std::vector<Row*> rows;
		for (auto &row : blocks[j].rows)
			rows.emplace_back(&row);

		std::shuffle(rows.begin(), rows.end(), g);

		auto end = rows.begin() + rows.size() * (1.f - discard);
		for (auto it = rows.begin(); it != end; ++it)
		{
			auto &row = **it;
			if ((blocks[j].columns - row.teams.size() > 0) && !row.any_conflicts(team.rows))
			{
				team.rows.push_back(&row);
				row.teams.push_back(&team);

				bool r = generate_(i, j + 1);
				if (r)
					return true;

				row.teams.pop_back();
				team.rows.pop_back();
			}
		}
		return false;
	}
}
