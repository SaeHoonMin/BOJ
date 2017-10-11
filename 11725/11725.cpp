#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace::std;

typedef struct TreeNode{
	vector<int> next;
}TreeNode;

int answer[100001];

int main(void)
{

	/*

	11725 : 트리의 부모 찾기
		    그냥 노드 간 연결된 노드정보들 중복구성 한 다음,
			1번 노드부터 순회하면서 중복노드번호는 접근 안하게 하면 됨..

	*/

	int n;
	queue<int> que;
	cin >> n;
	vector<TreeNode> tree(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		//간선정보 중복 구성
		tree[a].next.push_back(b);
		tree[b].next.push_back(a);

		answer[i + 1] = 0;
	}
	
	que.push(1);
	while (!que.empty())
	{
		// BFS
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			int jsize = tree[que.front()].next.size();
			for (int j = 0; j < jsize; j++)
			{
				int idx = tree[que.front()].next[j];
				if (idx != 1 && answer[idx] == 0)
				{
					answer[idx] = que.front();
					que.push(idx);
				}
			}
			que.pop();
		}
	}

	for (int i = 2; i <= n; i++)
	{
		printf("%d\n", answer[i]);
	}
}