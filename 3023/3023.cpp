#include <iostream>
using namespace::std;



void swap(char & a, char & b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int ly, lx;
char ** arr;


void print(int x, int y, int i, int j)
{
	char c = arr[x][y];

	if (i == ly && j == lx)
	{
		if (c == '#')
			cout << '.';
		else
			cout << '#';
	}
	else
		cout << c;

}

int main(void)
{
	int y, x;
	cin >> y >> x;
	

	arr = new char*[y];
	for (int i = 0; i < y; i++)
	{
		arr[i] = new char[x];
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> ly >> lx;
	ly--; lx--;

	for (int i = 0; i < y * 2; i++)
	{
		for (int j = 0; j < x * 2; j++)
		{
			// first quarter
			if (i < y && j < x)
			{
				print(i, j, i, j);
			}
			// second quarter
			if (i < y && j >= x)
			{
				print(i, x - (j-x)-1, i, j);
			}
			// thrid quarter
			if (i >= y && j < x)
			{
				print(y - (i - y) -1 , j, i, j);
			}
			if (i >= y && j >= x)
			{
				print(y - (i - y) - 1, x - (j - x) - 1,i, j);
			}
		}
		cout << '\n';
	}
}
