#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace::std;

#define PAIR  std::pair<int,int> 

#define INF -1

int main(void)
{
	/**
	1753 최단 경로
	*/

	int n;
	string a, b;
	map<string, string> employee;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (b[0] == 'e')
		{
			employee.insert( pair<string,string>(a,b));
		}
		else
		{
			employee.erase(employee.find(a));
		}
	}

	map<string, string>::reverse_iterator iter;
	for ( iter = employee.rbegin(); iter != employee.rend(); iter++)
	{
		cout << iter->first << "\n";
	}


	return 0;
}