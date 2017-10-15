#include <iostream>
#include <algorithm>
using namespace::std;

int main(void)
{
	/*
	
		2579 : 계단 오르기

		dp[i] 에서의 경우의 수?
		i칸은 무조건 밟은 것이므로,

		이전 칸은 확실히 밟지 않았고 2번째 전 칸의 최소값 + 지금 값
		i-2까지의 최소값(dp[i-2]) + arr[i] 이거나

		이전 칸을 밟은 경우는 i-2칸은 밟았으면 안되므로, 
		dp[i-3]의 결과 + arr[i-1] + arr[i]
		arr[i] + arr[i-1] + arr[i-3]
	*/
	int n;

	cin >> n;

	int *arr = new int[n + 1];

	int * result = new int[n + 1];

	arr[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	result[1] = arr[1];
	result[2] = arr[1] + arr[2];
	result[3] = max(arr[3] + arr[2], arr[3] + result[1]);

	for (int i = 4; i <= n; i++)
	{
		result[i] = max(arr[i] + result[i - 2], arr[i] + arr[i - 1] + result[i - 3]);
	}

	cout << result[n];

	return 0;
}