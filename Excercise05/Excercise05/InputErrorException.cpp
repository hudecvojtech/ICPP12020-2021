#include "InputErrorException.h"

const char* InputErrorException::what() const throw()
{
	return "Wrong input value";
}
