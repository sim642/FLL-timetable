#include "BlockOutputter.hpp"
#include <fstream>
#include "csv/csv.hpp"

BlockOutputter::BlockOutputter(State &n_s, std::size_t i) : Outputter(n_s), block(blocks[i])
{

}

BlockOutputter::~BlockOutputter()
{

}

void BlockOutputter::output(const std::string& filename)
{
	std::ofstream fout(filename);

	csv::cols_t cols = {"start_time"};
	for (std::size_t i = 0; i < block.columns; i++)
		cols.emplace_back(std::to_string(i));
	csv::output_iterator it(fout, cols);

	for (auto &row : block.rows)
	{
		csv::row_t csvrow;
		csvrow["start_time"] = strftime("%Y-%m-%d %H:%M", row.start_time);
		for (std::size_t i = 0; i < block.columns; i++)
			csvrow[std::to_string(i)] = row.teams[i]->name;
		*it++ = csvrow;
	}
}
