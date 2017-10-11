#include<iostream>
using namespace::std;
#define TOT 4
#define C1 1
#define C2 2
#define C3 3

int arr[4][5];

int main(void)
{
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			int a;
			cin >> a;
			arr[j][a]++;
			arr[j][TOT] += a;
		}
	}

	int max = 0;
	int idx = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (arr[i][TOT] > max)
		{
			max = arr[i][TOT];
			idx = i;
		}
	}

	bool unchanged = false;

	for (int i = 1; i <= 3; i++)
	{
		if (i != idx && arr[i][TOT] == max)
		{
			if (arr[i][3] > arr[idx][3])
			{
				idx = i;
				unchanged = false;
			}
			else if (arr[i][3] == arr[idx][3] && arr[i][2] > arr[idx][2])
			{
				idx = i;
				unchanged = false;
			}
			else if (arr[i][3] == arr[idx][3] && arr[i][2] == arr[idx][2])
			{	
				unchanged = true;
			}
		}
	}

	if (unchanged)
		idx = 0;

	cout << idx << " " << max;
}