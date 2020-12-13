#ifndef PIPEEND_H
#define PIPEEND_H
#include "PipeElement.h"

struct PipeEnd : public PipeElement {
	PipeEnd(int x, int y) : PipeElement(x, y) {};
	~PipeEnd();
	bool IsConnectionValid(const Conduit* conduit) const override;
};

#endif // !PIPEEND_H
