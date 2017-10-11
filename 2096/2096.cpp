#include<iostream>
#include<cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INT_MAX       2147483647    

using namespace::std;

int arr[3];
int maxDp[2][3];
int minDp[2][3];
int n;

void swapDp()
{
	for (int i = 0;i < 3; i++)
	{
		maxDp[0][i] = maxDp[1][i];
		minDp[0][i] = minDp[1][i];
	}
}

int main()
{
	cin >> n;

	int maxans = -1;
	int minans = 9 * 100000 + 1;

	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[j]);

			if (i == 0)
			{
				maxDp[0][j] = arr[j];
				minDp[0][j] = arr[j];

				maxans = max(arr[j], maxans);
				minans = min(arr[j], minans);
			}
			else
			{
				// max, min계산
				minans = INT_MAX;

				switch (j)
				{
				case 0:
					maxDp[1][j] = max(maxDp[0][j], maxDp[0][j + 1]) + arr[j];
					minDp[1][j] = min(minDp[0][j], minDp[0][j + 1]) + arr[j];
					break;
				case 1:
					maxDp[1][j] = max( max(maxDp[0][j], maxDp[0][j - 1]), maxDp[0][j + 1]) + arr[j];
					minDp[1][j] = min( min(minDp[0][j], minDp[0][j - 1]), minDp[0][j + 1]) + arr[j];
					break;
				case 2:
					maxDp[1][j] = max( maxDp[0][j], maxDp[0][j - 1]) + arr[j];
					minDp[1][j] = min( minDp[0][j], minDp[0][j - 1]) + arr[j];
					break;
				}
				
				maxans = max(maxans, maxDp[1][j]);
	
			} // if-else
		} //for j
		if (i != 0)
			swapDp();
	} //for i

	if (n != 1)
	{
		for (int i = 0; i < 3; i++)
		{
			minans = min(minDp[0][i], minans);
		}
	}

	
	
	cout << maxans << " " << minans;

}


