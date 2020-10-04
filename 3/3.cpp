#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;


char* Strncat(char* dest, const char* src, size_t maxlen);

int main() {
	setlocale(0, "");

	char arr[100] = "12345";
	const char* ara = "1234567";
	size_t length = 5;

	char* res = Strncat(arr, ara, length);
	char* res2 = strncat(arr, ara, length);

	cout << res << endl;
	cout << res2 << endl;

	return 0;
}

char* Strncat(char* dest, const char* src, size_t maxlen) {

	int length = (sizeof(dest) / sizeof(dest[0]));
	char* dest2 = new char[(length + maxlen)];
	dest2 = dest;

	for (size_t i = length, j = 0; i < (length+maxlen);)
	{
		dest2[++i] = src[j++];
	}


	return dest2;
}