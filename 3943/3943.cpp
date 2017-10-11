#include <cstdio>
#include <iostream>
using namespace::std;
void process(int n);
int main(void)
{
	int n;
	int k; 
	cin>>n;
	for(int i = 0;i < n; i++)
	{
		scanf("%d",&k);
		process(k);
	}
}
void process(int n)
{
	int max = n;
	
	while ( n != 1)
	{
		if( n %2 == 0)
		{
			n >>=1;
		}
		else
		{
			n = n*3 +1;	
		}
		
		if( n > max ) 
			max = n;
	}
	cout<<max<<"\n";
}