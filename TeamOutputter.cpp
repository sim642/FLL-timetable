#include "TeamOutputter.hpp"
#include <fstream>
#include "csv/csv.hpp"
#include "common.hpp"

TeamOutputter::TeamOutputter(State &n_s) : AbstractOutputter(n_s)
{

}

TeamOutputter::~TeamOutputter()
{

}

void TeamOutputter::output(const std::string& filename)
{
	std::ofstream fout(filename);

	csv::cols_t cols = {"name"};
	for (auto &block : blocks)
		cols.emplace_back(block.name);
	csv::output_iterator it(fout, cols);

    for (auto &team : teams)
    {
		csv::row_t csvrow;
		csvrow["name"] = team.name;
		for (auto &row : team.rows)
			csvrow[row->block.name] = strftime(time_format, row->start_time);
		*it++ = csvrow;
    }
}
