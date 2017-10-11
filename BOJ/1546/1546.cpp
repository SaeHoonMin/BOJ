#include <iostream>
#include <stdio.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	int m;
	int * score;
	double sum=0;
	cin>>n;
	score = new int[n];
	for(int i=0; i<n;i++)
	{
		cin>>score[i];
	}
	m=score[0];
	for(int i=0;i<n;i++)
	{
		if(score[i]>m)
			m=score[i];
	}
	for(int i=0;i<n;i++)
	{
		sum += (double)score[i]/m*100;
	}
	printf("%.2lf",sum/n);
}