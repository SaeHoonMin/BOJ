#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace::std;

int main(void)
{
	/*
	10996 별찍기 21
	.
	*/

	int n;
	cin >> n;
	for (int i = 1;i <= n*2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ( (i % 2 == 0 && j % 2 == 0) ||
				(i % 2 == 1 && j % 2 == 1))
				printf("*");
			else if( n!=1)
				printf(" ");
		}
		if(n!=1)
		printf("\n");
	}

	return 0;
}