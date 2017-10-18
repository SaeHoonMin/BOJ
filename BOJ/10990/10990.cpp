#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace::std;


int main(void)
{
	/*

	2448: 별찍기 -15

	*/
	int n, l, m; 
	cin >> n;
	l = 1 + (2 * (n - 1));
	m = l / 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m+i; j++)
		{
			if (j == m + i  ||
				j== m-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}