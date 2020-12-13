#ifndef PIPEEASTWEST_H
#define PIPEEASTWEST_H
#include "PipeElement.h"

struct PipeEastWest : public PipeElement {
	PipeEastWest(int x, int y) : PipeElement(x, y) {};
	~PipeEastWest();
	bool IsConnectionValid(const Conduit* conduit) const override;
};

#endif // !PIPEEASTWEST_H