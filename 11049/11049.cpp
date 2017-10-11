#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace::std;

long long int dp[500][500];

int main(void)
{
	int n;
	cin >> n;
	vector< std::pair<int,int> > arr(n);

	for (int i = 0;i < n; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	/*
		11049 : 햏렬 곱셈 순서

		행렬 A*B*C*D..
		A ~ C 까지 곱할때 최소계산회수 ?   min( AB * C , A * BC )

		A~ D?
		min (  AB * CD , A*BCD, ABC * D )

		A~ E?
		min ( ABCD E, A BCDE,  AB CDE, ABC DE, 


		dp[i][j] = i부터 j까지 곱할때 최소 값

	*/

	for (int j = 1 ; j < n; j++)
	{
		for (int i = 0; j+i < n; i++)
		{
			int end = j + i;
			dp[i][end] = 9876543210;

			for (int k = i; k < end; k++)
			{
				dp[i][end] = min(dp[i][end],
					dp[i][k] + dp[k + 1][end] + arr[i].first * arr[k].second * arr[end].second);
			}
			
		}
	}
	
	cout << dp[0][n - 1];

	return 0;
}