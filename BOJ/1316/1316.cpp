#include <cstdio>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define CTOI(x) (x-'a')
using namespace::std;

int cnt[26];

int main()
{
	int t;


	scanf("%d",&t);


	int ans = t;

	for (int i = 0; i < t; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		char buf[101];
		scanf("%s", buf);

		int ch_before = -1;
		for (int j = 0; j < strlen(buf); j++)
		{
			int idx = CTOI(buf[j]);
			if (cnt[idx] == 0)
			{
				cnt[idx]++;
				ch_before = idx;
			}
			else
			{
				if (ch_before != idx)
				{
					ans--;
					break;
				}
			}
		}
	}

	printf("%d", ans);


}