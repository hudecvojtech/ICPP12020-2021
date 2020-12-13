#include "PipeSouthEastWest.h"

PipeSouthEastWest::~PipeSouthEastWest()
{
}

bool PipeSouthEastWest::IsConnectionValid(const Conduit* conduit) const
{
	if (!isSouthBorderValid(conduit) || !isEastBorderValid(conduit) || 
		!isWestBorderValid(conduit)) return false;
	if (!isSouthConnectionValid(conduit) || !isEastConnectionValid(conduit) ||
		!isWestConnectionValid(conduit)) return false;
	return true;
}
