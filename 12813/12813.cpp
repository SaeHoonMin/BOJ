#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>

#define INT_MAX 2147483647
#define DIVIDER 1000000000
using namespace::std;

class BitStream
{
public:
	string str;
	BitStream() {};
	BitStream Not();
	BitStream And(BitStream & B);
	BitStream Or(BitStream & B);
	BitStream Xor(BitStream & B);
	
	friend ostream & operator <<(ostream &, const BitStream &);
};

ostream &operator <<(ostream & out, const BitStream& str)
{
	out << str.str<<"\n";
	return out;
}

BitStream BitStream::Not()
{
	BitStream b;
	for (int i = 0; i < str.length(); i++)
		b.str.push_back( str[i] == '1' ? '0' : '1' );
	return b;
}
BitStream BitStream::And(BitStream & B)
{
	BitStream ret;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '1' && B.str[i] == '1')
			ret.str.push_back('1');
		else
			ret.str.push_back('0');
	}

	return ret;
}

BitStream BitStream::Or(BitStream & B)
{
	BitStream ret;

	for (int i = 0; i < str.length(); i++)
	{
		if ( (str[i] == '1' && B.str[i] == '1') ||
			(str[i] == '0' && B.str[i] == '1') ||
			(str[i] == '1' && B.str[i] == '0'))
			ret.str.push_back('1');
		else
			ret.str.push_back('0');
	}

	return ret;
}

BitStream BitStream::Xor(BitStream & B)
{
	BitStream ret;

	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] == '0' && B.str[i] == '1') ||
			(str[i] == '1' && B.str[i] == '0'))
			ret.str.push_back('1');
		else if( (str[i] == '1' && B.str[i] == '1') || 
			     (str[i] == '0' && B.str[i] == '0') )
			ret.str.push_back('0');
	}

	return ret;
}


int main(void)
{
	/**
	12813 : 이진수 연산

	A & B, 
	A | B, 
	A ^ B, 
	~A,
	~B

	*/

	BitStream a, b;
	cin >> a.str;
	cin >> b.str;


	cout << a.And(b);
	cout << a.Or(b);
	cout << a.Xor(b);
	cout << a.Not();
	cout << b.Not();


	return 0;
}