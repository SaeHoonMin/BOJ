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

bool visited[100001];

int main(void)
{
	/**
		1697 : 숨바꼭질
		
		1차원 bfs로 되..겠지?
		분기 3개
	*/

	int n, k;
	cin >> n >> k;

	queue<int> que;
	que.push(n);
	visited[n] = 1;
	
	int sec = 0;


	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			int a = que.front();

			if (a == k)
			{
				cout << sec;
				return 0;
			}


			int jump = a * 2;

	
			if (jump <= 100000 && !visited[jump])
			{
				visited[jump] = 1;
				que.push(jump);
			}
			if (a + 1 <= 100000 && !visited[a + 1])
			{
				visited[a + 1] = 1;
				que.push(a + 1);
			}
			if (a - 1 >= 0 && !visited[a - 1])
			{
				visited[a - 1] = 1;
				que.push(a - 1);
			}

			que.pop();
		}

		sec++;
	}



	return 0;
}

