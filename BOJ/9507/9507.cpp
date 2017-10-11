#include <iostream>

using namespace::std;

long long int dp[70];

int main(void)
{
	int testCase;
	cin >> testCase;
	
	for (int i = 0; i <= 67; i++)
	{
		if (i < 2)
			dp[i] = 1;
		else if (i == 2)
			dp[i] = 2;
		else if (i == 3)
			dp[i] = 4;
		else
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	
	for (int i = 0; i < testCase; i++)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
}