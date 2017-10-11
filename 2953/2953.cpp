#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <vector>
using namespace::std;


int main(void)
{
	/**
	2953 : 나는 요리사다

	*/
	int wi;
	int maxSum = -1;


	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int n;
			cin >> n;
			sum += n;
		}
		if (maxSum < sum)
		{
			maxSum = sum;
			wi = i + 1;
		}
	}
	cout << wi <<" "<< maxSum;
	
}