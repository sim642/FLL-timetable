#include <iostream>
#include <fstream>
#include "csv/csv.hpp"
#include <algorithm>
#include "Generator.hpp"
#include "TeamOutputter.hpp"
#include "Timer.hpp"
#include "State.hpp"
#include "MultiGenerator.hpp"

using namespace std;

int main()
{
    State s;
    {
        ifstream fin("teams.csv");
        copy(csv::input_iterator(fin), csv::input_iterator(), back_inserter(s.teams));
    }

    {
        ifstream fin("blocks.csv");
        copy(csv::input_iterator(fin), csv::input_iterator(), back_inserter(s.blocks));
    }

    for (auto &block : s.blocks)
        block.create_rows(s.teams.size());

    for (auto &block : s.blocks)
        cout << block.name << " " << block.columns << " " << block.rows.size() << " " << strftime("%Y-%m-%d %H:%M", block.start_time) << endl;


    bool r;
    int i = 0;
    Timer t;

    MultiGenerator g(s, [&](std::thread::id id, bool r)
    {
        cout << "attempt " << ++i << " (" << id << "): " << r << endl;
    });

    r = g.generate();
    if (r)
    {
        cout << "generate successful" << endl;
        TeamOutputter(s).output("out_teams.csv");
    }
    else
        cout << "generate failed" << endl;

    auto dur = t.get();
    cout << "took " << std::chrono::duration<double, std::chrono::minutes::period>(dur).count() << " min" << endl;

    return 0;
}
