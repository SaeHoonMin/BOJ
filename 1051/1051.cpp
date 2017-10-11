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

int arr[50][50];

int main(void)
{
	/**
	1051 : 숫자 정사각형
	*/
	int ans = 0;

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		char buf[51];
		scanf("%s", &buf);
		for (int j = 0; j < m; j++)
		{
			
			arr[i][j] = buf[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num = arr[i][j];
			int k = i, l = j;
			int cnt = 0;
			int size = 1;
			while (k < n && l < m)
			{
				cnt++;
				if (arr[k][l] == num && 
					arr[k][l-cnt+1] == num && 
					arr[k-cnt+1][l] == num)
					size = cnt;
				k++;l++;
			}
			ans = max(ans, (int)pow(size, 2));
		}
	}
	
	cout << ans;
	return 0;
}