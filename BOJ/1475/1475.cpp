#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <vector>
using namespace::std;


int arr[10];

int main(void)
{
	/**
	1475 : 방 번호

	*/
	int ans = -1;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		arr[str[i] - '0']++;
	}
	int ns = arr[6] + arr[9];
	arr[6] = arr[9] = (ns) / 2 + (ns%2);
	for (int i = 0; i < 10; i++)
	{
		ans = max(ans, arr[i]);
	}
	cout << ans;
}
	