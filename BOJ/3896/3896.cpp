#include <string>
#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace::std;

#define MAX 1299709

int mask[MAX];

int main()
{
	/**
		3896 : 소수 사이 수열
		간단한 에라토스테네스 ㅊㅔ 문제
	*/
	int T;
	cin >> T;

	mask[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		if (mask[i] == 0)
		{
			for (int j = 2; i*j <= MAX; j++)
			{
				mask[i*j] = 1;
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		int t; 
		scanf("%d", &t);
		if (mask[t] == 0)
		{
			printf("0\n");
		}
		else
		{
			int a, b;
			a = b = t;
			while (a <= MAX && mask[a] != 0)
				a++;
			while (b >= 2 && mask[b] != 0)
				b--;

			printf("%d\n", a - b);

		}
	}
	
    return 0;
}

