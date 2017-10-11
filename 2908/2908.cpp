#include <iostream>
#include <string>
using namespace::std;
int i=2;
int swap(string& s)
{
	return (s[2]-'0') * 100 + (s[1]-'0') * 10 + (s[0]-'0');
}
int main(void)
{
	string a, b;
	cin >> a >> b;
	
	cout << (swap(a)>swap(b)? swap(a):swap(b));
}