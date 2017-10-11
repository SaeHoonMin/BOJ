#include <iostream>
using namespace::std;


int arr[100];

int main(void)
{
	int n, p;
	cin >> n >> p;

	int next = n;
	int ans = 0;
	do {
		next = (next * n) % p;

		
		if (arr[next] == 1)
		{
			arr[next]++;
		}
		else if(arr[next] == 0)
		{
			arr[next] = 1;
		}
		else if (arr[next] == 2)
		{
			for (int i = 0; i < 100; i++)
				if (arr[i] >1)
					ans++;
			break;
		}

	} while (true);


	cout << ans;

}
