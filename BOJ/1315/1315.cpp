#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
using namespace::std;


int PNT[101];
int STR[101];
int INT[101];
int visited[101];
int dp[1001][1001];
int q;

int solve(int _str, int _int, int clear)
{
	if (dp[_str][_int]!=-1)
	{
		return dp[_str][_int];
	}

	int pnt = 0;
	int cnt = 0;
	int temp[101];
	memcpy(temp, visited, sizeof(temp));

	for (int i = 0; i < q; i++)
	{
		if (!visited[i] && (STR[i] <= _str || INT[i] <= _int))
		{
			pnt += PNT[i];
			cnt++;
			visited[i] = 1;
		}
	}

	clear += cnt;

	//더 깰게 있으면 현재 포인트로 할수 있는 투자 전부 해보기
	dp[_str][_int] = clear;
	for (int i = _str; i <= min(1000, _str+pnt); i++)
	{
		int j = min(1000, _int + pnt - (i - _str));
		dp[_str][_int] = max(dp[_str][_int], 
							solve( i,j, clear));
	}


	memcpy(visited, temp, sizeof(temp));
	return dp[_str][_int];

}

int main(void)
{
	/*
		1315 : RPG

		: 시작 -> 힘 지능 각각 1 1이므로 여기서 진입

		dp[i][j] = i힘과 j지능으로 깰수있는 퀘스트 최대 수
		힘, 지능 최대치는 각각 1000

		
		1) 현재 힘 지능으로 깰수있는 퀘스트 다 깬다음 포인트 모은다
		2) p, p-i  로 현재 포인트로 투자할수 있는 경우의 수 만큼 dfs
		3) dp[1][1]이 답

		주의점 : 이미 깬 것은 다시 못깨니까 visited로 표시 해줘야 함,
		       depth 들어가기 전에 체크 하고, depth 빠져나올 때 복원 해줘야 함

			   기저는 현재 포인트로 깰 게 없는 경우 혹은 dp[i][j]에 답이 기록된 경우.
	*/

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d %d", &STR[i], &INT[i], &PNT[i]);
	}

	memset(dp, -1, sizeof(dp));

	solve(1, 1, 0);

	cout << dp[1][1];
	
	return 0;
}