#include "BlocksOutputter.hpp"
#include "BlockOutputter.hpp"
#include <boost/format.hpp>

BlocksOutputter::BlocksOutputter(State &n_s) : Outputter(n_s)
{

}

BlocksOutputter::~BlocksOutputter()
{

}

void BlocksOutputter::output(const std::string& filename)
{
	for (std::size_t i = 0; i < blocks.size(); i++)
		BlockOutputter(s, i).output((boost::format(filename) % i).str());
}
