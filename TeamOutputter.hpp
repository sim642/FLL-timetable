#ifndef TEAMOUTPUTTER_H
#define TEAMOUTPUTTER_H

#include "Outputter.hpp"

class TeamOutputter : public Outputter
{
	public:
		TeamOutputter(State &n_s);
		virtual ~TeamOutputter();

		virtual void output(const std::string &filename);
};

#endif // TEAMOUTPUTTER_H
