#include <string>
#ifndef IOBJECT_H
#define IOBJECT_H
#include "IComparable.h"

class IObject : public IComparable {
public:
	virtual std::string ToString() const = 0;
	virtual ~IObject() = 0;
};

#endif // !IOBJECT_H

