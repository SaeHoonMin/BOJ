#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;
using namespace::std;

typedef struct _arrWindex
{
	int index;
	int number;
}arrWindex;

arrWindex * reArrange(int * arr1, int * arr2, int length);


int main()
{
	int array_length;
	int * arr1;
	int * arr2;
	arrWindex * mArrWindex;

	int i=0;

	cin>>array_length;

	arr1 = new int[array_length];
	arr2 = new int[array_length];
	mArrWindex = new arrWindex[array_length];
	
	while(cin>>arr1[i] )
	{
		i++;
		if(i>=array_length)
			break;
	}
	i=0;
	//fflush(stdin);
	while(cin>>arr2[i] )
	{
		i++;
		if(i>=array_length)
			break;
	}

	mArrWindex = reArrange(arr1,arr2,array_length);

	//show results.
	int result=0;
	for(int i=0; i<array_length;i++)
	{
		result += mArrWindex[i].number * arr2[(mArrWindex[i].index)];
	}
	cout<<result;
}

arrWindex * reArrange(int * arr1, int * arr2, int length)
{
	arrWindex * arrWindex1= new arrWindex[length];
	arrWindex * arrWindex2 = new arrWindex[length];

	int min;
	int minindex;
	int max;
	int maxindex;
	arrWindex  temp;


	for(int i=0;i<length;i++)
	{
		arrWindex1[i].index=i;
		arrWindex1[i].number=arr1[i];
		arrWindex2[i].index=i;
		arrWindex2[i].number=arr2[i];
	}



	//arr1을 오름차순 정렬하면서 인덱스도 저장

	for(int i = 0 ; i<length ; i++)
	{
		min = arrWindex1[i].number;
		minindex = i;

		for(int j = i; j < length-1; j++)
		{		
			if( arrWindex1[j+1].number <= min )
			{
				min = arrWindex1[j+1].number;
				minindex = j+1;
			}
		}

		temp = arrWindex1[i];
		arrWindex1[i] = arrWindex1[minindex];
		arrWindex1[minindex]=temp;
	}

	//cout<<endl<<"arrWindex1's info"<<endl;
	//for(int i=0; i<length;i++)
	//{
	//	cout<<"("<<arrWindex1[i].number<<","<<arrWindex1[i].index<<")";
	//}

	//arr2를 내림차순 정렬하면서 인덱스도 저장
	for(int i = 0 ; i<length ; i++)
	{
		max = arrWindex2[i].number;
		maxindex = i;
		for(int j = i; j < length-1; j++)
		{		
			if( arrWindex2[j+1].number >= max )
			{
				max = arrWindex2[j+1].number;
				maxindex = j+1;
			}
		}
		temp = arrWindex2[i];
		arrWindex2[i] = arrWindex2[maxindex];
		arrWindex2[maxindex]=temp;
	}

	//cout<<endl<<"arrWindex2's info"<<endl;
	//for(int i=0; i<length;i++)
	//{
	//	cout<<"("<<arrWindex2[i].number<<","<<arrWindex2[i].index<<")";
	//}
	//cout<<endl;

	for(int i =0; i<length;i++)
	{
		arrWindex1[i].index = arrWindex2[i].index;
	}
	return arrWindex1;
}