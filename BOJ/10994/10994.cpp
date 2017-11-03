#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <memory.h>

using namespace::std;

char arr[398][398];
void process(int start, int n)
{
	if (n == 0)
		return;

	int l = 1 + (n - 1) * 4;
	for (int i = start; i - start < l; i++)
	{
		arr[start][i] = '*';
		arr[i][start] = '*';
		arr[start+l - 1][i] = '*';
		arr[i][start+l - 1] = '*';
	}

	process(start + 2, n - 1);
}

int main(void)
{
	/*
		별 찍기 - 19
		중첩 사각형 모양..

		n*n사이즈임.
		1 5 9 13

		1 + (n-1)*4;
		최대 : 1+(100-1)*4 == 397
	*/

	int n;
	cin >> n;

	int size = 1 + (n - 1) * 4;

	memset(arr, ' ', sizeof(arr));

	process(0, n);
	for (int i = 0; i < size; i++)
	{
		arr[i][size] = '\0';
		printf("%s\n", arr[i]);
	}

	
	return 0;
}