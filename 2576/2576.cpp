#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
using namespace::std;

int main(void)
{
	/**
	2576 : 홀수
	*/
	int n,sum = 0;
	int minOdd = 101;
	for (int i = 0;i < 7; i++)
	{
		cin >> n;
		if (n % 2 == 1)
		{
			minOdd = min(minOdd, n);
			sum += n;
		}
	}
	if (sum == 0) cout << "-1";
	else
	cout << sum << endl << minOdd;
	
	return 0;
}