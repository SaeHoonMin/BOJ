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


using namespace::std;

char arr[400][400];
int n;

void draw(int cnt, int w, int y, int x)
{
	if (cnt == 0) return;
	int height = w + 2;

	int left = x - w + 1;
	int bottom = y + height;
	
	for (int i = 0; i < w; i++)
	{
		arr[y][x] = '*';
		if (x - 1 >= left) x--;
	}
	for (int i = 0; i < height; i++)
	{
		arr[y][x] = '*';
		if (y + 1 < bottom) y++;
	}
	for (int i = 0; i < w; i++, x)
	{
		arr[y][x] = '*';
		if (x +1 < left+w) x++;
	}
	for (int i = 0; i <= height - 2; i++)
	{
		arr[y][x] = '*';
		if (y - 1 > bottom - height + 1) y--;
	}


	if(cnt!=1)
		arr[y][x-1] = '*';

	draw(cnt - 1, w - 4, y, x-2);
}

int main(void)
{
	/**
		10997 : 별 찍기 -22
		달팽이모양임.

		시작위치는 오른쪽 위이고 끝은 왼쪽 위에서 -2라고하면, 이게 1cycle.

		다음단계는 이전단계 끝에서 x가 -2만큼 연결하고 시작

		최대 크기? (가로,세로)
		1    2     3         4
		1,1  5,7   9, 11     13, 15

		w = 1 + (n-1)*4
		h(n) = w(n)+2
	*/

	cin >> n;
	int width = 1 + (n - 1) * 4;

	memset(arr, ' ', sizeof(arr));

	if (n == 1)
	{
		printf("*");
		return 1;
	}


	draw(n, 1 + (n - 1) * 4, 0,width-1);
	
	for (int i = 0; i < width + 2; i++)
	{
		arr[i][width] = '\0';
		if (i == 1)
			arr[i][1] = '\0';
		printf("%s\n", arr[i]);
	}

	return 0;
}

