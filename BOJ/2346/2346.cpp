#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <list>
#include <vector>

#define PAIR  std::pair<int,int> 

using namespace::std;

int n;
int main(void)
{
	/**
	2345 풍선 터트리기
	*/

	cin >> n;

	vector< PAIR > v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i+1;
	}



	vector< PAIR >::iterator it = v.begin();

	for (int i = 0;i < n; i++)
	{
		cout << it->second << " ";

		int t = it->first;

		if (v.size() - 1 != 0)
		{
			it = v.erase(it);
			if (it == v.end())
				it = v.begin();

			int cnt = t > 0 ? 1 : 0;

			if (t > 0)
			{
				while (cnt != t)
				{
					if (it == v.end()-1)
						it = v.begin();
					else
						it++;
					cnt++;
				}
			}
			else
			{
				while (cnt != t)
				{
					if (it == v.begin())
						it = v.end()-1;
					else
						it--;
					cnt--;
				}
			}
		}

	}

	return 0;
}