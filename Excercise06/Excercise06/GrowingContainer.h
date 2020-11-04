#ifndef GROWINGCONTAINER_H
#define GROWINGCONTAINER_H
#include <exception>

template<typename DataType, int initSize = 5, int growCoeficient = 2>
class GrowingContainer {
	DataType* _array;
	unsigned _arraySize;
	unsigned _countOfElements;
	bool isSpaceInArray() const;
	void GrowArray();
public:
	GrowingContainer();
	~GrowingContainer();	
	void Add(const DataType& o);
	DataType& operator[](int index);
	DataType operator[](int index) const;
	unsigned int count() const;
};


#endif // !GROWINGCONTAINER_H

template<typename DataType, int initSize, int growCoeficient>
GrowingContainer<DataType, initSize, growCoeficient>::GrowingContainer()
{
	_arraySize = initSize;
	_array = new DataType[_arraySize]; // Jak uvolnit pamÏù? po provedenÌ memcpy() a n·slednÈm delete[] spadne
	_countOfElements = 0;
}

template<typename DataType, int initSize, int growCoeficient>
GrowingContainer<DataType, initSize, growCoeficient>::~GrowingContainer()
{
	//delete[] _array;
}

template<typename DataType, int initSize, int growCoeficient>
bool GrowingContainer<DataType, initSize, growCoeficient>::isSpaceInArray() const
{
	return _countOfElements < _arraySize;
}

template<typename DataType, int initSize, int growCoeficient>
void GrowingContainer<DataType, initSize, growCoeficient>::GrowArray()
{
	if (isSpaceInArray()) return;

	DataType* newArray = new DataType[_arraySize * growCoeficient];
	memcpy(newArray, _array, _arraySize * sizeof(DataType));
	_arraySize *= growCoeficient;
	//delete[] _array; 
	_array = newArray;
}

template<typename DataType, int initSize, int growCoeficient>
void GrowingContainer<DataType, initSize, growCoeficient>::Add(const DataType& o)
{
	if (_countOfElements == _arraySize)
		GrowArray();

	_array[_countOfElements++] = o;
}

template<typename DataType, int initSize, int growCoeficient>
DataType& GrowingContainer<DataType, initSize, growCoeficient>::operator[](int index)
{
	if (index >= _countOfElements)
		throw std::exception();
	return _array[index];
}

template<typename DataType, int initSize, int growCoeficient>
DataType GrowingContainer<DataType, initSize, growCoeficient>::operator[](int index) const
{
	if (index >= _countOfElements)
		throw std::exception();
	return _array[index];
}

template<typename DataType, int initSize, int growCoeficient>
unsigned int GrowingContainer<DataType, initSize, growCoeficient>::count() const
{
	return _countOfElements;
}
