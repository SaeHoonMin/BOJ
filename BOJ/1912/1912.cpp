#include<iostream>
#define MAX(a,b) (a>b?a:b)
using namespace::std;

int * dp;
int *arr;
int main(void)
{
	int n;
	cin >> n;
	arr = new int[n + 1];
	dp = new int[n + 1];
	for (int i = 1; i <= n;i++)
	{
		cin >> arr[i];
	}

	dp[0] = -9999;

	for (int i = 1; i <= n; i++)
	{
		if (dp[i - 1] + arr[i] > arr[i])
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
	}

	int max = dp[1];
	for (int i = 2; i <= n; i++)
	{
		if (max < dp[i])
			max = dp[i];
	}
	cout << max;
}