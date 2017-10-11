#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace::std;

#define INT_MAX 2147483647
#define PAIR  std::pair<int,int> 
#define INF -1

#define LEN (h-t+1)



typedef struct S {
	
	int k;	//desc
	int e;	//asc
	int m;	//desc
	string name; //asc
}S;

int mySort(S & s1, S& s2)
{
	if (s1.k != s2.k)
	{
		return s1.k > s2.k;
	}
	else if (s1.e != s2.e)
	{
		return s1.e < s2.e;
	}
	else if (s1.m != s2.m)
	{
		return s1.m > s2.m;
	}
	else
		return s1.name < s2.name;
}

int main(void)
{
	/**
	10825 : 국영수
	*/
	int n;
	cin >> n;
	vector<S> s(n);
	for (int i = 0;i < n; i++)
	{
		cin >> s[i].name;
		scanf("%d %d %d", &s[i].k, &s[i].e, &s[i].m);
	}
	sort(s.begin(), s.end(), mySort);

	for (int i = 0;i < n; i++)
	{
		printf("%s\n", s[i].name.c_str());
	}

	
	return 0;
}