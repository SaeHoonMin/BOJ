#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

#define DIVIDER 15746

using namespace::std;
int dp[1000001] = { 1,1 };

int main(void)
{
	/*
		1904 : 타일


		1 또는 00 으로 만들수 있는 길이가 n인 2진수열 경우의 수?

		1 : 1													1
		2 : 00 11												2  
		3 : 100 001 111											3  
		4 : 0000 0011 1001 1100 1111							5  
		5 : 00100 10000 00001 11001 10011 11100 00111  11111    8  
		
		엥? 이거 피보나치아니냐?
		
	*/
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % DIVIDER;
	}
	cout << dp[n];
}