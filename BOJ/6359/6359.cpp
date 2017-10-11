#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <string.h>


using namespace::std;
int dp[101];

int main(void)
{
	/*
		6359 : 만취한 상범

		0	   : 모든 문 close상태
		1라운드 : 모든 문 open
		2라운드 : 2, 4, 6,,,.close
		3라운드 : 3, 6, 9 ,,... close ( close 면 open )

		n번째 문이 마지막에 열려있으려면?

		1rd -> open, 2rd->close , 3rd -> open이려면
		    1 : open, -> 영구 open
		ex) 2 : open, 2rd close, ->영원히 close
		ex) 3 : open, 3rd close, -> 영원히 close
		ex) 4 : open, 2rd에 close, 4rd에 open
		    5 : ..
			9 : open, 3rd close, 4rd open

		완전제곱수면 nth 수는 nth라운드에 살아있음
	*/ 

	int t;
	cin >> t;

	vector<int> answers;
	for (int i = 1; i*i <= 100; i++)
	{
		answers.push_back(i*i);
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		int ans = 0;
		cin >> n;

		for (int j = 0; j < answers.size(); j++)
		{
			if (answers[j] <= n)
				ans++;
		}
		cout << ans << endl;
	}


}