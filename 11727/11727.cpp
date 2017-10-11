#include <iostream>

using namespace::std;

const int moder = 10007;

int dp[1001];

int main(void)
{
	//2*n 직사각형을 
	//2*1과 2*2 타일로 채우는 방법의 수
	// dp[0] = 0
	// dp[1] = 1
	// dp[2] = 3 
	// dp[3] = 5  ( 2*1 )쓰는경우 4개 + 2*2쓰는경우 2개
	// dp[4] = 

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;

	int k; 
	cin >> k;
	for (int i = 3; i <= k; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % moder;
	}
	cout << dp[k];
}