#ifndef PIPEEMPTY_H
#define PIPEEMPTY_H
#include "PipeElement.h"

struct PipeEmpty : public PipeElement {
	PipeEmpty(int x, int y) : PipeElement(x, y) { };
	~PipeEmpty();
	bool IsConnectionValid(const Conduit* conduit) const override;
};

#endif // !PIPEEMPTY_H
