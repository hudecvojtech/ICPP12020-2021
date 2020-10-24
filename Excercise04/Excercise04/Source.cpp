#include <cstdlib>
#include <time.h>
#include <iostream>
#include "IComparable.h"
#include "Time.h"

#define ARRAY_SIZE 10

void SortArray(IComparable** array, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i]->CompareTo(array[j]) == 1) {
				IComparable* temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main(char** argc, int argv) {
	srand(time(NULL));
	IComparable** arr = new IComparable*[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = new Time(rand() % 23, rand() % 59, rand() % 59);
	}

	SortArray(arr, ARRAY_SIZE);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << arr[i]->ToString() << std::endl;
	}
}