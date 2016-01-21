#ifndef ROW_H
#define ROW_H

#include "common.hpp"
#include <vector>

class Block;
class Team;

class Row
{
	public:
		Row(const Block &n_block, int i);
		virtual ~Row();

		bool during(const system_clock::time_point &tp) const;
		bool conflicts(const Row &other) const;
		bool any_conflicts(const std::vector<Row> &others) const;

		const Block &block;
		system_clock::time_point start_time;
		std::vector<Team*> teams;
};

#endif // ROW_H
