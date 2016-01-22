#ifndef BLOCKSOUTPUTTER_H
#define BLOCKSOUTPUTTER_H

#include "AbstractOutputter.hpp"

class BlocksOutputter : public AbstractOutputter
{
	public:
		BlocksOutputter(State &n_s);
		virtual ~BlocksOutputter();

		virtual void output(const std::string &filename);
};

#endif // BLOCKSOUTPUTTER_H
