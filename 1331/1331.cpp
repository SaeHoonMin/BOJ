#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int move[8][2] =
{
	{ -1 , -2 }, {-2 , -1 },
	{  1 , 2 }, { 2, 1 } ,
	{ -1,  2 }, { -2, 1 },
	{ 1, -2 } , {2, -1 }
};

bool chess[6][6] = { false, };
int current[2] = { -1, -1 };
int first[2] = { -1, -1 };



bool CheckMove(int a, int b)
{
	int i = a - current[0];
	int j = b - current[1];

	bool found = false;

	if (chess[a][b] == true)
		return false;
	else
	{
		for (int k = 0; k < 8; k++)
		{
			if (i == move[k][0] &&
				j == move[k][1])
			{
				found = true;
				break;
			}
		}
	}


	if (found == false)
			return false;

	return true;
}

int main(void)
{

	for (int i = 0; i < 36;i++)
	{
		char a;
		int b;
		cin >> a;
		cin >> b;
		a -= 'A';
		b -= 1;


		if (current[0] == -1)
		{
			current[0] = a; 
			current[1] = b;

			first[0] = a;
			first[1] = b;

			chess[a][b] = true;
		}
		else
		{
			if (CheckMove( a, b ))
			{
				current[0] = a;
				current[1] = b;
				chess[a][b] = true;
			}
			else
			{
				cout << "Invalid" << endl;
				return 0;
			}
		}
	}


		for (int i = 0; i < 8; i++)
		{
			if (move[i][0] + current[0] == first[0] &&
				move[i][1] + current[1] == first[1])
			{
				cout << "Valid" << endl;
				return 0;
			}
		}



		cout << "Invalid" << endl;;
}