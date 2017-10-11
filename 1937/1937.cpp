#include<iostream>
#include<cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INT_MAX       2147483647    
using namespace::std;

int dp[500][500];
int arr[500][500];
int dj[] = { 0,1,0,-1 };
int di[] = { 1,0,-1,0 };
int ans = -1;
int n;

int calc(int i, int j)
{

	if (dp[i][j] != 0)
	{
		return dp[i][j];
	}

	dp[i][j] = 1;
	for (int k = 0; k < 4; k++)
	{
		int mj = dj[k] + j;
		int mi = di[k] + i;

		if (mj < 0 || mi < 0 || mi >= n || mj >= n)
			continue;
		if (arr[mi][mj] <= arr[i][j])
			continue;

		dp[i][j] = max(dp[i][j], calc(mi, mj) +1 );
	}

	return dp[i][j] ;
		
}

void process()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			calc(i, j);

			if (dp[i][j] > ans)
				ans = dp[i][j];

		}
	}
}


int main(void)
{
	 /*
		1937 : 욕심쟁이 판다

		n*n 대나무숲에서  항상 다음위치는 지금보다 많은 양의 대나무로만 이동
		최대 생존일수 ?

		n <= 500;

		완전탐색 : 
		  대략 500^4 = 625억 이상.

		1  to n
		2n .. n+1 
		  
		dp[i][j]에 저장해놓으면..

		calc  :  arr[i][j]로 시작할  때 최대 경로 길이 반환

		dp[i][j] = max( calc(i-1,j), calc(i,j-1), calc(i+1,j),calc(

		-> 이렇게 해도 시간 초과임.. 왜? -> 중복계산 때문...
		-> 중복계산 없앨 수도 없음.
		-> 재귀호출 설계가 잘못됨..

		calc()
		calc()
		calc()
		calc()
		dp[i][j] = x
        return dp[i][j] 가 아니라

		for(int i =0; i<4; i++)
		   calc()
		   dp[i][j] = max(dp[i][j] , calc())
		return dp[i][j] 가 되야함
		
	*/
	cin >> n;


	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
        for(int j = 0; j<n; j++)
		scanf("%d", &arr[i][j]);
	}


	process();

	cout << ans;

	return 0;
}