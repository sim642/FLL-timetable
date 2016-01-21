#include "input_iterator.hpp"
#include <boost/tokenizer.hpp>

namespace csv
{

input_iterator::input_iterator() : is(nullptr)
{

}

input_iterator::input_iterator(std::istream &n_is) : is(&n_is)
{
	std::string line;
	std::getline(*is, line);

	boost::tokenizer<boost::escaped_list_separator<char>> tok(line);
	for (auto &col : tok)
		cols.push_back(col);

	increment(); // get first line
}

input_iterator::~input_iterator()
{

}

void input_iterator::increment()
{
	std::string line;
	if (!std::getline(*is, line))
	{
		is = nullptr;
		return;
	}

	boost::tokenizer<boost::escaped_list_separator<char>> tok(line);
	cur.clear();
	int i = 0;
	for (auto &cell : tok)
		cur.emplace(cols[i++], cell);
}

bool input_iterator::equal(const input_iterator& other) const
{
	return (is == nullptr && other.is == nullptr) || (is == other.is && cur == other.cur);
}

const row_t& input_iterator::dereference() const
{
	return cur;
}

}
