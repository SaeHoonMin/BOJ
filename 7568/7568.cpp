#include <iostream>
#include <cstdio>
#include <vector>

using namespace::std;

int n;
int main(void)
{
	cin >> n;

	vector < std::pair<int, int> > v(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		ans[i] = 1;
		for (int j = 0; j < n; j++)
		{
			if (i != j &&
				v[i].first < v[j].first &&
				v[i].second < v[j].second)
				ans[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}