#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace::std;


char arr[6562][6563];


void recur(int x, int y, int t)
{
	if (t == 3) // 밑변 길이가 3이면 최소단위이므로
	{
		for (int i = 0; i < 3; i++)
		{
			arr[y][x+i] = '*';
			arr[y + 1][x + i] = '*';
			arr[y+2][x + i] = '*';
		}
		arr[y + 1][x + 1] = ' ';
	}
	else if (t == 1)
	{
		arr[y][x] = '*';
	}
	else
	{
		//차례로 8개로 나눠야 함.
		int a = t / 3;
		recur(x, y, a);
		recur(x + a, y, a);
		recur(x + a * 2, y, a);
		
		//가온데는 하나 없음
		recur(x, y + a, a);
		recur(x + a * 2, y + a, a);

		recur(x, y + a * 2, a);
		recur(x + a, y + a * 2, a);
		recur(x + a * 2, y + a * 2, a);

	}
}

int main(void)
{
	/*

	2447: 별찍기 -10

	*/
	int n;
	cin >> n;
	for (int i = 0;i < n; i++)
		memset(arr[i], ' ', sizeof(arr[i]));

	recur(0, 0, n);

	for (int i = 0;i < n; i++)
	{
		arr[i][n + 1] = '\n';
		arr[i][n + 2] = '\0';
		printf("%s", arr[i]);

	}
	
	return 0;
}