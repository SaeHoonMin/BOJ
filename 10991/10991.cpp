#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
using namespace::std;


int main(void)
{
	/**
	10991 별찍기 16

	*/

	int n;
	cin >> n;
	int l = n * 2 - 1;
	for (int i = 1; i <= n; i++)
	{
		int s = i * 2 - 1;
		int b = (l - s) / 2;
		for (int j = 0; j < b; j++)
			printf(" ");
		for (int j = 1; j <= s; j++)
		{
			if( j%2 ==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
}