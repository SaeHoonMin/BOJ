#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
using namespace::std;

#define SELF 1
#define NOT 2
int check[10001];
int main(void)
{
	/*
		4673 : 셀프 넘버

		d(n)=  n + (각 자리수 합 ) 

		1~10000의 셀프 넘버는?
	*/
;
	for (int i = 1; i <= 10000; i++)
	{
		if (check[i] == NOT)
			continue;

		check[i] = SELF;
		int num = i;
		while (num <= 10000)
		{
			int j = num;
			int sum = j;
			while (j != 0)
			{
				int res = j % 10;
				sum += res;
				j = j / 10;
			}
			check[sum] = NOT;
			num = sum;
		}
		
	
		if (check[i] == SELF)
			printf("%d\n", i);
	}
	
}