#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
using namespace::std;

#define PRIME 1
#define NO 2

char flags[1000001];
int main(void)
{
	/*
		6588 : 골드바흐의 추측
		1.우선 소수 집합은 백만 이하니까 에라토스테네스의 채로 구한다
	*/
	vector<int> primes;
	for (int i = 2; i <= 1000000; i++)
	{
		if (flags[i] == NO)
			continue;
		
		flags[i] = PRIME;
		primes.push_back(i);

		for (int j = 2; i*j <= 1000000; j++)
			flags[i*j] = NO;
	}
	
	/*
		2. 구한 소수들로 TC 처리 : 
			val 보다 작은 큰 수(b)먼저 고른 뒤(upper_bound),  val-b값 이분탐색 하면 됨.
	*/
	int val;
	vector<int>::iterator a, b;
	while (true)
	{
		scanf("%d", &val);
		if (val == 0) break;
	
		b = lower_bound(primes.begin(), primes.end(), val);
		while( true )
		{
			b--;
			a = find(primes.begin(), primes.end(), val - (*b));
			if (a == primes.end())
				continue;
			else
			{
				printf("%d = %d + %d\n", val, *a, *b);
				break;
			}
		}
	}
}