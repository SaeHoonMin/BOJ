#include <cstdio>
#include <vector>
#include <algorithm>
using namespace::std;
typedef struct Point { int x, y; }Point;


int comp(const Point & a, const Point & b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	else
		return a.x < b.x;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<Point> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &v[i].x, &v[i].y);
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", v[i].x, v[i].y);
}