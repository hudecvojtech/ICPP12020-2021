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
