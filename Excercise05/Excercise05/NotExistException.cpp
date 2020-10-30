#include "NotExistException.h"

const char* NotExistException::what() const throw()
{
	return "Item does not exist";
}
