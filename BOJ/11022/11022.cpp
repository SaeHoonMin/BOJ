#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace::std;
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i + 1, a, b, a + b);
	}
}
	
