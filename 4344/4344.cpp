#include <cstdio>
#include <vector>
using namespace::std;


int main()
{
	int t;


	scanf("%d",&t);

	for (int i = 0; i < t; i++)
	{
		int n;
		int sum = 0;
		scanf("%d", &n);
		vector<int> arr(n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		double avg = sum / n;
		int cnt = 0;
		for (int j = 0;j < n; j++)
		{
			if (arr[j] > avg)
			{
				cnt++;
			}
		}
		printf("%.3lf%%\n", (double)cnt / n * 100);

	}


}