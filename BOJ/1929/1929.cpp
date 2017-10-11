#include <cstdio>
using namespace::std;

int arr[1000001] = { 1, 1, };

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	for (int i = 2; i <= b; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = 2; ;j++ )
			{
				if (j*i > b) break;
				arr[j*i] = 1;
			}
		}
	}

	for (int i = a; i <= b; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}
}