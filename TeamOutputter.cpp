#include "TeamOutputter.hpp"
#include <fstream>
#include "csv/csv.hpp"

TeamOutputter::TeamOutputter(std::vector<Team>& n_teams, std::vector<Block>& n_blocks) : Outputter(n_teams, n_blocks)
{

}

TeamOutputter::~TeamOutputter()
{

}

void TeamOutputter::output(const std::string& filename)
{
	std::ofstream fout(filename);

	std::vector<std::string> cols = {"name"};
	for (auto &block : blocks)
		cols.emplace_back(block.name);
	csv::output_iterator it(fout, cols);

    for (auto &team : teams)
    {
		csv::row_t csvrow;
		csvrow["name"] = team.name;
		for (auto &row : team.rows)
			csvrow[row->block.name] = strftime("%Y-%m-%d %H:%M", row->start_time);
		*it++ = csvrow;
    }
}