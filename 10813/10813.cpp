#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <vector>
using namespace::std;


int arr[101];

int main(void)
{
	/**
	10831 : 공 바꾸기

	*/
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		arr[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		cin >> a >> b;
		t = arr[a];
		arr[a] = arr[b];
		arr[b] = t;
	}
	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
}
	