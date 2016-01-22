#include "AbstractGenerator.hpp"

AbstractGenerator::AbstractGenerator(State &n_s) : cancel(nullptr), s(n_s)
{

}

AbstractGenerator::~AbstractGenerator()
{

}

bool AbstractGenerator::should_cancel() const
{
	return cancel != nullptr && *cancel;
}
