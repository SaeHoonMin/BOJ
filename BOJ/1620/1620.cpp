#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace::std;

map<string, int> pokemon1;
string names[100001];
int ten[6] = { 1, 10, 100, 1000, 10000, 100000 };
int main()
{
	int n, t;
	cin >> n >> t;
	char name[30];
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", name);
		names[i] = name;
		pokemon1[names[i]] = i;
	}

	for (int i = 1; i <= t; i++)
	{
		char input[25];
		scanf(" %s", input);
		if (input[0] >= 'A' && input[0] <= 'Z')
		{
			printf("%d\n", pokemon1[input]);
		}
		else
		{
			int len = strlen(input);
			int num = 0;
			for (int j = 0; j < len; j++)
			{
				num = num + ((input[j] - '0') * ten[len - j - 1]);
			}
			printf("%s\n", names[num].c_str());
		}
	}
}