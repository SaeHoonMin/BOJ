#include <iostream>
#include <cstdio>
using namespace::std;

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int s;
		int n;
		cin >> s;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int a, b;
			cin >> a >> b;
			s += (a * b);
		}
		cout << s << endl;
	}
}
	
