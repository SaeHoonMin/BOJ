#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
using namespace::std;

char primes[10000001];
int primev[664579];
int main(void)
{
	/*
	11653 소인수분해

	*/

	vector<int> answers;
	int n, k,l=0;
	cin >> n;

	primes[1] = 1;

	

	for (int i = 2; i <= n; i++)
	{
		if (primes[i] == 1)
			continue;
		primev[l++] = i;
		for (int j = 1; j*i <= n; j++)
		{
			primes[i*j] = 1;
		}
	}

	while (n != 1)
	{
		k = 0;
		if (!primes[n])
		{
			answers.push_back(n);
			break;
		}

		while (n % primev[k])
		{
			k++;
		}
		answers.push_back(primev[k]);
		n /= primev[k];
	}
	for (int i = 0;i < answers.size(); i++)
	{
		printf("%d\n", answers[i]);
	}

}