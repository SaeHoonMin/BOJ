#include <math.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <memory.h>

using namespace::std;

typedef struct nation {
	int num;
	int gold;
	int silver;
	int cooper;
}nation;


int main(void)
{
	/*
	8979 : 올림픽

	 목표 국가보다 잘한 국가만 세면됨
	*/

	int n, t, rank = 0, accm = 0;
	cin >> n >>t;
	vector<nation> nations(n);
	nation target;
	for (int i = 0;i < n; i++)
	{
		cin >> nations[i].num >>
			nations[i].gold >> 
			nations[i].silver >>
			nations[i].cooper;

		if (t == nations[i].num)
			target = nations[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (nations[i].num == t)
			continue;

		if (nations[i].gold > target.gold)
			rank++;
		else if (nations[i].gold == target.gold)
		{
			if (nations[i].silver > target.silver)
				rank++;
			else if (nations[i].silver == target.silver &&
				nations[i].cooper > target.cooper)
				rank++;
		}
	}
	cout << rank+1;
	return 0;
}

