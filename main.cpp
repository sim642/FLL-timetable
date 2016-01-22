#include <iostream>
#include <fstream>
#include "csv/csv.hpp"
#include <algorithm>
#include <vector>
#include "Team.hpp"
#include "Block.hpp"
#include "Generator.hpp"
#include "TeamOutputter.hpp"
#include "Timer.hpp"

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
        cout << block.name << " " << block.columns << " " << block.rows.size() << " " << strftime("%Y-%m-%d %H:%M", block.start_time) << endl;

    bool r;
    Timer t;
    do
    {
        Generator g(teams, blocks);
        r = g.generate();
        if (r)
        {
            cout << "generate successful" << endl;
            TeamOutputter(teams, blocks).output("out_teams.csv");
        }
        else
            cout << "generate failed" << endl;
    }
    while (!r);
    auto dur = t.get();
    cout << "took " << std::chrono::duration<double, std::chrono::minutes::period>(dur).count() << " min" << endl;

    return 0;
}
