#include <cstdio>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define CTOI(x) (x-'a')
using namespace::std;

vector<int> answers;

typedef struct node {

	vector<int> nextIdx;
	vector<int> values;

}node;


vector<node> tree;
int n;

int process(node & nod, int val)
{
	if (nod.nextIdx.size() == 0)
		return val;

	if (val == 0)
	{
		vector<int> values;

		for (int i = 0; i < nod.nextIdx.size(); i++)
		{
			values.push_back(process(tree[nod.nextIdx[i]], val + nod.values[i]));
		}
		sort(values.begin(), values.end());

		int sum = 0;
		sum += values.at(values.size() - 1);
		if ((int)values.size() - 2 >= 0)
			sum += values.at(values.size() - 2);

		return  sum  ;
	}
	else
	{
		int maxVal = 0;
		for (int i = 0; i < nod.nextIdx.size(); i++)
		{
			int value = process(tree[nod.nextIdx[i]], val + nod.values[i]);
			if (value > maxVal)
				maxVal = value;
		}
		return maxVal;
	}

}

int main()
{
	// 1 = 1                n<= 1
	// 2 to 7 = 2           n <= 1+(6*1)
	// 8 to 19 = 3         n<= 1+(6*1)+(6*2)  = 7 + 12 = 19 
	// 20 to 37 = 4       n <= 19 + 6*3 = 37
	// 38 to 61 = 5       n <= 37 + 6*4 = 61

	int n;
	cin >> n;

	int steps = 1;
	int sum = 1;
	for (int i = 1; ; i++)
	{
		if (n <= sum)
			break;
		else
		{
			steps++;
			sum = sum + 6 * i;
		}
	}

	cout << steps;
}