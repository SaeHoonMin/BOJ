#include <iostream>

using namespace::std;

int main(void)
{
	// dp[0] = 0
	// dp[1] = 1,  = 1 a
	// dp[2] = 10,  = 1 b    a
	// dp[3] = 100, 101 = 2; ( dp[1] + dp[2] ) resul   b
	// dp[4] = 1010, 1001, 1000 (dp[3] + dp[4] ) 


	int n;

	cin >> n;


	// a = f(n -2), b = f(n -1)
	long long int a =1, b = 1;

	long long int result = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			result = 1;
		else if (i == 2)
			result = 2;
		else
		{
			result = a + b;
			a = b; 
			b = result;
		}
	}
	cout << result;
}