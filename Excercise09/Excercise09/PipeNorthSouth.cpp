#include "PipeNorthSouth.h"

PipeNorthSouth::~PipeNorthSouth()
{
}

bool PipeNorthSouth::IsConnectionValid(const Conduit* conduit) const
{
	if (!isNorthBorderValid(conduit) || !isSouthBorderValid(conduit)) return false;
	if (!isNorthConnectionValid(conduit) || !isSouthConnectionValid(conduit)) return false;
	return true;
}
