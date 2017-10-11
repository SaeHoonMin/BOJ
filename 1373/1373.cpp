
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

char s[1000001];
char ans[333344];

int main(void)
{
	/**
	1373 : 2진수 8 진수
	*/


	int j = 0, cnt = 0;
	scanf("%s", &s);

	for (int i = strlen(s)-1; i >= 0; i--)
	{
		if (cnt == 3)
		{
			j++; cnt = 0;
		}
		ans[j] += (s[i] - '0')* pow(2, cnt++);
	}

	for (int i = j; i >= 0; i--)
	{
		printf("%d", ans[i]);
	}
}
	