#include <iostream>
#include <math.h>
using namespace::std;

int n, row, col;

int cnt = 0;

bool flag = false;


/*
	2^15 * 2^15 = 32768^2 = 10억 넘어감.
	
	4개씩 쪼갤때 쪼갠 구간이 정답 row, col 에 들어가는지 체크해서
	포함안되는구간은 더해버리면 속도 빨라질 듯
	
*/

void solve(int num, int r, int c, int er, int ec)
{
	if (num == 2 && flag == false)
	{
		for (int i = r; i < er; i++)
		{
			for (int j = c; j < ec; j++)
			{
				if (i == row && j == col)
				{
					flag = true;
					return;
				}
				cnt++;
			}
		}

	}



	if (num != 2 && flag == false)
	{
		int half = num / 2;

		if (row >= r && row < r + half)
		{
			if (col >= c && col < c + half)
			{
				solve(half, r, c, r + half, c + half);
			}
			else
			{
				cnt += (half*half);
				solve(half, r, c + half, r + half, c + num);
			}
		}
		else
		{
			if (col >= c && col < c + half)
			{
				cnt += (half*half) * 2;
				solve(half, r + half, c, r + num, c + half);
			}
			else
			{
				cnt += (half*half) * 3;
				solve(half, r + half, c + half, r + num, c + num);
			}
		}
	}
}

int main(void)
{
	
	cin >> n >> row >> col;


	int num = pow(2, n);

	solve(num, 0, 0,num, num);
	

	
	cout << cnt;

	return 0;

}