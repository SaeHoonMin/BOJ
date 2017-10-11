#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int K,tempb;
	int a=1;
	int b=0;
	cin>>K;
	for(int i=0;i<K;i++)
	{
		tempb =b;
		b+=a;
		a=0;
		a+=tempb;
	}
	cout<<a<<" "<<b;
}