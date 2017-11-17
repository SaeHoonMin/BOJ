#include <string>
#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace::std;


int main()
{
	/**
		1764 : 듣보잡
		걍 카운팅 해서 2번 나오면 듣보잡인거
	*/
	int n, m, nm, a;
	cin >> n >> m;
	nm = n + m;
	map<string,int> strmap;
	vector<string> v;
	for (int i = 0;i < nm; i++)
	{
		string s;
		cin >> s;
		a = ++strmap[s];
		if (a == 2)
			v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		printf("%s\n", v[i].c_str());
	}


    return 0;
}

