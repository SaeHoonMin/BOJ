#include <iostream>
#include <stdio.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int x,y,w,h;
	cin>>x>>y>>w>>h;
	int a = (x<w-x)? x : w-x;
	int b= (y<h-y)? y : h-y;
	if(a==b || a<b)
		cout<<a;
	else if(a>b)
		cout<<b;
}