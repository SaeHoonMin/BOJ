#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace::std;

int main(void)
{
	/*

	10955: 별찍기 - 20

	*/
	int n;
	cin >> n;
	for (int i = 0;i < n; i++)
	{
		if (i % 2 == 1)
			printf(" ");
		for (int j = 0; j < n; j++)
		{
			printf("*");
			if (j < n - 1)
				printf(" ");
			else
				printf("\n");
		}
		
	}
	
	return 0;
}