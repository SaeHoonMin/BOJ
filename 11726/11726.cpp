#include <iostream>

using namespace::std;

const int moder = 10007;

int main(void) {

	// 2 * n 
	int n;
	cin >> n;

	long long int dp[1002];

	dp[0] = 1; 
	dp[1] = 1;
	///  2*1 = 1개
	//dp[0] = 0;
	//dp[1] = 1;
	//dp[2] = 2;
	//dp[3] = dp[n - 2] + dp[n - 1];
	for (int i = 2; i <= n;i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % moder;
	}

	cout << dp[n];

}