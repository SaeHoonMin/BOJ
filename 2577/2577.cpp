#include <iostream>
using namespace::std;
int main(void)
{
	int arr[10] = { 0, };
	int a, b, c;
	cin >> a >> b >> c;
	int num = a*b*c;
	long long int mod = 10;
	while (mod != 10000000000)
	{
		int res = num % mod;

		arr[res / (mod /10) ]++;

		num -= res;
		mod *= 10;
		if (num == 0) break;

	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
}