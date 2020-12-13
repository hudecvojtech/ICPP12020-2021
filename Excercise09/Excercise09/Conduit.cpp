#include "Conduit.h"
#include "PipeElement.h"
#include "PipeEmpty.h"
#include "PipeEastWest.h"
#include "PipeNorthSouth.h"
#include "PipeNorthSouthEastWest.h"
#include "PipeSouthEastWest.h"
#include "PipeEnd.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

Conduit::Conduit(int size)
{
	_size = size;
	matrix = new PipeElement** [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new PipeElement*[size];
	}
}

Conduit::~Conduit()
{
}

void Conduit::AddElement(int x, int y, PipeElement* element)
{
	if (_size < x || _size < y || x < 0 || y < 0)
		throw std::out_of_range("Input is out of range");

	matrix[x][y] = element;
}

PipeElement* Conduit::GetElement(int x, int y) const
{
	if (_size < x || _size < y || x < 0 || y < 0)
		throw std::out_of_range("Input is out of range");

	return matrix[x][y];
}

bool Conduit::IsValid() const
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			PipeElement* element = matrix[i][j];
			if (!element->IsConnectionValid(this)) return false;
		}
	}

	return true;
}

int Conduit::GetSize() const
{
	return _size;
}

std::ifstream& operator>>(std::ifstream& input, Conduit& a)
{
	char c = 0;
	PipeElement* newElement = nullptr;
	int xNext = -1;
	std::string line;

	while (std::getline(input, line)) {
		++xNext;
		int yNext = 0;

		int i = 0;
		for (i = 0; i < line.length(); i++) {
			c = line.at(i);
			switch (c) {
			case '-':
				newElement = new PipeEastWest(xNext, yNext);
				break;
			case 'I':
				newElement = new PipeNorthSouth(xNext, yNext);
				break;
			case '+':
				newElement = new PipeNorhtSouthEastWest(xNext, yNext);
				break;
			case 'O':
				newElement = new PipeEnd(xNext, yNext);
				break;
			case 'T':
				newElement = new PipeSouthEastWest(xNext, yNext);
				break;
			case ' ':
				newElement = new PipeEmpty(xNext, yNext);
				break;
			}
			a.AddElement(xNext, yNext, newElement);
		}

		for (; i < a.GetSize(); i++) {
			newElement = new PipeEmpty(xNext, yNext);
			a.AddElement(xNext, yNext++, newElement);
		}
	}

	return input;
}
