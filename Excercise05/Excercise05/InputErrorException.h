#ifndef INPUTERROREXCEPTION_H
#define INPUTERROREXCEPTION_H
#include <exception>

struct InputErrorException : public std::exception {
	const char* what() const throw();
};

#endif // !INPUTERROREXCEPTION_H

