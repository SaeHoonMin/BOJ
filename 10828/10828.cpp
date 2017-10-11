#include <iostream>
#include <string>
using namespace::std;

const string PUSH = "push";
const string POP = "pop";
const string TOP = "top";
const string SIZE = "size";
const string EMPTY = "empty";

typedef struct DataNode
{
	DataNode * next;
	int val;
}DataNode_t;

class MyStack
{
private:
	DataNode * head;
	int topVal;
public:
	MyStack();
	MyStack(unsigned int reserveSize);
	int isEmpty();
	int size();
	int top();
	void push(int x);
	int pop();
};

MyStack::MyStack()
{
	topVal = -1;
}

MyStack::MyStack(unsigned int reserveSize)
	: MyStack()
{
	for (int i = 0; i < reserveSize; i++)
	{
		// todo : create element
	}
}

int MyStack::isEmpty()
{
	if (topVal == -1)
		return 1;
	else
		return 0;
}

int MyStack::top()
{
	int retVal = -1;

	if (!isEmpty())
		retVal = head->val;

	return retVal;
}

int MyStack::size()
{
	if (this->isEmpty())
		return 0;
	else
		return topVal + 1;
}

void MyStack::push(int x)
{
	DataNode * newNode = new DataNode;

	newNode->next = NULL;
	newNode->val = x;

	// topval == -1
	if (topVal == -1)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	topVal++;
}
int MyStack::pop()
{
	
	int retVal = -1;
	if (!isEmpty())
	{
		retVal = head->val;

		if (topVal == 0) //원소가 한개 남았으면
		{
			delete head;
			head = NULL;
		}
		else
		{
			DataNode* temp = head->next;
			delete head;
			head = temp;
		}
		topVal--;
	}


	return retVal;
}

int main(void)
{
	int command;
	cin >> command;

	int number;
	string str;

	MyStack stack;

	for (int i = 0; i < command; i++)
	{
		cin >> str;
		if (str.compare(PUSH) == 0)
		{
			// push
			cin >> number;
			stack.push(number);
		}
		else if (str.compare(POP) == 0)
		{
			cout << stack.pop() << "\n";
		}
		else if (str.compare(SIZE) == 0)
		{
			// 스택에 들어 있는 정수 개수 출력
			cout << stack.size() << "\n";
		}
		else if (str.compare(EMPTY) == 0)
		{
			// 비어있으면 1 아니면 0
			cout << stack.isEmpty() << "\n";
		}
		else if (str.compare(TOP) == 0)
		{
			// 가장 위에 있는 정수 출력. 없으면 -1
			cout << stack.top() << "\n";
		}
	}

	return 0;
}