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

char arr[2047][4094];

int n, x;

void draw(int cnt, int height, int y)
{
	if (cnt == 0)
		return;

	int bottom = height * 2 - 1;
	int k = 0;
	int j;

	if (cnt % 2 == 1)
	{
		for (int i = y; i < y + height; i++, k++)
		{
			j = x - k;
			for (; j <= x + k; j++)
			{
				if (j == x - k || j == x + k )
					arr[i][j] = '*';
				else if (i+1 == y + height)
					arr[i][j] = '*';
			}
		}
		draw(cnt - 1, height / 2, y + height - 2);
	}
	else
	{
		
	
		for (int i = y; i >= y - height+1; i--, k++)
		{
			j = x - k;
			for (; j <= x + k; j++)
			{
				if (j == x - k || j == x + k)
					arr[i][j] = '*';
				else if (i == y - height+1)
					arr[i][j] = '*';
			}
		}

		draw(cnt - 1, height / 2, y - height+2);
	}
}

int main(void)
{
	/**
		10993 : 별 찍기 18
		
		밑변 : 1, 5, 13, 29 : 이전*2 +3 

		높이 : 이전*2+1
		      1, 3, 7, 15

		밑변 : 높이 *2 -1

		짝수 : 역삼각형

	*/

	int height=1; 
	cin >> n;
	
	for (int i = 2; i <= n; i++)
	{
		height = height * 2 + 1;
	}
	x = (height * 2 - 1) / 2;

	memset(arr, ' ', sizeof(arr));

	draw(n, height, (n%2==1)?0:height-1);

	int l = (n % 2 == 1) ? x : (height * 2 - 1);
	int k = 0;
	for (int i = 0; i < height; i++)
	{
		arr[i][l + k + 1] = '\0';
		printf("%s\n", arr[i]);
		k = (n % 2 == 1) ? k + 1:k - 1;
	}
	
	return 0;
}

