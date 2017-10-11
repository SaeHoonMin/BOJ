#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>

#define INT_MAX 2147483647
#define DIVIDER 1000000000
using namespace::std;

string str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string str2 = "abcdefghijklmnopqrstuvwxyz";
int len = 26;

int main(void)
{
	/**
	11655 : ROT13

	쉬어가는 문제..

	*/

	string s; 
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c >= 'a' && c <= 'z')
		{
			c -= 'a';
			s[i] = str2[(c + 13) % 26];
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c -= 'A';
			s[i] = str1[(c + 13) % 26];
		}
	}

	cout << s;

	return 0;
}