#include <iostream>
#include <fstream>
#include "csv/csv.hpp"
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("blocks.csv");
    ofstream fout("test.csv");

    /*for (csv::input_iterator it(fin); it != csv::input_iterator(); ++it)
    {
        for (auto &p : *it)
			cout << p.first << ": " << p.second << endl;
		cout << "------" << endl;
    }*/

    copy(csv::input_iterator(fin), csv::input_iterator(), csv::output_iterator(fout, {"name", "start_time"}));
    return 0;
}
