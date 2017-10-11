#include <iostream>
using namespace::std;
int main()
{
	int n, s = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		char d; 
		std::cin >> d;
		s += d - '0';
	}
	std::cout << s;
}