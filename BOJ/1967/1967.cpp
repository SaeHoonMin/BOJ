#include <cstdio>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
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
		return val;		//기저 : 계산된 길이 리턴

	if (val == 0)
	{
		//처음 진입 시 차수가 일정치 않으므로 foreach (nextNode)에 대해 process 함수 재귀 호출

		vector<int> values;

		for (int i = 0; i < nod.nextIdx.size(); i++)
		{
			values.push_back(process(tree[nod.nextIdx[i]], val + nod.values[i]));
		}
		sort(values.begin(), values.end());

		//우선 가장 길게 이어진 자식 줄기를 고르고, 차수가 1일수도 있으므로 판별하여 다음으로 긴
		// 자식 줄기 골라서 리턴하도록..

		int sum = 0;
		sum += values.at(values.size() - 1);
		if ((int)values.size() - 2 >= 0)
			sum += values.at(values.size() - 2);

		return  sum;
	}
	else
	{
		//중간 단계 에서는 그냥 foreach(연결된노드) 에 대해 재귀호출하고 가장긴것만 리턴해주면 됨
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

	cin >> n;

	node nod;
	tree.reserve(n + 1);

	for (int i = 0;i <= n; i++)
	{
		tree.push_back(nod);
	}

	for (int i = 1; i <= n - 1; i++)
	{
		int a, b, val;
		scanf("%d %d %d", &a, &b, &val);

		tree[a].nextIdx.push_back(b);
		tree[a].values.push_back(val);

	}

	int maxVal = 0;

	/*
		무식한 방법으로 모든 n개의 노드들에 대해 자식노드들 탐색하도록 했는데..

		트리 지름 구하는 방법 찾아보니 루트에서 가장 멀리있는거 하나만 찾은다음
		그 노드에서 가장 멀리있는거 하나 찾으면 되는 것으로 보임..->1167번은
		input이 100000개이므로 해당 문제에 도전 해보자..
	*/

	for (int i = 1; i <= n; i++)
	{
		int retVal = process(tree[i], 0);
		if (retVal > maxVal)
			maxVal = retVal;
	}




	cout << maxVal;
}