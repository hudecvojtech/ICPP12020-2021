#ifndef PIPENORTHSOUTH_H
#define PIPENORTHSOUTH_H
#include "PipeElement.h"

struct PipeNorthSouth : public PipeElement {
	PipeNorthSouth(int x, int y) : PipeElement(x, y) {};
	~PipeNorthSouth();
	bool IsConnectionValid(const Conduit* conduit) const override;
};

#endif // !PIPENORTHSOUTH_H
