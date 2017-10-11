#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace::std;

#define INT_MAX 2147483647
#define PAIR  std::pair<int,int> 
#define INF -1

#define LEN (h-t+1)

int main(void)
{
	/**
	1806 : 부분합
	*/
	int ans = INT_MAX;
	int n, s;
	int t= 0, h= 0;
	int currentSum = 0;
	cin >> n >> s;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	currentSum = arr[h];
	while ( true )
	{
		if (currentSum >= s)
		{
			ans = min(LEN, ans);

			if (LEN > 1)
			{
				currentSum -= arr[t];
				t++;
			}
		}
		else
		{
			h++;
			currentSum += arr[h];
		}

		if ( h+1 == arr.size() && currentSum < s)	//답 못찾음
			break; 
		if (ans == 1)
			break;
	}
	if (ans == INT_MAX)
		ans = 0;
	cout << ans;
	return 0;
}