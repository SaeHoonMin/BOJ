#include <iostream>
#include <algorithm>
using namespace::std;
int arr[50][50];

int n, m;
#define NONE 0
#define GUARDED 1




int main(void)
{

	cin >> n >> m;

	char c; 



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			if (c == 'X')
			{
				arr[i][j] = GUARDED;
			}
		}
	}

	// row 탐색
	int rc = n;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == GUARDED)
			{
				rc--;
				break;
			}
		}
	}

	int cc = m; 
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == GUARDED)
			{
				cc--;
				break;
			}
		}
	}

	cout << max(rc, cc);
}