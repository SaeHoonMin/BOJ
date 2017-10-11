#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace::std;


int main(void)
{

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += (i*(i + 1) + (i*(i + 1)) / 2);
	}
	cout << sum;
}