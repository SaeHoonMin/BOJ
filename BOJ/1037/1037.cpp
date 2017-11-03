#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>

using namespace::std;

int main(void)
{
	/*
		1037 : 약수

		걍  구하면 됨
	*/
	

	int n; 
	cin >> n;
	vector<int> arr(n);
	for (int i = 0;i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	cout << arr[0] * arr[arr.size()-1];
	
	return 0;
}