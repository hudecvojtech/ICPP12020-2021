#include "PipeEnd.h"

PipeEnd::~PipeEnd()
{
}

bool PipeEnd::IsConnectionValid(const Conduit* conduit) const
{
	// always true
	return true;
}
