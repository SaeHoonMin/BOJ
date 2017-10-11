#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace::std;

const char * isVPS(string s)
{
	vector<char> v;

	for (int i = 0;i < s.size(); i++)
	{
		if (s[i] == '(')
			v.push_back(s[i]);
		else
		{
			if (v.size() == 0)
				return "NO\n";
			if (v.back() == ')')
				return "NO\n";
			v.pop_back();
		}
	}
	if (v.size() == 0)
		return "YES\n";
	else
		return "NO\n";
}

int main(void)
{
	/*
		9012 괄호

		걍 스택으로 괄호 짝 검사하면 됨..
	*/
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		printf("%s", isVPS(s));
	}


	return 0;
}