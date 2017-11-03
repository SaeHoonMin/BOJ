#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>

#define NEXT(d) (d+1)%4
#define BACK(d) (d+2)%4
#define ROT(d)  (d=(d+1)%4)

using namespace::std;

enum Direction{ NORTH = 0, WEST, SOUTH, EAST};
enum State{ EMPTY=0, WALL, CLEANED, };
       //   n , w, s, e
int y[] = { -1, 0, 1,0 };
int x[] = { 0, -1, 0,1 };
int n, m, r, c, d, ans = 0;
int arr[50][50];

bool isValid(int x, int y)
{
	if (y >= 0 && y < n &&
		x >= 0 && x < m &&
		arr[y][x]!= WALL)
	{
		return true;
	}
	return false;
}

bool isCleanable(int x, int y)
{
	if (arr[y][x] == EMPTY)
		return true;
	else 
		return false;
}

int main(void)
{
	/*
		14503 로봇 청소기

		시뮬레이션이니까 규칙대로 짜면 됨.
	*/
	
	cin >> n >> m;
	cin >> r >> c >> d;

	//회전은 북서남동인데 입력이 북동남서니까 
	if (d == 1) d = 3;
	else if (d == 3) d = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}


	while (true)
	{
		int i = 0;

		// con 1
		if (arr[r][c] == EMPTY)
		{
			arr[r][c] = CLEANED;
			ans++;
		}
		
		
		for (i = 0;i < 4; i++)
		{	
			//condition 2
			int dy = r + y[NEXT(d)];
			int dx = c + x[NEXT(d)];
			if (isValid(dx, dy) && isCleanable(dx, dy))
			{
				//con 2.1
				ROT(d);
				r = dy;
				c = dx;
				break;	// to 1
			}
			else //con2.2
			{
				ROT(d);
			}
		}

		if (i == 4 )
		{
			int dy = r + y[BACK(d)];
			int dx = c + x[BACK(d)];
			if (isValid(dx, dy))
			{
				// con2.3
				r = dy;
				c = dx;
			}
			else
				break;	//con2.4
		}
	}

	cout << ans;
	
	return 0;
}