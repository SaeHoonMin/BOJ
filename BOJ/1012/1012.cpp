#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <string.h>
using namespace::std;

int arr[51][51];
int visited[51][51];
const int vect[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
#define PAIR std::pair<int, int>

void clear()
{
	for (int i = 0;i < 50;i++)
	{
		memset(arr[i], 0, sizeof(arr[i]));
		memset(visited[i], 0, sizeof(visited[i]));
	}
}

int main(void)
{
	/*
	1012 : 유기농 배추

	걍 bfs 하면 됨.

	*/
	int t; 
	cin >> t;
	for (int T = 0; T < t; T++)
	{
		clear();
		int m, n, b, x, y;
		scanf("%d %d %d", &n, &m, &b);
		

		for (int j = 0; j < b; j++)
		{
			scanf("%d %d", &x, &y);
			arr[y][x] = 1;
		}

		int worm = 0;
		while (b)
		{
			// 우선  0이 아닌 배추를 찾는다
			worm++;
			int i = 0, j = 0;
			for (i = 0; i < m; i++)
			{
				for (j = 0;j < n; j++)
				{
					if (arr[i][j])
						break;
				}
				if (arr[i][j])
					break;
			}

			// 거기서부터 bfs시작.
			queue< PAIR > que;
			que.push(PAIR(i, j));
			while(!que.empty())
			{
				int size = que.size();
				for (int i = 0; i < size; i++)
				{
					PAIR p = que.front();
					visited[p.first][p.second] = 1;
					arr[p.first][p.second] = 0;

					for (int j = 0;j < 4; j++)
					{
						int a = p.first + vect[j][0];
						int b = p.second + vect[j][1];

						if (a >= 0 && a < m && b >= 0 && b < n)
						{
							if (arr[a][b] && !visited[a][b])
							{
								que.push(PAIR(a, b));
								visited[a][b] = 1;
							}
						}

					}
					que.pop();
					b--;
				}
			}
		}//while(leftb)
		cout << worm << "\n";
	}


}