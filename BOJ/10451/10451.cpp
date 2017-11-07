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
int arr[1001];
int visited[1001];
int main(void)
{
	/*
		10451 순열 사이클

		: 걍 세면 됨
	*/
	int T, n;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}
		memset(visited, 0, sizeof(visited));
		int cycle = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				cycle++;
				visited[i] = 1;
				int next = arr[i];
				while (!visited[next])
				{
					visited[next] = 1;
					next = arr[next];
				}
			}
		}
		printf("%d\n", cycle);
	}
	
	return 0;
}

