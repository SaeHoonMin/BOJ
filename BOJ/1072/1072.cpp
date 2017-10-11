#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

#define XMAX 2000000000

using namespace::std;

int n;

long long calc(long long y, long long x, long long  k)
{
	return (long long)floor( (y + k) * 100 / (x + k) );
}


int main(void)
{
	/*
		1072 게임

		x : 게임회수, y : 이긴회수
		승률 = 내림( y/x * 100 )  = A

		question is, 
		 
		floor( (y+k)/(x+k)*100 ) !=A 인 최초의 k ?
		
	*/

	long long x, y;

	while (scanf("%lld %lld", &x, &y) != EOF)
	{
		long long A = calc(y, x, 0);

		if ((long long)A >= 99)
		{
			printf("-1");
			continue;
		}
		
		int left = 1;
		int right = XMAX;
		
		while ( left <= right )
		{
			long long mid = (left + right) / 2;
			long long result = calc(y, x, mid);

			if (result != A)
			{
				if (calc(y, x, mid - 1) == A)
				{
					printf("%d\n", mid);
					break;
				}
				right = mid-1;
			}
			else
			{
				//upper area
				left = mid + 1;
			}
		}

		if (left > right)
			printf("-1\n");
	}
}