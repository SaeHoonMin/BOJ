#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <memory.h>
using namespace::std;

#define PAIR std::pair<int, int>
#define CLEAR memset(visited,0,sizeof(visited))

queue< PAIR > iceBergs;

int arr[300][300];
bool visited[300][300];

int y[4] = { 0, 0, -1, 1 };
int x[4] = { 1, -1, 0, 0 };

int main(void) {

	/*
	2573 : 빙산

	: BFS로 돌면서 한번에 다 안돌아지는 순간 정답.

	*/
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			//arr[i][j] = 10;
			scanf("%d", &arr[i][j]);

			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
				arr[i][j] = 0;
			else if (arr[i][j])
				iceBergs.push(PAIR(i, j));
		}
	}


	int days = 0;
	queue< PAIR > que;

	while (!iceBergs.empty())
	{
		que.push(iceBergs.front());
		int count = iceBergs.size();

		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				//하나를 방문
				PAIR p = que.front();
				count--;

		
				int cnt = 0;
				for (int j = 0; j < 4; j++)
				{
					int dy = p.first + y[j];
					int dx = p.second + x[j];
					
					if (dx >= 0 && dx < m && dy >= 0 && dy < n
						&& !visited[dy][dx] &&
						!arr[dy][dx])
						cnt++;
				}
				arr[p.first][p.second] -= cnt;
				if (arr[p.first][p.second] < 0) arr[p.first][p.second] = 0;

				visited[p.first][p.second] = 1;

				for (int j = 0; j < 4; j++)
				{
					int dy = p.first + y[j];
					int dx = p.second + x[j];

					if (dx >= 0 && dx < m && dy >= 0 && dy < n
						&& !visited[dy][dx] &&
						arr[dy][dx])
					{
						que.push(PAIR(dy, dx));
						visited[dy][dx] = 1;
					}
				}
				que.pop();
			}
		}

		if (count)
			break;


		days++;
		CLEAR;
		int size = iceBergs.size();
		for (int i = 0; i < size; i++)
		{
			PAIR p = iceBergs.front();
			iceBergs.pop();
			if (arr[p.first][p.second]>0)
			{
				iceBergs.push(p);
			}
		}
	}

	if (iceBergs.empty())
		cout << "0";
	else
		cout << days;
}