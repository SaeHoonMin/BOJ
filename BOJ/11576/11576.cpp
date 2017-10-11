#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace::std;



int main(void)
{

	/*

	11576 : Base Conversion

	*/
	int dnum = 0;
	int a, b, k, n;
	cin >> a >> b >> k;
	for (int i = k - 1; i >= 0; i--)
	{
		scanf("%d", &n);
		dnum += n * pow(a,i);
	}
	vector<int> ans;
	while (true)
	{

		ans.push_back(dnum % b);
		dnum = dnum / b;
		if (dnum < b)
		{
			ans.push_back( dnum );
			break;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		printf("%d", ans[i]);
		if (i != 0)
			printf(" ");
	}


}