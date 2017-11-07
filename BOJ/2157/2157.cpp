#include <math.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <memory.h>
#include <vector>

using namespace::std;

typedef struct city{
	vector<int> next;
	vector<int> food;
};

int dp[301][301]; // 방문개수 최대 300 * 10000(c최대) = 300,0000
vector<city> cities(301);

int main(void)
{
	/*
		2157 여행

		1 : 최동쪽, N : 최고서쪽, 
		서쪽으로만 여행 가능, 
		M-2개 이하만큼 여행하며, 
		항로가 연결 안되어있을 수 있음

		항로 개설여부와 기내식 점수 주어짐, 기내식점수 총합 최대로하는 여행의
		기내식점수 합은?

		입력 : a b (a에서 b 항로 있음, 서에서 동일수도 있음), c(기내식 점수)
		싸이클 X.

		무조건 1에서 N에서 끝나야 하며, M-2개를 여행해야 한다는 점을 고려하면..

	
		dp[방문개수][도시번호] = 현재도시까지 오면서 기내식 점수 최대값
		
	*/
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int e, w, f;
		scanf("%d %d %d", &e, &w, &f);
		if (e < w)
		{
			cities[e].next.push_back(w);
			cities[e].food.push_back(f);
		}
	}

	memset(dp, -1, sizeof(dp));

	dp[1][1] = 0;
	for (int i = 1; i <= n; i++) // 도시번호 : 1 to N
	{

		city &currentCity = cities[i];

		//방문 회수 :: 서쪽으로만 이동 가능하니까 최대 i번까지 이동가능하다. 
		// 1번 도시 이동하는데 1번, 2번도시 이동하는덴ㄴ 최대 2번..
		for (int j = 1; j<= i; j++)
		{
			if (dp[j][i] == -1)
				continue;
			
			
			int size = currentCity.next.size();
			for (int k = 0; k < size; k++) // 다음도시
			{
				int idx = currentCity.next[k];
				
				if (dp[j + 1][idx] == -1)
					dp[j + 1][idx] = dp[j][i] + currentCity.food[k];
				else
					dp[j + 1][idx] = max(dp[j + 1][idx], currentCity.food[k] + dp[j][i]);
			}
		}		
	}

	int ans = dp[1][1];
	for (int i = 2; i <= m; i++)
	{
		ans = max(dp[i][n], ans);
	}
	cout << ans;
	return 0;
}

