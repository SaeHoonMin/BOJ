#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string s1;
	string s2;
	int * a;
	int * b;
	cin>>s1>>s2;
	int c= (s1.length() >=s2.length())? s1.length() : s2.length();
	a= new int[c+1];
	b= new int[c+1];
	for(int i=0;i<c+1;i++)
	{
		a[i]=0;
		b[i]=0;
	}
	int j=0;
	for(int i=s1.length()-1;i>=0;i--)
	{
		a[j]=s1[i]-48; j++;
	}
	j=0;
	for(int i=s2.length()-1;i>=0;i--)
	{
		b[j]=s2[i]-48; j++;
	}
	for(int i=0;i<c;i++)
	{
		if(a[i]+b[i]>9)
		{
			a[i+1]+=1;
			a[i]= (a[i]+b[i]-10);
		}
		else
			a[i]+=b[i];
	}

	for(int i=c;i>=0;i--)
	{
		if(i==c && a[i]==0)
			continue;
		cout<<a[i];
	}
}