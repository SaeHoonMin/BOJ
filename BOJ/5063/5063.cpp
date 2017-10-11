#include <iostream>
#include <string>
#include <vector>
#include <cstdio>


using namespace::std;

#define INT_MIN     (-2147483647 - 1)



int main(void)
{

	int t;
	int a, b, c;
	cin >> t;
	for (int i = 0;i < t; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		if (a > (b - c))
		{
			printf("do not advertise\n");
		}
		else if (a == (b - c))
			printf("does not matter\n");
		else
			printf("advertise\n");
	}

	return 0;
}