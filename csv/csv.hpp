#ifndef CSV_H
#define CSV_H

#include <string>
#include <vector>
#include <map>

namespace csv
{

typedef std::string col_t;
typedef std::vector<col_t> cols_t;
typedef std::map<col_t, std::string> row_t;

}

#endif // CSV_H
