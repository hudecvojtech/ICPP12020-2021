#ifndef APIPEELEMENT_H
#define APIPEELEMENT_H

struct Conduit;

struct APipeElement {
	virtual ~APipeElement() { }
	virtual bool IsConnectionValid(const Conduit* conduit) const = 0;
	int _x;
	int _y;
};

#endif // !APIPEELEMENT_H

