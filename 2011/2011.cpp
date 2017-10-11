#include <iostream>
#include <cstdio>
#include <string>
#define TOCHAR(x) (x-'0')
using namespace::std;
int dp[5001];

int main()
{
	string str;
	cin >> str;

	dp[0] = 1;
	dp[1] = 1;

	if (str.length() == 1 && TOCHAR(str[0]) == 0)
		dp[1] = 0;

	for (int i = 2; i <= str.length(); i++)
	{
		// 현재 문자위치'만 선택되는 경우'
		// "현재 문자위치와 이전 문자위치가 동시에 선택되는 경우
		// dp[i]  = dp[i-1] + if( 10 < arr[i-1]*10 +arr[i] < 26) dp[i-2];

		if (TOCHAR(str[i - 1]) > 0)
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;

		int num = TOCHAR(str[i - 2]) * 10 + TOCHAR(str[i - 1]);

		if ( num <= 26 && num >=10 )
		{
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
		
	}

	cout << dp[str.length()];
}