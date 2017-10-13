#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
using namespace::std;


int arr[101];
int main(void)
{
	/*
	10810 : 공 넣기

	*/

	int m, n, a,b,c;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		for (int j = a; j <= b; j++)
		{
			arr[j] = c;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	
}