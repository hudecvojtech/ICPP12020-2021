#ifndef PIPEELEMENT_H
#define PIPEELEMENT_H
#include "APipeElement.h"
#include "Conduit.h"

struct PipeElement : public APipeElement {
	PipeElement(int x, int y);
	virtual bool IsConnectionValid(const Conduit* conduit) const;
protected:
	bool isNorthConnectionValid(const Conduit* conduit) const;
	bool isSouthConnectionValid(const Conduit* conduit) const;
	bool isEastConnectionValid(const Conduit* conduit) const;
	bool isWestConnectionValid(const Conduit* conduit) const;
	bool isNorthBorderValid(const Conduit* conduit) const;
	bool isSouthBorderValid(const Conduit* conduit) const;
	bool isEastBorderValid(const Conduit* conduit) const;
	bool isWestBorderValid(const Conduit* conduit) const;
};

#endif // !PIPEELEMENT_H
#pragma once
