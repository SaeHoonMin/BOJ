#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace::std;



long long int ans[101];
void calc()
{
	// 1 1 1 2 2 3 4 5 7 9 12
	// 1 2 3 4 5 6 7 8 9 10
	// 
	// p(9) = p(8) + p(5)
	// p(10) = p(9) + p(5)	 -5, -1	
	// p(11) = p(10) + p(6)    
	// p(12) = p(11) + p(7)  = 
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 1;
	ans[4] = 2;
	ans[5] = 2;
	for (int i = 6; i <= 100; i++)
	{
		ans[i] = ans[i - 5] + ans[i - 1];
	}

}
int main(void)
{
	int t;
	cin >> t;

	calc();

	for (int i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		cout << ans[a] << endl;
	}
}
