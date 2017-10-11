#include <iostream>
using namespace::std;

int canvas[101][101];

void paint(int a, int b)
{
	for (int j = b; j < b + 10; j++)
	{
		for (int i = a; i < a + 10; i++)
		{
			canvas[j][i] = 1;
		}
	}
}


int main(void)
{
	int paper;
	cin >> paper;

	for (int i = 0; i < paper; i++)
	{
		int a, b;
		cin >> a >> b;
		paint(a, b);
	}

	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (canvas[i][j] > 0)
				sum++;
		}
	}
	cout << sum;
}