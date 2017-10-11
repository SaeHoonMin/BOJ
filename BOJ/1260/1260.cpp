#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <string.h>
#include <deque>

using namespace::std;

bool visited[1001];
bool visited2[1001];
int graph[1001][1001]; //인접 행렬
int n, m, v;

void DFS(int vtx);
void BFS();

int main(void)
{
	/*
	1260 DFS와 BFS

	걍 dfs bfs 하면 됨
	*/


	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	DFS(v);
	cout << endl;
	BFS();
}

void DFS(int vtx)
{
	//걍 재귀호출 하자
	visited[vtx] = 1;
	printf("%d ", vtx);

	for (int i = 1; i <= 1000; i++)
	{
		if (!visited[i] && graph[vtx][i])
			DFS(i);
	}
}

void BFS()
{

	deque<int> tempV;

	tempV.push_back(v);

	while (tempV.size() != 0)
	{
		for (int i = 0; i < tempV.size(); i++)
		{
			if (!visited2[tempV[i]])
			{
				visited2[tempV[i]] = true;
				printf("%d ", tempV[i]);
			}
		}

		int size = tempV.size();
		for (int i = 0; i < size; i++)
		{
			int k = tempV.front();
			for (int j = 1; j <= 1000; j++)
			{
				if (!visited2[j] && graph[k][j])
					tempV.push_back(j);
			}
			tempV.pop_front();
		}
	}
}