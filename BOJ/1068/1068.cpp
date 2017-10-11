#include <cstdio>
#include <queue>

#include <iostream>
using namespace::std;

typedef struct TreeNode
{
	vector<int> next;
}TreeNode;

int n, k, head;
vector<TreeNode> tree(50);

int answer(int idx)
{
	int sum = 0;

	if (idx == k)
		return 0;
	if (tree[idx].next.size() == 0)
		return 1;

	for (int i = 0; i < tree[idx].next.size(); i++)
	{
			sum+= answer(tree[idx].next[i]);
	}
	
	if ( idx!=head && sum == 0)
		return 1;	// 리프노드가 없으면 내가 리프노드다.
	return sum;
}


int main(void)
{
	/*
		1068:트리
		어떤 노드 k를 지웠을때 리프노드의 개수?

	*/
	cin >> n;
	int a;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a == -1)
			head = i;
		else
			tree[a].next.push_back(i);
		
	}
	cin >> k;

	cout << answer(head);


	return 0;
}