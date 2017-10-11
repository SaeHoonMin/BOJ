#include <iostream>
#include <stdlib.h>
using namespace::std;

int Compare(int a, int b)
{
	return a >= b ? a : b;
}

int main(void)
{
	int triangleSize;

	int maxSum = 0;

	cin >> triangleSize;

	int ** inputArr;
	int ** resultArr;

	inputArr = (int **)malloc(sizeof(int*) * triangleSize);
	resultArr = (int **)malloc(sizeof(int*) * triangleSize);
	for (int i = 0; i < triangleSize; i++)
	{
		inputArr[i] = (int*)malloc(sizeof(int) * triangleSize);
		resultArr[i] = (int*)malloc(sizeof(int) * triangleSize);
	}

	for (int i = 0;i < triangleSize; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> inputArr[i][j];
		}
	}

	resultArr[0][0] = inputArr[0][0];

	for (int i = 1; i < triangleSize; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int currentNum = inputArr[i][j];
			if (j == 0)
			{
				resultArr[i][j] = resultArr[i - 1][j] + currentNum;
			}
			else
			{
				resultArr[i][j] = Compare(resultArr[i - 1][j] + currentNum,
					                      resultArr[i - 1][j - 1] + currentNum);

				if (resultArr[i][j] >= maxSum)
					maxSum = resultArr[i][j];
			}
		}
	}

	cout << maxSum;


	return 0;
}