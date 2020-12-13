#include "PipeEastWest.h"

PipeEastWest::~PipeEastWest()
{
}


bool PipeEastWest::IsConnectionValid(const Conduit* conduit) const
{
	if (!isEastBorderValid(conduit) || !isWestBorderValid(conduit)) return false;
	if (!isEastConnectionValid(conduit) || !isWestConnectionValid(conduit)) return false;
	return true;
}

