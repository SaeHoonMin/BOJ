#include <iostream>
#include <math.h>
#include <string>
using namespace::std;

int main()
{
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
	}
}