#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace::std;


char arr[3073][6145];


void recur(int x, int y, int t)
{
	if (t == 3) // 밑변 길이가 3이면 최소단위이므로
	{
		arr[y][x] = '*';

		arr[y + 1][x - 1] = arr[y + 1][x + 1] = '*';

		for (int i = -2; i <= 2; i++)
			arr[y + 2][x + i] = '*';
	}
	else
	{
		// 위에꺼, 왼쪽 아래, 오른쪽 아래 순서
		recur(x, y, t / 2);
		// 단계가 24일때 다음 recur의 x좌표는 +- 12,
		// y는 + 12니까
		recur(x - t / 2, y + t / 2, t / 2);
		recur(x + t / 2, y + t / 2, t / 2);
	}
}

int main(void)
{
	/*

	2448: 별찍기 -11

	입력 크기		3	  6      12        24
	밑변 길이		5   5*2+1  5*4+3     5*8+7
	밑변 길이 =  5*(n/3)+((n/3)-1)

	*/
	int n; 
	cin >> n;

	for (int i = 0;i < n; i++)
	{
		memset(arr[i], ' ', sizeof(arr[i]));
	}

	int length = 5 * (n / 3);
	if (n != 3) length += ((n / 3) - 1);
	recur(length / 2, 0, n);

	for (int i = 0; i < n; i++)
	{
		arr[i][length] = '\n';
        arr[i][length+1] = '\0';
		printf("%s",arr[i]);
	}
	
	return 0;
}