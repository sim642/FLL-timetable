#include "Generator.hpp"
#include <algorithm>

Generator::Generator(std::vector<Team>& n_teams, std::vector<Block>& n_blocks) : teams(n_teams), blocks(n_blocks), g(std::random_device()())
{

}

Generator::~Generator()
{

}

bool Generator::generate(int i, int j)
{
	if (i == teams.size())
		return true;
	else if (j == blocks.size())
		return generate(i + 1, 0);
	else
	{
		Team &team = teams[i];

		std::vector<Row*> rows;
		for (auto &row : blocks[j].rows)
			rows.emplace_back(&row);

		std::shuffle(rows.begin(), rows.end(), g);

		//for (auto &row : rows)
		for (int k = 0; k < rows.size() / 2; k++)
		{
			auto &row = *rows[k];
			if ((blocks[j].columns - row.teams.size() > 0) && !row.any_conflicts(team.rows))
			{
				team.rows.push_back(&row);
				row.teams.push_back(&team);

				bool r = generate(i, j + 1);
				if (r)
					return true;

				row.teams.pop_back();
				team.rows.pop_back();
			}
		}
	}
}
