#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <math.h>
using namespace::std;

int arr[1000000];

int main()
{
	/*

	13458 : 시험 감독

	N개의 시험장, n번째 시험장의 응시생 수 : A(n)명

	총감독은 각 시험장에 단 1명만 존재해야 함
	부감독관은 C명 감시 가능, 여러명 있어도 됨.

	응시생 모두 감시하기 위한 감독관 수 최소값?

	*/

	int n, B, C;
	scanf("%d", &n);
	long long int ans = n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);
	for (int i = 0; i < n; i++)
	{
		int A = arr[i] - B;
		if( A>0 )
		ans += ceil((double)A / C);
	}

	cout << ans;

	return 0;
}