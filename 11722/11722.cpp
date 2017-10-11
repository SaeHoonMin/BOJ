#include <iostream>
using namespace::std;


int dp[1001] = { 0,1, };
int arr[1001];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n;i++)
	{
		cin >> arr[i];
	}

	// arr  0 50  40 50
	// dp   0  1   2
	int ans = 1;
	for (int i = 2;  i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] > arr[i] && dp[max] < dp[j]+1)
				max = j;
		}
		dp[i] = dp[max] + 1;
		if (dp[i] > ans)
			ans = dp[i];
	}
	cout << ans;
}
