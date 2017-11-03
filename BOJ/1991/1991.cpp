#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>

using namespace::std;

typedef struct Node {
	char Name;
	Node * left;
	Node * right;
};


vector<Node *> treeMap(255);


void preorder(Node * node)
{
	printf("%c", node->Name);
	if (node->left)
		preorder(node->left);
	if (node->right)
		preorder(node->right);

}

void inorder(Node * node)
{
	if (node->left)
		inorder(node->left);
	printf("%c", node->Name);
	if (node->right)
		inorder(node->right);
}

void postorder(Node * node)
{
	if (node->left)
		postorder(node->left);
	if (node->right)
		postorder(node->right);
	printf("%c", node->Name);
}

int main(void)
{
	/*
		1991 트리 순회
	*/
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
	
		Node *n;
		if (treeMap[a] == NULL)
		{
			n = new Node();
			n->Name = a;
			treeMap[a] = n;
		}
		else
			n = treeMap[a];
		
		if (b != '.')
		{
			n->left = new Node();
			n->left->Name = b;
			treeMap[b] = n->left;
		}
		if (c != '.')
		{
			n->right = new Node();
			n->right->Name = c;
			treeMap[c] = n->right;
		}
	}

	preorder(treeMap['A']); printf("\n");
	inorder(treeMap['A']); printf("\n");
	postorder(treeMap['A']); printf("\n");
	
	return 0;
}