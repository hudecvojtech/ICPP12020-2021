#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>

class IObject {
public:
	virtual std::string ToString() const = 0;
	virtual ~IObject() {};
};

#endif // !IOBJECT_H

