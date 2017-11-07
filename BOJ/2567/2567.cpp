#include <math.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <memory.h>
#include <vector>

#define NONE 0
#define EDGE 1
#define FACE 2

using namespace::std;
int arr[100][100];
int y[] = { 0,1,0,-1 };
int x[] = { 1,0,-1,0 };
int main(void)
{
	/*
		2567 : 색종이 2
	*/
	int P, a, b;
	cin >> P;
	for (int p = 0; p < P; p++)
	{
		scanf("%d %d", &a, &b);
		for (int i = a; i < a+10; i++)
		{
			for (int j = b; j < b+10; j++)
			{
				//i, j가 테두리 그리는중이고 이미 그려져있는 칸이 테두리거나 백지면
				if ((i == a || j == b || i == a + 9 || j == b + 9)
					&&
					(arr[i][j] == NONE || arr[i][j] == EDGE))
					arr[i][j] = EDGE;
				else
					arr[i][j] = FACE;
			}
		}
	}

	int l = 0;
	for (int i = -1;i < 101; i++)
	{
		for (int j = -1; j < 101; j++)
		{
			if (arr[i][j] == 0 ||
				i==-1 || j==-1 || i==100 || j==100)
			{
				for (int k = 0; k < 4; k++)
				{
					int dy = y[k] + i;
					int dx = x[k] + j;

					if (dy >= 0 && dy < 100 && dx >= 0 && dx < 100 &&
						arr[dy][dx] == EDGE)
						l++;
				}
			}
		}
	}

	cout << l;
	
	return 0;
}

