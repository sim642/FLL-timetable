#include "output_iterator.hpp"

namespace csv
{

output_iterator_::output_iterator_() : os(nullptr)
{

}

output_iterator_::output_iterator_(std::ostream& n_os, const cols_t& n_cols) : os(&n_os), cols(n_cols)
{
	for (auto it = cols.begin(); it != cols.end(); ++it)
	{
		if (it != cols.begin())
			*os << ',';
		*os << *it;
	}
	*os << std::endl;
}

void output_iterator_::operator()(const row_t& cur)
{
	for (auto it = cols.begin(); it != cols.end(); ++it)
	{
		if (it != cols.begin())
			*os << ',';
		// TODO: support quotes, escapes
		*os << cur.find(*it)->second;
	}
	*os << std::endl;
}

output_iterator::output_iterator()
{

}

output_iterator::output_iterator(std::ostream &n_os, const cols_t &n_cols) : boost::function_output_iterator<output_iterator_>(output_iterator_(n_os, n_cols))
{

}

output_iterator::~output_iterator()
{

}

}
