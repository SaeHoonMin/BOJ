#include <iostream>

using namespace::std;

int dp[12];

//f(n) = f(n-1) + f(n-2) + f(n-3)
// 1 = 1 (1)
// 2 = 1 + 1, 2 (2)
// 3 = 1+2, 2+1, 1+1+1, 3  (4)
// 4 = 2+2, 2+1+1, 1+2+1, 1+1+2, 

int main(void)
{
	int test;
	cin >> test;

	int result;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 11; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	for (int i = 0; i < test;i++)
	{
		int n;
		cin >> n;

		cout << dp[n] << endl;;

	}


	return 0;
}