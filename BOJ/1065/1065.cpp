#include <cstdio>
#include <iostream>

using namespace::std;



int main(void)
{
	/*
		1065: 한수 -> x의 자리수가 등차수열
		n보다 작거나 같은 한수의 개수?
	*/
	int n, ans =0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int n = i;
		int d = 100;
		int d_before;
		int before;

		ans++;
		while (n!=0)
		{
			int num = n % 10;
			if (n==i) //처음인경우
			{
				before = num;
			}
			else
			{
				//2번째 자리 
				if (d == 100)
					d_before = num - before;
				d = num - before;
				if (d_before != d)
				{
					ans--; 
					break;
				}
				d_before = d;

				before = num;
			}
			n /= 10;
		}
	}
	cout << ans;

	return 0;
}