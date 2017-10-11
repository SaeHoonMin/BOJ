#include<iostream>
#include<cstdio>
using namespace::std;
int main(void)
{
	int n;
	cin >> n;

	if (n == 1)
	{
		printf("*");return 0;
	}

	/*
	1 - 1
	2 - 3
	3 - 5
	
	   *
	  ***

	     *	 	 3
		* *     2, 4
	   *****
	*/
	int bottom = 1 + 2 * (n - 1);

	for (int i = 1; i <= n; i++)
	{
		if (i != n)
		{
			for (int j = 1; j <= bottom; j++)
			{
				if (j == (bottom - (bottom / 2) + (i - 1)) ||
					j == (bottom / 2) + 1 - (i - 1))
					printf("*");
				else if(j < (bottom - (bottom / 2) + (i - 1)))
					printf(" ");
			}
		}
		else
		{
			for (int j = 0; j <bottom; j++)
				printf("*");
		}
		printf("\n");
	}

	return 0;
}