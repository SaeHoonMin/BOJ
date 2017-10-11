#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define NUM(x) ( x-'1'+1 )
#define STR(x) ( x+'1'-1 )
using namespace std;

class DP {
	vector<char> arr;
public:
	bool empty();
	DP();
	DP(int i);
	DP& operator=(const DP& b);
	DP& operator=(const int& b);
	DP operator+(const DP& b);
	DP operator*(const int& b);
	void CatDP(const DP& b);
	friend ostream& operator<<(ostream& os, const DP& b);
};

void DP::CatDP(const DP& b)
{
	
	DP temp;

	for (int i = 0; i < b.arr.size(); i++)
	{
		temp.arr.push_back(b.arr[i]);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		temp.arr.push_back(arr[i]);
	}

	*this = temp;
}

bool DP::empty()
{
	if (arr.empty())
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const DP&b)
{
	for (int i = b.arr.size() - 1; i >= 0; i--)
	{
		printf("%d", b.arr[i]);
	}
	return os;
}
DP::DP()
{

}
DP::DP(int i)
{
	if (i < 10)
	{
		arr.push_back(i);
	}
	else
	{
		long long int div = 10;
		while (div <= 10000000000)
		{
			int res = i % div;
			res = res / (div / 10);
			arr.push_back(res);
			div = div * 10;
		}
		int j = arr.size() - 1;
		while (arr[j--] == 0)
		{
			arr.pop_back();
		}
	}
}

DP& DP::operator=(const int&b)
{
	arr.clear();
	arr.push_back(b);
	return *this;
}
DP& DP::operator=(const DP&b)
{
	arr.clear();
	for (int i = 0; i < b.arr.size(); i++)
		arr.push_back(b.arr[i]);
	return *this;
}

DP DP::operator+(const DP& b)
{
	const DP * at;
	const DP * bt;
	if (arr.size() >= b.arr.size())
	{
		at = this;
		bt = &b;
	}
	else
	{
		at = &b;
		bt = this;
	}

	DP temp;
	int k = at->arr.size();
	int carry = 0;

	for (int i = 0; i < k; i++)
	{
		int res; 
		if (i >= bt->arr.size())
			res = at->arr[i];
		else
			res = at->arr[i] + bt->arr[i];
		res += carry;
		if (res >= 10)
		{
			carry = res / 10;
			res = res % 10;
		}
		else
			carry = 0;
		temp.arr.push_back(res);
	}
	if (carry != 0)
		temp.arr.push_back(carry);
	return temp;
}
DP DP::operator*(const int& b)
{
	DP temp;
	int k = arr.size();
	int carry = 0;

	for (int i = 0; i < k; i++)
	{
		int res = arr[i] * 2;
		res += carry;
		if (res >= 10)
		{
			carry = res / 10;
			res = res % 10;
		}
		else
			carry = 0;
		temp.arr.push_back(res);
	}
	if (carry != 0)
		temp.arr.push_back(carry);

	return temp;
}


int main() {

	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	DP d1(a);
	DP d2(b);
	DP d3(c);
	DP d4(d);
	d1.CatDP(d2);
	d3.CatDP(d4);
	cout << d1 + d3;

}
