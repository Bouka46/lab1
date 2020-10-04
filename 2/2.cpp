#include <iostream>
#include <random>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

using namespace std;

void initializeArray(double** arr,int rows, int column) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = pow(i + j + 1, 1.0 / 2.0);
		}
	}
}

double** makeArray2D(double** arr, int rows, int column) {

	for (size_t i = 0; i < rows; i++)
	{
		*(arr + i) = new double[column];
	}
	return arr;

}

double* makeArray(double** arr, int rows, int column) {

	double* array = new double[rows * column];
	int arraySize = 0, i = 0, j = column - 1, cnt = 0;;
		
	printf("\n");
	for (;j >= 0;j--) 
	{
		for (;i <= column - 1 ;)
		{
			array[arraySize++] = arr[i++][j];
		}
		i = 0;
		
	}
	return array;
}

void printArray2D(double** array, int rows, int column) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			printf("%.2f ", array[i][j]);

		}
		printf("\n");
	}
}

void printArray(double* array, int rows, int column) {
	int length = rows * column;
	for (size_t i = 0; i < length; i++)
	{
		printf("%.4f ", array[i]);
	}
	printf("\n\n");
}

void freeArray2D(double** arr, int N) {
	for (int i = 0; i < N; ++i)
		delete[] arr[i];
	delete[] arr;
}
void freeArray(double* arr) {
	delete[] arr;
}


int main() {
	
	const int rows = 4;
	const int column = 4;
	double** array2D = new double* [rows];

	makeArray2D(array2D, rows, column);

	initializeArray(array2D,rows, column);

	printArray2D(array2D, rows, column);


	double* array = makeArray(array2D, rows, column);
	printArray(array, rows, column);

	freeArray(array);
	freeArray2D(array2D, rows);


}





