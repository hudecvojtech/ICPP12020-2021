#ifndef NOTEXISTEXCEPTION_H
#define NOTEXISTEXCEPTION_H

#include <exception>

struct NotExistException : public std::exception {
	const char* what() const throw();
};

#endif // NOTEXISTEXCEPTION_H

 
