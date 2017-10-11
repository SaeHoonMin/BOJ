#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <vector>
using namespace::std;

int mySort(string &s1, string &s2)
{
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	else
		return s1 < s2;
}

int main(void)
{
	/**
	1181 : 단어 정렬

	*/

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), mySort);

	for (int i = 0; i < n; i++)
	{
		if (i != 0 && v[i - 1] == v[i])
			continue;
		cout << v[i] <<"\n";
	}
	

	
}