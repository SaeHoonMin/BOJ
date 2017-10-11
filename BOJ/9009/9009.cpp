#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <string>
#include <deque>
#include <algorithm>


using namespace::std;

vector<int>fibo;
vector<int> AnswerVector;

int n;


void solve2(long long val, vector<int> &v, int before)
{
	if (n == val)
	{
		for (int i = 0; i < v.size(); i++)
			AnswerVector.push_back(v[i]);

		v.pop_back();
		return;
	}
	
	for (int i = before-1; i >= 0; i--)
	{
		if (val + fibo[i] <= n && AnswerVector.empty())
		{
			v.push_back(fibo[i]);
			solve2(val + fibo[i], v, i);
		}
	}

	if( ! v.empty() )
		v.pop_back();
	return;
}

void solve(int n)
{
	vector<int> v;
	AnswerVector.clear();


	solve2(0, v, fibo.size()-1);

	for (int j = AnswerVector.size()-1; j >=0 ; j--)
	{
		printf("%d ", AnswerVector[j]);
	}
	printf("\n");

}

int main(void)
{
	/*
		9009 피보나치
		     -> 1. dfs
			    2. DP

		DP로 풀려면  n이 10억이므로 불가

		완전탐색 : 
		 fibo(45)면 10억 넘어가므로.. 44까지만 하면 됨
		단 44! 면 숫자가 너무 큼..

		대략 10억 근방까지만 fibo 수 구해놓은 뒤,

		큰 수에서 작은수로 탐색하여 답 찾으면 바로 quit
		
	*/
	fibo.push_back(0);
	fibo.push_back(1);
	for (int i = 2;i <= 100; i++)
	{
		int a = fibo[i - 2] + fibo[i - 1];
		fibo.push_back(a);
		if (fibo[i] >= 1000000000)
			break;
	}

	int t;
	cin >> t;
	for (int i = 0;i < t; i++)
	{
		scanf("%d", &n);
		solve(n);
	}
}
