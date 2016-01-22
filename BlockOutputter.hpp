#ifndef BLOCKOUTPUTTER_H
#define BLOCKOUTPUTTER_H

#include "Outputter.hpp"
#include "Block.hpp"

class BlockOutputter : public Outputter
{
	public:
		BlockOutputter(State &n_s, std::size_t i);
		virtual ~BlockOutputter();

		virtual void output(const std::string &filename);

	private:
		Block &block;
};

#endif // BLOCKOUTPUTTER_H
