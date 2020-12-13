#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include "Conduit.h"
#include "PipeElement.h"
#include "PipeEastWest.h"
#include "PipeNorthSouth.h"
#include "PipeNorthSouthEastWest.h"
#include "PipeSouthEastWest.h"
#include "PipeEnd.h"
#include "PipeEmpty.h"

int main() {
	std::string line;
	int size;
	Conduit* conduit = nullptr;
	std::string file = "input.txt";
	std::ifstream in(file);
	if (in.is_open()) {
		std::getline(in, line);
		size = stoi(line);
		conduit = new Conduit(size);
		for (int i = 0; i < size; i++) {
			std::getline(in, line);
			for (int j = 0; j < size; j++) {
				char c = line.at(j);
				PipeElement* newElement = nullptr;
				switch (c) {
				case '-':
					newElement = new PipeEastWest(i, j);
					break;
				case 'I':
					newElement = new PipeNorthSouth(i, j);
					break;
				case '+':
					newElement = new PipeNorhtSouthEastWest(i, j);
					break;
				case 'O':
					newElement = new PipeEnd(i, j);
					break;
				case 'T':
					newElement = new PipeSouthEastWest(i, j);
					break;
				case ' ':
					newElement = new PipeEmpty(i, j);
					break;
				}
				conduit->AddElement(i, j, newElement);
			}

		}
		std::cout << conduit->IsValid() << std::endl;
		in.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}

}