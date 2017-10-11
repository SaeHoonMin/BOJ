#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace::std;

typedef struct Node{
	Node * next;
int val;
}Node;

typedef struct List {
	Node * head;
	Node * tail;
}List;

List l;

void MakeList(int n)
{
	Node* node;
	Node* b = NULL;
	for (int i = 0;i < n; i++)
	{
		node = new Node();

		if (i == 0)
			l.head = node;
		else
			b->next = node;
		
		node->val = i + 1;
		b = node;
	}
	b->next = l.head;
	l.tail = b;
}


int main(void)
{

	/*

	1158 : 조세퍼스 문제
	<7, 3> -> <3,6,2,7,5,1,4>

	loc % arr.size()

	*/

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);

	MakeList(n);


	Node * node = l.head;
	Node * b = l.tail;
	printf("<");
	for (int i = 0;i < n; i++)
	{
		int  j = 0;
		if (i == 0)
			j++;

		for (; j < m; j++)
		{
			b = node;
			node = node->next;
		}
		b->next = node->next;
		printf("%d", node->val);
		if (i + 1 < n)
			printf(", ");
	}
	printf(">");
}