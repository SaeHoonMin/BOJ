#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
using namespace::std;


int main(void)
{
	/**
	11005	 : 진법 변환2

	*/

	int num;
	int w;
	string str;
	cin >> num >> w;
	
	while (true)
	{
		int res = num % w;
		num /= w;

		if (res < 10)
		{
			str.push_back((char)res + '0');
		}
		else
			str.push_back((char)res - 10 + 'A');

		if (num == 0)
			break;
	}
	
	for (int i = str.length() - 1; i >= 0; i--)
		cout << str[i];
	
}