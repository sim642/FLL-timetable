#ifndef BLOCKSOUTPUTTER_H
#define BLOCKSOUTPUTTER_H

#include "Outputter.hpp"

class BlocksOutputter : public Outputter
{
	public:
		BlocksOutputter(State &n_s);
		virtual ~BlocksOutputter();

		virtual void output(const std::string &filename);
};

#endif // BLOCKSOUTPUTTER_H
