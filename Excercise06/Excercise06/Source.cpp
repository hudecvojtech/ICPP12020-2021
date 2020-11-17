#include "GrowingContainer.h"
#include <string>
#include <iostream>

int main(char** argv, int argc) {
	GrowingContainer<std::string, 2, 2> growingContainer;
	growingContainer.Add("aa");
	growingContainer.Add("ab");
	growingContainer.Add("bc");
	growingContainer.Add("cd");
	growingContainer.Add("de");
	std::cout << growingContainer.count() << std::endl;
	std::cout << growingContainer[3] << std::endl;
	std::cout << &growingContainer[2] << std::endl;

	try {
		std::cout << growingContainer[12] << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}