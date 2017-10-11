#include <iostream>
#include <algorithm>
using namespace::std;
int n;
int arr[1001];
int dp[1001];\
int process()
{
	dp[1] = arr[1];
	int max = dp[1];

	for (int i = 2; i <= n; i++)
	{
        dp[i] = arr[i];
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		if (max < dp[i])
			max = dp[i];
	}

	return max;
}

int main(void)
{
	 cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cout << process();
}