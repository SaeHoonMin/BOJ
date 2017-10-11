#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
using namespace::std;
int main(void)
{
	/*
		10866 덱
	*/
	deque<int> dec;
	int n;
	cin >> n;
	for (int i = 0;i < n; i++)
	{
		string s;
		int x;
		cin >> s;
		if (s == "push_back")
		{
			cin >> x;
			dec.push_back(x);
		}
		else if (s == "push_front")
		{
			cin >> x;
			dec.push_front(x);
		}
		else if (s == "pop_front")
		{
			if (dec.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", dec.front());
				dec.pop_front();
			}
		}
		else if (s == "pop_back")
		{
			if (dec.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", dec.back());
				dec.pop_back();
			}
		}
		else if (s[0] == 's')
		{
			printf("%d\n", dec.size());
		}
		else if (s[0] == 'e')
		{
			printf("%d\n", dec.empty() ? 1 : 0);
		}
		else if (s == "front")
		{
			if (dec.empty())
				printf("-1\n");
			else
				printf("%d\n", dec.front());
		}
		else if (s == "back")
		{
			if (dec.empty())
				printf("-1\n");
			else
				printf("%d\n", dec.back());
		}
	}

}