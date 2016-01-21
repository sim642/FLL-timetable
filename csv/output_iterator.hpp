#ifndef CSV_OUTPUT_ITERATOR_H
#define CSV_OUTPUT_ITERATOR_H

#include "common.hpp"
#include <boost/function_output_iterator.hpp>
#include <iterator>
#include <ostream>

namespace csv
{

class output_iterator;

class output_iterator_
{
	private:
		friend class output_iterator;
		friend class boost::function_output_iterator<output_iterator_>;

		output_iterator_();
		output_iterator_(std::ostream &n_os, const cols_t &n_cols);
		void operator()(const row_t &cur);

		static std::string escape(std::string str);

		std::ostream *os;
		cols_t cols;
};

class output_iterator : public boost::function_output_iterator<output_iterator_>
{
	public:
		output_iterator();
		explicit output_iterator(std::ostream &n_os, const cols_t &n_cols);
		virtual ~output_iterator();
};

}

#endif // CSV_OUTPUT_ITERATOR_H
