#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdexcept>

template<typename T> class Matrix {
private:
	T** arr;
	int rows;
	int columns;

public:
	Matrix(int rows, int columns);
	Matrix(const Matrix<T>& m);
	~Matrix();
	void Set(int row, int column, T value);
	void SetOneDimension(T* arr);
	T& Get(int row, int column) const;
	template<typename R> Matrix<R> Cast() const;
	Matrix Transposition() const;
	Matrix Product(const Matrix& m) const;
	Matrix Product(T scalar) const;
	Matrix Sum(const Matrix& m) const;
	Matrix Sum(T scalar) const;
	bool IsSame(const Matrix& m) const;
	void Print() const;
};

template<typename T>
Matrix<T>::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->arr = new T * [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new T[columns];
		for (int j = 0; j < columns; j++) {
			arr[i][j] = 0;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m)
{
	rows = m.rows;
	columns = m.columns;
	arr = new T * [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new T[columns];
		for (int j = 0; j < columns; j++) {
			arr[i][j] = m.arr[i][j];
		}
	}
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}

template<typename T>
void Matrix<T>::Set(int row, int column, T value)
{
	if (row < 0 || row > rows) {
		throw std::out_of_range("Row is out of range.");
	}
	if (column < 0 || column > columns) {
		throw std::out_of_range("Column is out of range.");
	}

	arr[row][column] = value;
}

template<typename T>
void Matrix<T>::SetOneDimension(T* arr)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			this->arr[i][j] = arr[(i * columns) + j];
		}
	}
}

template<typename T>
T& Matrix<T>::Get(int row, int column) const
{
	if (row < 0 || row > rows) {
		throw std::out_of_range("Row is out of range.");
	}
	if (column < 0 || column > columns) {
		throw std::out_of_range("Column is out of range.");
	}

	return arr[row][column];
}


template<typename T>
Matrix<T> Matrix<T>::Transposition() const
{
	Matrix<T> newMatrix{ columns, rows };
	for (int i = 0; i < newMatrix.rows; i++) {
		for (int j = 0; j < newMatrix.columns; j++) {
			newMatrix.arr[i][j] = arr[j][i];
		}
	}
	return newMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::Product(const Matrix& m) const
{
	if (columns != m.rows) {
		throw std::invalid_argument("Operation is not suitable for this matrixes.");
	}

	Matrix<T> newMatrix{ rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < m.columns; j++) {
			T newValue = 0;
			for (int k = 0; k < m.rows; k++) {
				newValue += arr[i][k] * m.arr[k][j];
			}
			newMatrix.arr[i][j] = newValue;
		}
	}
	return newMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::Product(T scalar) const
{
	Matrix<T> newMatrix{ rows, columns };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.arr[i][j] = arr[i][j] * scalar;
		}
	}

	return newMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::Sum(const Matrix& m) const
{
	if (rows != m.rows || columns != m.columns) {
		throw std::invalid_argument("Operation is not suitable for this matrixes.");
	}

	Matrix<T> newMatrix{ rows, columns };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.arr[i][j] = m.arr[i][j] + arr[i][j];
		}
	}

	return newMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::Sum(T scalar) const
{
	Matrix<T> newMatrix{ rows, columns };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.arr[i][j] = arr[i][j] + scalar;
		}
	}

	return newMatrix;
}

template<typename T>
bool Matrix<T>::IsSame(const Matrix& m) const
{
	if (rows != m.rows || columns != m.columns) return false;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (arr[i][j] != m.arr[i][j])
				return false;
		}
	}

	return true;
}

template<typename T>
void Matrix<T>::Print() const
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
template<typename R>
Matrix<R> Matrix<T>::Cast() const
{
	Matrix<R> newMatrix{ rows, columns };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.Set(i, j, static_cast<R>(Get(i, j)));
		}
	}

	return newMatrix;
}

#endif // !MATRIX_H