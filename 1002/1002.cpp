#include <iostream>
#include <math.h>
#include <cstdio>
using namespace::std;
int main(void)
{

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x1, x2, y1, y2;
		int r1, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		long long dist = ((x2 - x1)*(x2-x1)) + ((y2 - y1)*(y2-y1));
		long long dist2 = (r1 + r2)*(r1+r2);
		long long dist3 = (r2 - r1)*(r2 - r1);
		//p1, p2 not same
		if (dist != 0)
		{
			if (dist < r1*r1 || dist < r2*r2)
			{
				if ( dist3 == dist)
					printf("%d\n", 1);
				else if ( dist3 < dist)
					printf("%d\n", 2);
				else
					printf("0\n");
			}
			else
			{
				if (dist == dist2 )
					printf("%d\n", 1);
				else if (dist < dist2 )
					printf("%d\n", 2);
				else
					printf("0\n");
			}
			
		}
		else // p1, p2 same
		{
			if (dist2 == 0)
				printf("1\n");
			else if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
		}

	}


}