#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace::std;

#define ZERO 1000

int ans[2002]; 

int main(void)
{
	int n; 
	int * arr;
	cin >> n;
	arr = new  int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0;i < n; i++)
	{
		if (ans[ZERO+ arr[i]] == 0)
			printf("%d ", arr[i]);

		ans[ZERO+arr[i]]++;
	}
}
