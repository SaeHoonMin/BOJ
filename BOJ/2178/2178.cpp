#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <string>
#include <deque>
#include <algorithm>

#define MAX 10001	//by definition of problem
#define CORD std::pair<int,int>
using namespace::std;

int arr[101][101];
int dp[101][101];
bool visited[101][101];

int dirX[4] = { 0, 1, -1, 0 };
int dirY[4] = { 1, 0,  0, -1 };

deque< CORD > que;

int main(void)
{
	/*
	2178 : 미로 탐색

	*/
	string s;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j + 1] = s[j] - '0';

		/*	if(i==1)
				arr[i][j + 1] = 1;
			if (j + 1 == m)
				arr[i][j + 1] = 1;*/
		//	arr[i][j+1] = 1;

		}
	}

	que.push_back(CORD(1, 1));
	dp[1][1] = 1;

	while (!que.empty())
	{
		//방문 표시 먼저
		for (int i = 0; i < que.size(); i++)
		{
			int a = que[i].first;
			int b = que[i].second;

			if (!visited[a][b])
			{
				visited[a][b] = true;
			}
		}

		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			//하나씩 pop하면서 가능한 경로에 dp 업데이트
			int a = que.front().first;
			int b = que.front().second;
			que.pop_front();

			for (int j = 0; j < 4; j++)
			{
				int dx = a + dirX[j];
				int dy = b + dirY[j];

				if (arr[dx][dy] != 1 ||
					dx <= 0 || dx > n || dy <= 0 || dy>m)
					continue;

				if (!visited[dx][dy])
				{
					if (dp[dx][dy] == 0)
					{
						dp[dx][dy] = arr[dx][dy] + dp[a][b];
						que.push_back(CORD(dx, dy));
					}
					else
						dp[dx][dy] = min(dp[dx][dy], arr[dx][dy] + dp[a][b]);
					
				}
			}
		}
	}

	cout << dp[n][m];
}
