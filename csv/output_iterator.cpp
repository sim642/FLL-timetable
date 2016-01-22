#include "output_iterator.hpp"

namespace csv
{

output_iterator_::output_iterator_() : os(nullptr)
{

}

output_iterator_::output_iterator_(std::ostream& n_os, const cols_t& n_cols, const std::string &n_def) : os(&n_os), cols(n_cols), def(n_def)
{
	for (auto it = cols.begin(); it != cols.end(); ++it)
	{
		if (it != cols.begin())
			*os << ',';
		*os << escape(*it);
	}
	*os << std::endl;
}

void output_iterator_::operator()(const row_t& cur)
{
	for (auto it = cols.begin(); it != cols.end(); ++it)
	{
		if (it != cols.begin())
			*os << ',';
		auto it2 = cur.find(*it);
		*os << escape(it2 != cur.end() ? it2->second : def);
	}
	*os << std::endl;
}

std::string output_iterator_::escape(std::string str)
{
	for (size_t i = 0; (i = str.find_first_of("\"\n\\", i)) != std::string::npos; i += 2)
	{
		switch (str[i])
		{
			case '"':
				str.replace(i, 1, "\\\"");
				break;
			case '\n':
				str.replace(i, 1, "\\n");
				break;
			case '\\':
				str.replace(i, 1, "\\\\");
				break;
		}
	}

	if (str.find(',') == std::string::npos)
		return str;
	else
		return '"' + str + '"';
}

output_iterator::output_iterator()
{

}

output_iterator::output_iterator(std::ostream &n_os, const cols_t &n_cols, const std::string &n_def) : boost::function_output_iterator<output_iterator_>(output_iterator_(n_os, n_cols, n_def))
{

}

output_iterator::~output_iterator()
{

}

}
