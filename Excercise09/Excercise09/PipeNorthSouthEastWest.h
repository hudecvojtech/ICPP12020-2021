#ifndef PIPENORTHSOUTHEASTWEST_H
#define PIPENORTHSOUTHEASTWEST_H
#include "PipeElement.h"

struct PipeNorhtSouthEastWest : public PipeElement {
	PipeNorhtSouthEastWest(int x, int y) : PipeElement(x, y) {};
	~PipeNorhtSouthEastWest();
	bool IsConnectionValid(const Conduit* conduit) const override;
};

#endif // !PIPENORTHSOUTHEASTWEST_H
