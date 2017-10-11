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

	memset(cnt, -1, sizeof(cnt));
	char buf[101];
	scanf("%s", buf);


	for (int i = 0; i < strlen(buf); i++)
	{
		int idx = CTOI(buf[i]);
		
		if(cnt[idx] == -1)
			cnt[idx] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", cnt[i]);
	}


}