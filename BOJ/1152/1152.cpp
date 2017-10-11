#include <iostream>
#include <string>
using namespace::std;
int main(void)
{
	string str;
	getline(cin, str);
	int cnt =0;
	bool charAppear = false;
	for (int i = 0; i< str.length(); i++)
	{
		if (str[i] == ' ' && charAppear == true)
		{
			charAppear = false;
			cnt++;
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= 'a' && str[i] <= 'z'))
		{
			charAppear = true;
		}
	}
	if (charAppear == true)
		cnt++;
	std::cout << cnt;

}