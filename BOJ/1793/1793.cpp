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
	friend ostream& operator<<(ostream& os, const DP& b);
};

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
}

DP& DP::operator=(const int&b)
{
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
	DP temp;
	int k = arr.size();
	int carry = 0;

	for (int i = 0; i < k; i++)
	{
		int res = arr[i] + b.arr[i];
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
	if(carry != 0)
		temp.arr.push_back(carry);

	return temp;
}


int main() {

	// Recurrence relation
	// dp[1] = 1;
	// dp[2] = 3;		// ll, =, ㅁ == dp[2-1] +2
	// i >=3
	// dp[i] =  dp[i-1] + dp[i-2]*2
	// l ㅁ
	// l =
	// ll l
	// l ll <- 제외

	DP dp[251];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;

	int n;

	while (scanf("%d", &n)>0)
	{
		
		
		for (int i = 3; i <= n; i++)
		{
			if(dp[i].empty())
			dp[i] = dp[i - 1] + (dp[i - 2] * 2);
		}
		cout << dp[n]<<endl;
	}
	
	

}
