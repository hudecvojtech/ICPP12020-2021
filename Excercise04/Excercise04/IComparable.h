#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
#include "IObject.h"

class IComparable : public IObject {
public:
	virtual int CompareTo(IComparable* obj) const = 0;
	virtual ~IComparable() {};
};

#endif // !ICOMPARABLE_H

