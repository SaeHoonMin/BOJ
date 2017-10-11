#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace::std;

#define INT_MIN     (-2147483647 - 1)


string colors[10] =
{
	"black",
	"brown",
	"red",
	"orange",
	"yellow",
	"green",
	"blue",
	"violet",
	"grey",
	"white"
};


int findIdx(string s)
{
	for (int i = 0; i < 10; i++)
	{
		if (s.compare(colors[i]) == 0)
			return i;
	}
}

int main(void)
{

	string a, b, c;

	cin >> a >> b >> c;
	
	long long int ten = findIdx(a);
	int one = findIdx(b);
	int multiflier = findIdx(c);

	long long int ans = ((ten * 10) + one) *  pow(10, multiflier);
	cout << ans;
	return 0;
}