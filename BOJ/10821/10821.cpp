#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace::std;

int main(void)
{
	int cnt = 0;
	int n;
	char c;
	while (scanf("%d", &n)==1)
	{
		cnt++;
		if (scanf("%c", &c) == EOF)
			break;
	}
	cout << cnt;


	return 0;
}