#include <iostream>
using namespace::std;
#define DIV 9901;
int dp[100001] = { 1, 3 };

int main(void)
{
	int n;
	cin >> n;

	/*

	2*0개에 배치하는 법 = 1개 ( none)
	2*1	= 3
	2*2    = 3*2 + 1
	2*3    = none + 전체1칸인겨우 8
	= + 2마리 배치하는경우 6
	= + 3마리 배치하는 경우 2
	= 17
	= 3+ (7 *2)

	2*4    = 41  = 식?

	dp[i] = dp[i-1]*2 + dp[i-2]
	*/


	for (int i = 2; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % DIV;
	}
	cout << dp[n];

	return 0;

}