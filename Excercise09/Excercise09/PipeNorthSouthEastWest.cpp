#include "PipeNorthSouthEastWest.h"

PipeNorhtSouthEastWest::~PipeNorhtSouthEastWest()
{
}

bool PipeNorhtSouthEastWest::IsConnectionValid(const Conduit* conduit) const
{
	if (!isNorthBorderValid(conduit) || !isSouthBorderValid(conduit) ||
		!isEastBorderValid(conduit) || !isWestBorderValid(conduit)) return false;
	if (!isNorthConnectionValid(conduit) || !isSouthConnectionValid(conduit) ||
		!isEastConnectionValid(conduit) || !isWestConnectionValid(conduit)) return false;
	return true;
}
