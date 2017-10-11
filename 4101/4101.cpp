#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <list>
#include <vector>

#define PAIR  std::pair<int,int> 

using namespace::std;

int main(void)
{
	/**
	4101 크냐?
	*/

	int a, b;
	while (true)
	{
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		cout <<((a>b)?"Yes":"No") << "\n";
	}


	return 0;
}