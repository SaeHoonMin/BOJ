#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3

int n;
int dMax[11];
int t[20][20];

inline int max(int a, int b) { return a > b ? a : b; }

inline int getMax()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			ret = max(ret, t[i][j]);
	}
	return ret;
}

inline void doJob(int dir)
{
	int height[20] = { 0, };
	int t2[20][20] = { 0, };


	if (dir == UP)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//arr[i][j]가 있으면  height[j] 
				if (t[i][j])
				{
					if (t[i][j] == t2[height[j]][j])
					{
						t2[height[j]++][j] += t[i][j];
					}
					else if (!t2[height[j]][j]) //0인 경우
						t2[height[j]][j] = t[i][j];
					else //서로 다른 경우
						t2[++height[j]][j] = t[i][j];
				}
			}
		}//for i 
	}
	else if (dir == LEFT)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				//t[i][j]가 있으면 
				if (t[i][j])
				{
					if (t[i][j] == t2[i][height[i]])
					{
						t2[i][height[i]++] += t[i][j];
					}
					else if (!t2[i][height[i]]) //0인 경우
						t2[i][height[i]] = t[i][j];
					else //서로 다른 경우
						t2[i][++height[i]] = t[i][j];
				}
			}
		}
	}
	else if (dir == RIGHT)
	{
		for (int i = 0; i < 20; i++)
			height[i] = n - 1;

		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = 0; i < n; i++)
			{
				//t[i][j]가 있으면 
				if (t[i][j])
				{
					if (t[i][j] == t2[i][height[i]])
					{
						t2[i][height[i]--] += t[i][j];
					}
					else if (!t2[i][height[i]]) //0인 경우
						t2[i][height[i]] = t[i][j];
					else //서로 다른 경우
						t2[i][--height[i]] = t[i][j];
				}
			}
		}
	}
	else //DOWN
	{
		for (int i = 0; i < 20; i++)
			height[i] = n - 1;

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				//arr[i][j]가 있으면  height[j] 
				if (t[i][j])
				{
					if (t[i][j] == t2[height[j]][j])
					{
						t2[height[j]--][j] += t[i][j];
					}
					else if (!t2[height[j]][j]) //0인 경우
						t2[height[j]][j] = t[i][j];
					else //서로 다른 경우
						t2[--height[j]][j] = t[i][j];
				}
			}
		}//for i 

	}

	memcpy(t, t2, sizeof(t2));

}

bool same(int tmp[20][20])
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (tmp[i][j] != t[i][j])
				return false;
		}
	}
	return true;
}

void solve(int cnt)
{
	int c = getMax();

	//현재단계에서의 더이상의 분기는 최대값 도달이 불가능하다고 판단될 경우
	if (c <= dMax[cnt])
	{
		return;
	}
	if (cnt == 0)//종료
	{
		if (c > dMax[cnt])
		{
			for (int i = 0; i < 10; i++)
			{
				dMax[i] = c;
				c /= 2;
			}
		}
		return;
	}


	int temp[20][20];
	memcpy(temp, t, sizeof(temp));

	for (int i = 0; i < 4; i++)
	{
		//현재단계에서 더이상 특정 방향으로의 입력은 의미 없는 경우
		doJob(i);
		if (same(temp))
			continue;
		solve(cnt - 1);
		memcpy(t, temp, sizeof(temp));
	}

}

int main(void)
{
	/*
	12100 2048 ( EASY )

	알고리즘 개선으로 4ms 향상..

	*/
	scanf("%d", &n);

	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &t[i][j]);
		}
	}


	solve(10);

	if (n == 1)
		printf("%d", t[0][0]);
	else
		printf("%d", dMax[0]);

	return 0;
}