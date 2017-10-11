#include <iostream>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace::std;

int dir[4][2] = {
	{1, 0},	//UP
	{-1,0}, //DOWN
	{0, -1}, //LEFT
	{0, 1}, //RIGHT
};

long long int ** dp;
bool ** visited;
int ** arr;
int m, n;


int glob;

void clearVisited()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}

int process(int i, int j)
{
	if (i == m - 1 && j == n - 1)
		return 1;
	if (visited[i][j])
		return dp[i][j];

	visited[i][j] = true;
	int a, b;
	int ret = 0;
	for (int x = 0; x < 4; x++)
	{
		a = i + dir[x][0];
		b = j + dir[x][1];
		if (a >= 0 && b >= 0 &&
			a < m && b < n &&
			arr[a][b] < arr[i][j])
			ret += process(a, b);

	}

	//cout << "********" << glob++ << "*************" << endl;
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return dp[i][j] = ret;

}


int main(void)
{

	cin >> m >> n;

	arr = new int *[m];
	dp = new long long int*[m];
	visited = new bool *[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
		dp[i] = new long long int[n];
		visited[i] = new bool [n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = 0;
		}
	}
	clearVisited();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	process(0, 0);

	cout << dp[0][0];
}