//#include <iostream>
//
//using namespace::std;
//
//int dp[10001];
//int coins[101];
//
//int main(void)
//{
//	int n, k;
//	cin >> n >> k;
//
//	for (int i = 0; i < n; i++)
//	{
//		/*int c; 
//		cin >> c;
//		coins.push_back(c);*/
//		cin >> coins[i];
//	}
//	//sort(coins.begin(), coins.end());
//
//	dp[0] = 1;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = coins[i]; j <= k; j++)
//		{
//			dp[j] += dp[j - coins[i]];
//		}
//	}
//
//	cout << dp[k];
//}
#include <stdio.h>


int dp[10001];
int coins[101];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		/*int c;
		cin >> c;
		coins.push_back(c);*/
		scanf("%d", &coins[i]);
	}
	//sort(coins.begin(), coins.end());

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] += dp[j - coins[i]];
		}
	}

	printf("%d", dp[k]);
}