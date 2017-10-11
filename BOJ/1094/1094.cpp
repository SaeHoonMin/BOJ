#include <iostream>

int main(void)
{
	using namespace::std;

	int sum = 64;
	
	int x;
	cin >> x;

	int shortest = 64;
	int count = 1;

	while (sum != x)
	{
		count++;
		shortest >>= 1;
		
		if (sum - shortest >= x)
		{
			count--;
			sum -= shortest;
		}
 	}
	cout << count;
}