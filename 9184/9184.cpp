#include <iostream>
#include <string>
#include <vector>
#include <cstdio>


using namespace::std;

#define INT_MIN     (-2147483647 - 1)
#define SIZE 21
int dp[SIZE][SIZE][SIZE];



int w(int a, int b, int c)
{

	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	int val = dp[a][b][c];
	if (val != 0)
		return val;

	if (a < b && b < c)
	{
		return  dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}

	//otherwise
	{
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}

}


int main(void)
{
	/*
	 9184 : 신나는 함수 실행
	*/

	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		
		if (a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));

	}

	return 0;
}