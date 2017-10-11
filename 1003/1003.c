#include <stdio.h>
#include <stdlib.h>

int zeroCount;
int oneCount;

int fibonacci(int n) {
    if (n==0) {
		zeroCount++;
        return 0;
    } else if (n==1) {
		oneCount++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

typedef struct _result
{
	int zc;
	int oc;
}result;


int main(void)
{
	int testCase;
	int tc_Count;
	int N;
	result * rp;

	scanf("%d",&testCase);

	rp= (result*)malloc(sizeof(result)*testCase);

	for(tc_Count=0;tc_Count<testCase;tc_Count++)
	{
		scanf("%d",&N);
		zeroCount=0;
		oneCount=0;
		fibonacci(N);
		rp[tc_Count].oc=oneCount;
		rp[tc_Count].zc=zeroCount;
	}

	for(tc_Count=0;tc_Count<testCase;tc_Count++)
	{
		fflush(stdout);
		printf("%d %d\n",rp[tc_Count].zc,rp[tc_Count].oc);
	}
}