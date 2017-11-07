#include <math.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <memory.h>

using namespace::std;


int main(void)
{
	/*
	2869 : 달팽이는 올라가고 싶다

	
	*/

	int a, b, v;
	cin >> a >> b >> v;

	int x = ceil(((double)v - a) / (a - b));

	if (x >= v)
		cout << x;
	else
		cout << x + 1;

	return 0;
}
