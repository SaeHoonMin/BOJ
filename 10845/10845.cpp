#include <cstdio>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define CTOI(x) (x-'a')
using namespace::std;

/*
	0  1  2 3  4  5  6  7
	   
*/
#define QUESIZE 10001
typedef struct MyQueue {

	int arr[10001];
	int front;
	int back;
	int size;

	int Empty();
	int Front();
	int Back();
	int GetSize();
	void Push(int X);
	void Pop();
}MyQueue;

void initQueue(MyQueue& que)
{
	que.front = 0;
	que.back = 0;
	que.size = 0;
}

void MyQueue::Push(int x)
{
	int loc = back + 1 % QUESIZE;
	if (loc != front)
	{
		back = loc;
		arr[loc] = x;

		size++;
	}

}

void MyQueue::Pop()
{
	if (front != back)
	{
		printf("%d\n", arr[++front]);
		size--;
	}
	else
		printf("-1\n");
}

int MyQueue::GetSize()
{
	return size;
}

int MyQueue::Empty()
{
	if (GetSize()==0)
	{
		return 1;
	}
	else
		return 0;
}

int MyQueue::Front()
{
	if (size == 0)
		return -1;
	else
		return arr[front + 1];
}
int MyQueue::Back() {
	if (size == 0)
		return -1;
	else
		return arr[back];
}



int main()
{

	MyQueue que;
	initQueue(que);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		char str[30];
		scanf("%s", str);

		if (str[0] == 'p')
		{
			if (str[1] == 'u')
			{
				scanf("%d", &num);
				que.Push(num);
			}
			else
			{
				que.Pop();
			}
		}
		else if (str[0] == 's')
		{
			printf("%d\n", que.GetSize());
		}
		else if (str[0] == 'e')
		{
			printf("%d\n", que.Empty());
		}
		else if (str[0] == 'f')
		{
			printf("%d\n", que.Front());
		}
		else if (str[0] == 'b')
		{
			printf("%d\n", que.Back());
		}
	}

}