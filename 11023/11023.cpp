#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>

#define INT_MAX 2147483647
#define DIVIDER 1000000000
using namespace::std;


int main(void)
{
	/**
	11023 :더하기 3

	*/

	int n;
	int ans = 0;
	while ( scanf("%d ",&n) == 1)
	{
		ans += n;
	}
	cout << ans;

	return 0;
}