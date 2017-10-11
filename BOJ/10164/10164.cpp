#include <iostream>


using namespace::std;

int n, m, k;

int arr[16][16];
int dp[16][16];

int i = 1, j = 1;

void calc1()
{
	if (k != 0)
	{
		for (;;i++)
		{
			for (j = 1;j<=m;j++)
			{
				if (i == 1 && j == 1)
					dp[i][j] = 1;
				else
				{
					if (j - 1 >= 1)
						dp[i][j] += dp[i][j - 1];
					if (i - 1 >= 1)
						dp[i][j] += dp[i - 1][j];
				}

				if (arr[i][j] == k)
					return;
			}
		}
	}
}

void calc2()
{
	int a = i, b = j;

	for (;i <= n;i++)
	{
		for (j=b;j <= m;j++)
		{
			if (i == 1 && j == 1) dp[i][j] = 1;
			if (i == a && j == b)continue;
			else
			{
				if (j - 1 >= b)
					dp[i][j] += dp[i][j - 1];
				if (i - 1 >= a)
					dp[i][j] += dp[i-1][j];
			}
		}
	}
}

int main(void)
{


	cin >> n >> m >> k;
	
	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			arr[i][j] = cnt++;
	}

	
	calc1();
	calc2();

	cout << dp[n][m];

}