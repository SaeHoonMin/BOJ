#include <math.h>
#include <stdio.h>
#include <string.h>

#define PRIME 1
#define NO 2

int flags[10001];

int main(void)
{
	/**
	2581 : 소수
	*/
	int n, m, ans = 0, first = 99999;
	scanf("%d %d", &m, &n);

	flags[1] = NO;
	for (int i = 2; i <= n; i++)
	{
		if (flags[i]==0)
			flags[i] = PRIME;
		for (int j = 2; i*j <= 10000; j++)
		{
			flags[i*j] = NO;
		}

		if (i >= m && i <= n && flags[i] == PRIME)
		{
			ans += i;
			if (first > i)
				first = i;
		}
	}

	if (ans == 0)
		printf("-1");
	else
		printf("%d\n%d", ans, first);
	
}
	