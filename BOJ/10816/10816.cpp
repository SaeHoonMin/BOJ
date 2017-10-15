#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <string.h>
#include <map>
using namespace::std;



int main(void)
{
	/*
	10816 : 숫자 카드2

	걍 map에다 넣고 카운트 세주면 됨 .
	*/
	map<int, int> mymap;
	map<int, int>::iterator it;
	int n, m;
	cin >> n;
	for (int i= 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		it = mymap.find(num);
		if (it != mymap.end())
			(it->second)++;
		else
		{
			mymap[num] = 1;
		}

	}
	cin >> m;
	for (int i = 0;i < m; i++)
	{
		int num; 
		scanf("%d", &num);
		it = mymap.find(num);
		if (it != mymap.end())
			printf("%d", it->second);
		else
			printf("0");

		if (i < m - 1)
			printf(" ");

	}

}