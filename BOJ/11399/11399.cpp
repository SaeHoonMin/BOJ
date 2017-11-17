#include <math.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <memory.h>
#include <vector>


using namespace::std;

bool visited[100001];

int main(void)
{
	/**
		11399 ATM
		걍 정렬하고 누적합 구해서 더하면 됨
	*/

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0;i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	
	long long int sum = 0;
	long long int ans =0;
	for (int i = 0;i < n; i++)
	{
		sum += arr[i];
		ans += sum;
	}
	cout << ans;
	return 0;
}

