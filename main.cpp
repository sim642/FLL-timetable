#include <iostream>
#include <fstream>
#include "csv/csv.hpp"
#include <algorithm>
#include <vector>
#include "Team.hpp"
#include "Block.hpp"

using namespace std;

int main()
{
    vector<Team> teams;
    {
        ifstream fin("teams.csv");
        copy(csv::input_iterator(fin), csv::input_iterator(), back_inserter(teams));
    }

    vector<Block> blocks;
    {
        ifstream fin("blocks.csv");
        copy(csv::input_iterator(fin), csv::input_iterator(), back_inserter(blocks));
    }

    for (auto &block : blocks)
        block.create_rows(teams.size());

    for (auto &block : blocks)
        cout << block.name << " " << block.columns << " " << block.rows.size() << endl;
    return 0;
}
