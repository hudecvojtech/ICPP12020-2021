#ifndef PIPESOUTHEASTWEST_H
#define PIPESOUTHEASTWEST_H
#include "PipeElement.h"

struct PipeSouthEastWest : public PipeElement {
	PipeSouthEastWest(int x, int y) : PipeElement(x, y) {};
	~PipeSouthEastWest();
	bool IsConnectionValid(const Conduit* conduit) const override;
};

#endif // !PIPESOUTHEASTWEST_H
