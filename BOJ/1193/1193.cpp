#include <iostream>
#include <stdlib.h>
using namespace std;

struct rNumber
{
	int a,b;
};
int main()
{
	int n;

	cin>>n;

	int i=1;
	int b= 1;
	int k= 1;
	while(1)
	{
		if(i==1 && n==i)
			break;
		else
		{
			k++;
			i=b+1;
			b+=k;
			
			if(n<=b && n>=i)
			{
				break;
			}
		}
	}
	
	rNumber ** rN;
	rN = (rNumber **)malloc(sizeof(rNumber*)*k);
	for(int i=0;i<k;i++)
	{
		rN[i] = (rNumber*)malloc(sizeof(rNumber)*k);
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			rN[i][j].a=i+1;
			rN[i][j].b=j+1;
		}
	}

	int z, x,c;
	z=0;x=0;c=1;
	int flag=0;
	while(1)
	{
		if(c==n)
		{
			cout<<rN[z][x].a<<"/"<<rN[z][x].b;
			break;
		}

		if(flag==0)
		{
			if(z-1<0)
			{
				x++;
				c++;
				flag=1;
			}
			else
			{
				z--;
				x++;
				c++;
			}
		}
		else
		{
			if(x-1<0)
			{
				z++;
				c++;
				flag=0;
			}
			else
			{
				z++;
				x--;
				c++;
			}
		}
	}
}