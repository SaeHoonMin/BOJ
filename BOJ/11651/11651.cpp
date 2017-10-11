#include <cstdio>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define CTOI(x) (x-'a')
using namespace::std;


typedef struct Point {
	int a, b;
}Point;
int myfunc(Point&A, Point&B)
{
	if (A.b == B.b)
		return A.a < B.a;
	else
		return A.b < B.b;
}

int main()
{

	int n;
	cin >> n;
	vector<Point> arr(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i].a, &arr[i].b);
	}
	sort(arr.begin(), arr.end(), myfunc);

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", arr[i].a, arr[i].b);
	}


}