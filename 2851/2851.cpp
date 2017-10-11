#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace::std;



int main(void)
{
	/*
		2851: 슈퍼 마리오
	*/
	int mushroom, a, b;
	int score = 0;
	int ans = 0;
	for (int i = 0;i < 10; i++)
	{
		cin >> mushroom;
		score += mushroom;
		a = abs(100 - ans);
		b = abs(100 - score);
		if (a > b)
		{
			ans = score;
		}
		else if (a == b)
			ans = max(ans, score);
	}

	cout << ans;


	return 0;
}