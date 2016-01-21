#ifndef CSV_INPUT_ITERATOR_H
#define CSV_INPUT_ITERATOR_H

#include "common.hpp"
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <istream>

namespace csv
{

class input_iterator : public boost::iterator_facade<input_iterator, const row_t, std::input_iterator_tag>
{
	public:
		input_iterator();
		explicit input_iterator(std::istream &n_is);
		virtual ~input_iterator();

	private:
		friend class boost::iterator_core_access;
		void increment();
		bool equal(const input_iterator &other) const;
		const row_t& dereference() const;

		std::istream *is;
		cols_t cols;
		row_t cur;
};

}

#endif // CSV_INPUT_ITERATOR_H
