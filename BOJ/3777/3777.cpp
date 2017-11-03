#include <cstdio>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace::std;



class MyBigNumber {

	
public:
	vector<char> arr;
	//본 문제에선 1 더하거나 빼기 뿐이므로
	MyBigNumber() {};
	MyBigNumber(int i);
	MyBigNumber operator+( int i);
	MyBigNumber operator-( int i);
	//본 문제에선 2 곱하는거 뿐이므로
	MyBigNumber operator*( int i);
	MyBigNumber& operator=( MyBigNumber my);
	MyBigNumber& operator=(int i);
	string toString();
};

MyBigNumber& MyBigNumber::operator=(int i)
{
	//본 문제에선 1자리 수로 초기화할꺼니까
	arr.push_back(i);

	return *this;
}

MyBigNumber& MyBigNumber::operator=(MyBigNumber my)
{
	arr = my.arr;

	return *this;
}

//본 문제에선 1 더하거나 빼기 뿐이므로
MyBigNumber MyBigNumber::operator+(int i)
{
	MyBigNumber retVal;
	char carry = 0;
	char num = arr[0] + i;
	retVal.arr.push_back(num % 10);
	carry = num / 10;
	for (int j = 1; j < arr.size(); j++)
	{

		num = carry+arr[j];

		retVal.arr.push_back( num % 10 );
		carry = num / 10;
	}
	if (carry)
		retVal.arr.push_back(carry);

	return retVal;
}
MyBigNumber MyBigNumber::operator-( int i)
{
	MyBigNumber retVal;
	char carry = 0;

	char num = arr[0] - i;
	if (num < 0)
	{
		carry = 1;
		num = arr[0] + 10 - i;
		
	}
	retVal.arr.push_back(num);

	for (int j = 1; j < arr.size(); j++)
	{
		int num = arr[j];;
		if (carry)
		{
			if (arr[j] == 0)
			{
				carry = 1;
				arr[j] = 9;
			}
		
			num = arr[j] - carry;
			
		}
		retVal.arr.push_back(num);
	}
		
	return retVal;
}

//본 문제에선 2 곱하는거 뿐이므로
MyBigNumber MyBigNumber::operator*(int i)
{
	MyBigNumber retVal;
	char carry = 0;
	for (int j = 0; j < arr.size(); j++)
	{
		char num = arr[j] * i;
		num += carry;

		retVal.arr.push_back(num % 10);
		carry = num / 10;
	}
	if (carry)
		retVal.arr.push_back(carry);

	return retVal;
}

string 	MyBigNumber::toString()
{
	string str;

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		printf("%c",arr[i] + '0');
	}
	printf("\n");
	return str;
}


MyBigNumber dp[1001];

int main()
{

	/*
	
	3777 : Computer Transformation

	* 0 -> 10    1-> 01

	매번 크기가 2배이므로 브루트포스로 하면 2^1000...

	steps 
	0		1										0
	1		1    ->   0 1							1
	2		0 1  -> 1 0 0 1						    1        
	3		 01    1010    01					    1		 
	4		1001    01100110       1001				3		 
	5	 01101001 1001011010011001 01101001		    5		 

	how many pairs of consecutive zeroes will appear ?

	잘 감이 안오는데 규칙성이 있어보이므로 브루트포스로 10까지 구해보면..

	 1 2 3 4 5 6 
	 0 1 1 3 5 11 21 43 85 171
	 n-1 *2 +1 or n-1 *2 -1 형태임을 알 수 있다...

	 다시 말해 홀수면 dp[n-1]*2 -1
	 짝수면 dp[n-1]*2+1 

	 근데 long long int 범위 넘어감..하

	*/


	//string s = "1";
	//for (int j = 0; j < 10; j++)
	//{
	//	string newstr;
	//	for (int i = 0; i < s.size(); i++)
	//	{
	//		if (s[i] == '1')
	//		{
	//			newstr.push_back('0');
	//			newstr.push_back('1');
	//		}
	//		else
	//		{
	//			newstr.push_back('1');
	//			newstr.push_back('0');
	//		}
	//	}
	//	s = newstr;

	int n; 


	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;


	for (int i = 4; i <= 1000; i++)
	{
		if (i & 1)
		{
			dp[i] = dp[i - 1] * 2 - 1;
		}
		else
			dp[i] = dp[i - 1] * 2 + 1;
	}
	while (scanf("%d", &n) == 1)
	{
		dp[n].toString();
	}
	
}