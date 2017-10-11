#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>

using namespace::std;

int main(void)
{

	/*

	1551 : 수열의 변화

	*/

	int n, k;
	cin >> n >> k;
	int arr[20];
	for (int i = 0; i < n; i++)
	{
		scanf("%d,", &arr[i]);
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			arr[j] = arr[j+1] - arr[j];
		}
		n--;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i + 1 < n)
			printf(",");
	}
	
}