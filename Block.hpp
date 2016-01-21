#ifndef BLOCK_H
#define BLOCK_H

#include "csv/common.hpp"
#include <string>
#include "common.hpp"
#include "Row.hpp"
#include <vector>

class Block
{
	public:
		Block(const csv::row_t &row);
		virtual ~Block();

		std::string name;
		int columns;
		system_clock::time_point start_time;
		system_clock::duration setup_time, row_time, cleanup_time;
		std::vector<Row> rows;

		void create_rows(int teamcnt);
};

#endif // BLOCK_H
