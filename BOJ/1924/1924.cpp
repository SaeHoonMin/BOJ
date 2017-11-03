#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
using namespace::std;

int month[] = {0, 31,28,31, 30, 31, 30, 31, 31, 30, 31,30,31 };
string days[] = {"SUN", "MON","TUE","WED","THU","FRI","SAT" };
int main(void)
{
	/*
		1924 : 2007년

		2007년 x월 y일 몇요일이냐?
	*/
	int mm, dd;
	int d = 0;
	cin >> mm >> dd;
	for (int i = 1; i < mm; i++)
	{
		d += month[i];
	}
	d += dd;
	cout << days[d % 7].c_str();
	
	
	return 0;
}