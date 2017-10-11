#include <iostream>
#include <math.h>
using namespace::std;

void calc(int & a)
{
	if (a != 1)
	{
		if (a % 2 == 1)
		{
			a = (a + 1) / 2;
		}
		else
			a = a / 2;
	}
}

int main(void)
{
	int n, kim, im;
	cin >> n >> kim >> im;


	int smaller = kim > im ? im : kim;
	int bigger = kim > im ? kim : im;
	int round = 1;
	while(true)
	{
		if (smaller + 1 == bigger && 
			bigger % 2 == 0)
		{
			break;
		}else
		{
			calc(smaller);
			calc(bigger);
			round++;
		}
	}
	cout << round;
}