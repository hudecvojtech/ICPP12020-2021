#include "PipeEmpty.h"

PipeEmpty::~PipeEmpty()
{
}

bool PipeEmpty::IsConnectionValid(const Conduit* conduit) const
{
	// always true
	return true;
}
