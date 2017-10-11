#include<stdio.h>
int main()
{
	
	int a, b, n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",a*b/gcd(a,b));
	}
}


int gcd(int a, int b)
{
	int t;
	while(b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}