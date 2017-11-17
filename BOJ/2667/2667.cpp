#include <string>
#include "iostream"
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace::std;

bool visited[25][25];
int arr[25][25];
int x[] = { 0,1,0,-1 };
int y[] = { 1,0,-1,0 };

#define point std::pair<int, int> 

int main()
{
	/**
		2667 : 단지번호붙이기
		simple bfs
	*/
	int n;
	cin >> n;
	for (int i = 0;i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	vector<int>  complex;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (arr[i][j] == 1 && !visited[i][j])
			{
				int count = 0;
				queue< point > que;
				que.push(point(i, j));
				visited[i][j] = 1;
				while (!que.empty())
				{
					int size = que.size();
					for (int k = 0; k < size; k++)
					{
						point p = que.front();

						count++;
						
						for (int l = 0; l < 4; l++)
						{
							int dy = p.first + y[l];
							int dx = p.second + x[l];
							
							if (dy >= 0 && dy < n && dx >= 0 && dx < n
								&& !visited[dy][dx] && arr[dy][dx] ==1 )
							{
								visited[dy][dx] = 1;
								que.push(point(dy, dx));
							}
						}
						que.pop();
					}
				}

				complex.push_back(count);
			}
		}
	}
	sort(complex.begin(), complex.end());
	int cs = complex.size();
	printf("%d\n", cs);
	for (int i = 0; i < cs; i++)
	{
		printf("%d\n", complex[i]);
	}
    return 0;
}

