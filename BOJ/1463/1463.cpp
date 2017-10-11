#include <iostream>
#include <stdlib.h>
#define INT_MAX       2147483647
using namespace::std;


int min(int a, int b)
{
	return a <= b ? a : b;
}

int main(void)
{
	int input;
	int *arr;

	arr = (int *)malloc(sizeof(int) * 1000001);

	cin >> input;

	arr[1] = 0;

	for (int i = 2; i <= input; i++)
	{
		int a = INT_MAX, b = INT_MAX, c = INT_MAX;
		if (i % 2 == 0)
		{
			a = arr[i / 2] + 1;
		}

		if (i % 3 == 0)
		{
			b = arr[i / 3] + 1;
		}
		c = arr[i - 1] + 1;

		arr[i] = min(min(a, b), c);

	}


	cout << arr[input];

	return 0;
}