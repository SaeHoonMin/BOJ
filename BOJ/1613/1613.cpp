#include <cstdio>

int graph[401][401];

int ans(int a, int b)
{
	if (graph[a][b])
		return -1;
	else if (graph[b][a])
		return 1;
	else return 0;
}



int main(void)
{
	int n, k,t;
	scanf("%d %d", &n, &k);

	for (int i = 0;i < k; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				graph[j][k] |= (graph[j][i] & graph[i][k]);
			}
		}
	}
	scanf("%d", &t);
	for (int i = 0;i < t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", ans(a, b));
	}

	return 0;
}