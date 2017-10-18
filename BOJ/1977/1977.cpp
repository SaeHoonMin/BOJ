#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace::std;


int main(void)
{
	/*

	1977: 완전제곱수
	m이상 n이하 자연수 중 완전제곱수 찾아 합 / 최소값 출력
	
	..그냥 쉬어가는 코너..

	*/
	int sum = 0;
	int low = 99999;
	int m, n;
	cin >> m >> n;
	for (int i = 1; i*i <= n; i++)
	{
		int num = i * i;
		if (num >= m && num <= n)
		{
			if (low == 99999)
				low = num;
			sum += num;
		}
	}


	//합 최소값 출력
	if (sum == 0)
		cout << "-1";
	else
	{
		printf("%d\n%d", sum, low);
	}
	return 0;
}