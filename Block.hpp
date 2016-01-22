#ifndef BLOCK_H
#define BLOCK_H

#include "csv/common.hpp"
#include <string>
#include "common.hpp"
#include "Row.hpp"
#include <vector>
#include <boost/optional.hpp>

class Block
{
	public:
		Block(const csv::row_t &row);
		Block(const Block &other);
		virtual ~Block();

		system_clock::time_point end_time() const;

		std::string name;
		unsigned int columns;
		system_clock::time_point start_time;
		boost::optional<std::string> parent_name;
		system_clock::duration setup_time, row_time, cleanup_time;
		std::vector<Row> rows;

		void create_rows(unsigned int teamcnt);
};

#endif // BLOCK_H
