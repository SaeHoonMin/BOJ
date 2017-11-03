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
int n, maxd, maxval=-9999;
bool visited[100001];

void process(node & nod, int val, int idx)
{
	//진입점 -> 방문 체크
	visited[idx] = 1;

	bool isLeaf = true;
	for (int i = 0; i < nod.nextIdx.size(); i++)
	{
		if (visited[nod.nextIdx[i]] != 1)
		{
			process(tree[nod.nextIdx[i]], val + nod.values[i], nod.nextIdx[i]);
			isLeaf = false;
		}
	}

	visited[idx] = 0;

	//리프 노드이면 방문한 게 없으므로
	if ( isLeaf )
	{
		if (val > maxval)
		{
			maxval = val;
			maxd = idx;
		}
		return;
	}

}

int main()
{

	/*
	1167 : 트리의 지름

	1967을 내가 풀엇을땐 n^2으로 풀었으므로 이 문제에서
    그렇게 풀면 10만^10만 으로 시간초과가 날 것임.
	그래서 트리 지름 구하는 알고리즘을 보니..


	1) 임의의 노드 a를 구한다
	2) 노드 a에서 제일 먼 노드 b와 그 거리를 구한다
	3) b에서 제일 먼 노드를 다시 구하면 정답

	*/

	cin >> n;

	node nod;
	tree.reserve(n + 1);

	for (int i = 0;i <= n; i++)
	{
		tree.push_back(nod);
	}

	for (int i = 1; i <= n; i++)
	{
		int a, b, val;
		scanf("%d", &a);
		while (true)
		{
			scanf("%d", &b);
			if (b == -1)break;

			scanf("%d", &val);

			tree[a].nextIdx.push_back(b);
			tree[a].values.push_back(val);
		}
	}

	process(tree[1], 0, 1);
	maxval = -999;
	process(tree[maxd], 0, maxd);

	cout << maxval;
}