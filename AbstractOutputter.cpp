#include "AbstractOutputter.hpp"

AbstractOutputter::AbstractOutputter(State &n_s) : s(n_s), teams(s.teams), blocks(s.blocks)
{

}

AbstractOutputter::~AbstractOutputter()
{

}
