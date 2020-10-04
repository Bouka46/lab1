#include <iostream>
#include <random>
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;


int* processArray(int* val, int a1, int d, int& cnt, int length, int& lengthResultArray)
{

	//формирование массива 
	int temp = a1 + d;
	for (size_t i = 0; i < length; i++, temp += d)
	{
		val[i] = temp;
	}

	//Подсчет двухзначных элементов
	for (size_t i = 0; i < length; i++)
	{
		if (val[i] >= 10)
		{
			cnt++;
		}
		
	}


	int* temporaryArray = new int[length];
	temp = 0;
	int cntTempArray = 0;


	//формирование массива с элементами, сумма которых не равна 10
	for (size_t i = 0; i < length; i++)
	{
		temp = 0;
		string ss = to_string(val[i]);

		for (size_t j = 0; j < ss.size(); j++)
		{
			temp += (int)ss[j] - 48;
		}

		if (temp != 10) {
			temporaryArray[cntTempArray++] = val[i];
		}

	}


	lengthResultArray = cntTempArray;

	return temporaryArray;
}
void printArray(int* arr, int length) {

	for (size_t i = 0; i < length; i++)
	{
		printf("%d   ", arr[i]);
	}

}

int main() {

	setlocale(0, "");

	const int length = 15;
	int value[length] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int startValue = 4, difference = 3, cnt = 0, lengthResultArray = 0;


	int* resultArray = processArray(value, startValue, difference, cnt, length, lengthResultArray);
	
	printArray(resultArray, lengthResultArray);


	delete[] resultArray;
	resultArray = 0;

}












