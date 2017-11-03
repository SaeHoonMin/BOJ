#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
using namespace::std;
int main(void)
{
	/*
		11652 : 카드

		-2^62 ~2^62 범위 카드 100만 개 중 제일 많은 정수 구하기
	*/	
	int n;
	long long int c;
	map<long long int, int> cards;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &c);
		cards[c]++;
	}

	int ans = -1;
	long long int num = -1;
	for (auto it = cards.begin(); it != cards.end(); ++it)
	{
		if (ans == -1)
		{
			ans = (*it).second;
			num = (*it).first;
		}
		else if (ans < (*it).second)
		{
			ans = (*it).second;
			num = (*it).first;
		}
	}
	cout << num;

	return 0;
}