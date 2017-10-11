// 1874_stack수열.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;



int main()
{
	vector<int> target;
	vector<int> temp;
	vector<int> stack;

	vector<char> result;
	int n;
	cin >> n;

	int a; 
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		target.push_back(a);
		temp.push_back(a);
	}
	
	sort(temp.begin(), temp.end());

	int j = 0;
	int i = 0;
	while (true)
	{
		if (i < temp.size() && stack.size() == 0) // 처음 혹은 스택이 비어있음 : 정렬된 temp[i]을 stack 에 push
		{
			stack.push_back(temp[i]);
			i++;
			result.push_back('+');
		}
		else
		{
			if ( stack.size() > 0 &&
				stack.at(stack.size() - 1) == target[j])
			{
				result.push_back('-');
				stack.pop_back();
				j++;
			}
			else if( i < temp.size() )
			{
				result.push_back('+');
				stack.push_back(temp[i]);
				i++;
			}
			else
			{
				break;
			}
		}
	}

	if (j != target.size())
	{
		cout << "NO\n";
		return 0;
	}


	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] <<"\n";
	}

    return 0;
}

