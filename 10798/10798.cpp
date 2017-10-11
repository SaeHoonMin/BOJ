#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace::std;

int main(void)
{
	vector<string> str(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
	}

	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (j < str[i].length())
				printf("%c", str[i][j]);
		}
	}
}