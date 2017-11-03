#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>

using namespace::std;

struct node {
	vector<int> next;
};

int visited[101];

int main(void)
{
	/*
		2606 : 바이러스

		걍 BFS
	*/
	int n, e;
	scanf("%d %d", &n, &e);
	vector<node> v(n+1);
	for (int i = 0;i < e; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].next.push_back(b);
		v[b].next.push_back(a);
	}

	queue<int> que;
	que.push(1);
	
	int cnt = 0;

	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			int cur = que.front();
			if(cur != 1)cnt++;
			for (int j = 0; j < v[cur].next.size(); j++)
			{
				if (!visited[v[cur].next[j]])
				{
					que.push(v[cur].next[j]);
					visited[v[cur].next[j]] = 1;
				}
			}
			que.pop();
		}
	}

	cout << cnt;

	
	
	return 0;
}