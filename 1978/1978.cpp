
#include <iostream>

int main(void)
{
	int cnt = 0;
	int arr[100];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	for (int i = 0;i < n; i++)
	{
		int gcnt = 0;
		if (arr[i] == 1)
			continue;
		if (arr[i] == 2)
		{
			cnt++;
			continue;
		}
		for (int j = arr[i] - 2; j > 1; j--)
		{
			if (arr[i] % j == 0)
			{
				gcnt++;
				break;
			}
		}
		if (!gcnt)
			cnt++;
	}

	std::cout << cnt;
}