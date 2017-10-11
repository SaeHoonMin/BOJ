#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <algorithm>


using namespace::std;

vector<string> v(64);
string str;

int n;
int cnt = 0;

void makeQuad(int x, int y, int size)
{
	char c = v[x][y];
	bool flag = true;
	for (int i = x; i < x+size; i++)
	{
		for (int j = y; j < y+size; j++)
		{
			if (c != v[i][j])
			{
				flag = false;
				break;
			}
		}
	}

	if (flag == true)
		str.push_back(c);
	else
	{
		int half = size / 2;

		string arr[4];

		str.push_back('(');
		makeQuad(x, y, half);
		makeQuad(x, y + half, half);
		makeQuad(x + half, y, half);
		makeQuad(x + half, y + half, half);
		str.push_back(')');
	}



}

int main(void)
{
	/*
	
		1992 쿼드트리

		0, 1을 쿼드트리로 압축하여 출력
	
	*/

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	makeQuad(0,0,n);

	cout << str;
	

}