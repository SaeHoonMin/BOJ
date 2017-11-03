#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <memory.h>

using namespace::std;

int fields[1000001];

int main(void)
{
	/*
		5014 : 스타트링크

		F : 총 층
		S : 현재 층
		G : 목적지
		U : 위로가는 버튼
		D : 아래로 가는 버튼
	*/

	int f, s, g, u, d, temp, upper, below;
	cin >> f >> s >> g >> u >> d;

	int cnt = 0;
	queue<int> que;
	que.push(s);
	if (s == g)
	{
		cout << "0";
		return 0;
	}


	while (!que.empty())
	{
		bool found = false;
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			temp = que.front();
			upper = temp + u;
			below = temp - d;

			fields[temp]= 1;

			if (upper == g || below == g)
			{
				found = true; 
				break;
			}
			if (upper <= f && !fields[upper])
			{
				que.push(upper);
				fields[upper] = 1;
			}
			if (below >= 1 && !fields[below])
			{
				que.push(below);
				fields[below] = 1;
			}

			que.pop();
		}

		cnt++;

		if (found)
		{
			cout << cnt;
			return 1;
		}
	}

	cout << "use the stairs";
	
	return 0;
}