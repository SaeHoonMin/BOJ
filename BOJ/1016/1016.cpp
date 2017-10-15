#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <string.h>
#include <map>
using namespace::std;

bool masks[1000001];
long long int pows[1000001];

int main(void)
{
	/*
	1016: 제곱 ㄴㄴ수

	어떤 수 x가 제곱 ㄴㄴ수려면.....?
	ex) 81-> 제곱 ㄴㄴ수 아님. 81/(9^2) 
	
	1) 제곱수가 아닐 것.
	2) 어떤 수 a가 제곱수일때, a* (1...n)이 아닐 것

	수의 범위는 1조지만 min, max사이의 범위는 백만임.

	
	** 해법? **
	
	미리 제곱수를 1,000,000(백만개 ) 구하면서 마스킹
	어떤 n번째 제곱수 p[n]을 구하면 p[n] * a >= min 인 최소 a를 구한 뒤,
	for( a*p[n] <=max ; a++ ) 돌면서 마스킹.



	*/
	long long int min, max;
	cin >> min >> max;

	int cnt = 0;

	for (long long int i = 2; i<=1000000; i++)
	{
		pows[i] = i*i;
		if (pows[i] >= min && pows[i] <= max)
		{
			masks[pows[i] - min] = 1;
		}
		long long int  a = ceil(min / pows[i]);
		while (true)
		{
			if (a*pows[i] >= min)
				break;
			a++;
		}
		for (long long int j = a; j*pows[i] <= max; j++)
		{
			masks[j*pows[i] - min] = 1;
		}
	}

	for (long long int i = min; i <= max; i++)
	{
		if (!masks[i - min])
			cnt++;
	}

	cout << cnt;
	return 0;
	// mask[ i - min ]
}