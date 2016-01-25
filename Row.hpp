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
		Row(const Row &other, const Block &n_block);
		virtual ~Row();

		system_clock::time_point end_time() const;

		bool during(const system_clock::time_point &tp) const;
		bool conflicts(const Row &other) const;
		bool any_conflicts(const std::vector<Row*> &others) const;
		bool after(const Row &other) const;
		bool after(const std::vector<Row*> &others) const;

		const Block &block;
		system_clock::time_point start_time;
		std::vector<Team*> teams;
};

#endif // ROW_H
