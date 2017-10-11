#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
using namespace::std;


int main(void)
{
	/**
	2745	 : 진법

	//  A-> 10 
	// char-'A'+10;
	*/

	string str;
	int w;
	cin >> str >> w;
	int j = 0, dec = 0;
	for (int i = str.size() - 1;i >= 0; i--)
	{
		char c = str[i];
		if (c >= 'A' && c <= 'Z')
			c = str[i] - 'A' + 10;
		else
			c = str[i] - '0';
		dec += c * (int)pow(w, j++);
	}
	cout << dec;
	
}