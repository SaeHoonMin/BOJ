#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace::std;


int n, m;

int main()
{
	/*

	1092: 배

	무게제한이 있는 n대의 크레인으로
	m개의 각각 특정 무게를 갖는 박스  옮기는 최소시간

	어떤 박스 x가 몇 번째 크레인에 들어가면 적절한지 계산

	예시)
	크레인 번호   1          2         3
	크레인 중량   3          10        15
	박스 무게    (1,1,1,2)   (4,7,9)  (13,14)

	매일 각각의 크레인에서 하나씩 줄이고,
	줄일게 없는 경우 자기보다 가벼운 크레인 할당량에서 하나 줄이기
	*/
	int n, m, b;
	scanf("%d", &n);
	vector<int> crain(n);
	for (int i = 0;i < n; i++)
	{
		scanf("%d", &crain[i]);
	}
	sort(crain.begin(), crain.end());

	scanf("%d", &m);
	vector<int> box(n);
	for (int i = 0;i < m; i++)
	{
		scanf("%d", &b);
		int j = 0;
		for (; j < n; j++)
		{
			if (b <= crain[j])
			{
				box[j]++; break;
			}
		}
		if (j == n) 	//다 옮길수 없는 경우
		{
			cout << -1;
			return 0;
		}
	}



	int days = 0;

	while (m)
	{
		for (int i = 0; i < n; i++)
		{
			if (box[i])
			{
				box[i]--;
				m--;
			}
			else
			{
				int j = 0;
				for (j = i - 1; j >= 0; j--)
				{
					if (box[j]) break;
				}
				if (j >= 0)
				{
					box[j]--;
					m--;
				}
			}
		}
		days++;
	}


	cout << days;

	return 0;
}