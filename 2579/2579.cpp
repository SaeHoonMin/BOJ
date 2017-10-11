#include <iostream>
#include <algorithm>
using namespace::std;

int main(void)
{
	int n;

	cin >> n;

	int *arr = new int[n+1];

	int * result = new int[n + 1];

	arr[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	result[1] = arr[1];
	result[2] = arr[1] + arr[2];
	result[3] = max(arr[3] + arr[2], arr[3] + result[1]);

	for (int i = 4; i <= n; i++)
	{
		result[i] = max(arr[i] + result[i - 2], arr[i] + arr[i - 1] + result[i - 3]);
	}

	cout << result[n];

	return 0;
}