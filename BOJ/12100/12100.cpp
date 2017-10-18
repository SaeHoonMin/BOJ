#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace::std;

#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3

int **board;

int n;

void doJob(int dir, int ** arr)
{
	if (dir == UP)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//0이면 가장 가까운 수 찾아서 끌어내린다
				if (!arr[i][j])
				{
					int h = i + 1;
					while (h<n && !arr[h][j])
					{
						h++;
					}
					if (h < n)
					{
						arr[i][j] = arr[h][j];
						arr[h][j] = 0;
					}
				}

				if (arr[i][j] != 0)
				{
					//가장 가까운 0아닌 수 찾아서 합친다
					int h = i + 1;
					while (h<n && !arr[h][j])
					{
						h++;
					}
					if (h<n && arr[i][j] == arr[h][j])
					{
						arr[i][j] += arr[h][j];
						arr[h][j] = 0;
					}
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
				//0이면 가장 가까운 수 찾아서 끌어내린다
				if (!arr[i][j])
				{
					int w = j + 1;
					while (w<n && !arr[i][w])
					{
						w++;
					}
					if (w < n)
					{
						arr[i][j] = arr[i][w];
						arr[i][w] = 0;
					}
				}

				if (arr[i][j] != 0)
				{
					//가장 가까운 0아닌 수 찾아서 합친다
					int w = j + 1;
					while (w<n && !arr[i][w])
					{
						w++;
					}
					if (w<n && arr[i][j] == arr[i][w])
					{
						arr[i][j] += arr[i][w];
						arr[i][w] = 0;
					}
				}
			}
		}
	}
	else if (dir == RIGHT)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = 0; i < n; i++)
			{
				//0이면 가장 가까운 수 찾아서 끌어내린다
				if (!arr[i][j])
				{
					int w = j - 1;
					while (w >= 0 && !arr[i][w])
					{
						w--;
					}
					if (w >= 0)
					{
						arr[i][j] = arr[i][w];
						arr[i][w] = 0;
					}
				}

				if (arr[i][j] != 0)
				{
					//가장 가까운 0아닌 수 찾아서 합친다
					int w = j - 1;
					while (w >= 0 && !arr[i][w])
					{
						w--;
					}
					if (w >= 0 && arr[i][j] == arr[i][w])
					{
						arr[i][j] += arr[i][w];
						arr[i][w] = 0;
					}
				}
			}
		}
	}
	else //DOWN
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				//0이면 가장 가까운 수 찾아서 끌어내린다
				if (!arr[i][j])
				{
					int h = i - 1;
					while (h >= 0 && !arr[h][j])
					{
						h--;
					}
					if (h >= 0)
					{
						arr[i][j] = arr[h][j];
						arr[h][j] = 0;
					}
				}

				if (arr[i][j] != 0)
				{
					//가장 가까운 0아닌 수 찾아서 합친다
					int h = i - 1;
					while (h >= 0 && !arr[h][j])
					{
						h--;
					}
					if (h >= 0 && arr[i][j] == arr[h][j])
					{
						arr[i][j] += arr[h][j];
						arr[h][j] = 0;
					}
				}
			}
		}//for i 

	}
}

int solve(int dir, int ** arr, int cnt)
{
	if (cnt == 0)//종료
	{
		int ret = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n;j++)
				ret = max(ret, arr[i][j]);
		return ret;
	}

	int **currentArr;


	currentArr = (int**)malloc(sizeof(int*)*n);
	for (int i = 0;i < n; i++)
	{
		currentArr[i] = (int*)malloc(sizeof(int)*n);
		if (dir == -1)
			memcpy(currentArr[i], board[i], sizeof(int)*n);
		else
			memcpy(currentArr[i], arr[i], sizeof(int)*n);
	}

	//currentArr가지고 dir만큼 변형
	if (dir != -1)
	{
		cnt--;
		doJob(dir, currentArr);
	}


	int value = -1;
	for (int i = 0; i < 4; i++)
	{
		value = max(solve(i, currentArr, cnt), value);
	}

	for (int i = 0;i < n; i++)
	{
		free(currentArr[i]);
	}
	free(currentArr);

	return value;
}

int main(void)
{
	/*
		12100 : 2048 ( EASY )

		완전탐색으로 구현..
	*/
	scanf("%d", &n);


	board = (int**)malloc(sizeof(int*)*n);
	for (int i = 0;i < n; i++)
	{
		board[i] = (int*)malloc(sizeof(int)*n);
	}


	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	int answer = solve(-1, NULL, 5);

	printf("%d", answer);
	return 0;
}