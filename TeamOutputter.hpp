#ifndef TEAMOUTPUTTER_H
#define TEAMOUTPUTTER_H

#include "AbstractOutputter.hpp"

class TeamOutputter : public AbstractOutputter
{
	public:
		TeamOutputter(State &n_s);
		virtual ~TeamOutputter();

		virtual void output(const std::string &filename);
};

#endif // TEAMOUTPUTTER_H
