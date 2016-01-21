#include <iostream>
#include <fstream>
#include "csv/csv.hpp"
#include "csv/input_iterator.hpp"

using namespace std;

int main()
{
    ifstream fin("blocks.csv");

    for (csv::input_iterator it(fin); it != csv::input_iterator(); ++it)
    {
        for (auto &p : *it)
			cout << p.first << ": " << p.second << endl;
		cout << "------" << endl;
    }
    return 0;
}
