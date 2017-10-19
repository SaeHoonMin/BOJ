#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace::std;


typedef struct shelter{
	int height;
	vector<int> next;
	int best;
}shelter;


int n, m;
vector<shelter> shelters(5001);

int solve(int idx)
{
	if (shelters[idx].best != 0)
		return shelters[idx].best;


	int size = shelters[idx].next.size();
	int val = 1;

	for (int i = 0; i < size; i++)
	{
		val = max(val, solve(shelters[idx].next[i])+1);
	}
	shelters[idx].best = val;

	return val;
}

int main(void)
{
	/*
	14699 : 관악산 등산

		DP + DFS
	*/
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{	//높이 입력받기
		scanf("%d", &shelters[i].height);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		// a에서 b로가는데  a가 높이가 더 높다면 반대로 넣어주기
		if (shelters[a].height < shelters[b].height)
			shelters[a].next.push_back(b);
		else
			shelters[b].next.push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", solve(i) ) ;
	}

	return 0;
}