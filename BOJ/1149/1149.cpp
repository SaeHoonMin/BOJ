#include <iostream>
#include <algorithm>
using namespace::std;

#define R_ 0
#define G_ 1
#define B_ 2

int arr[3];

int before[3];

int main(void)
{
	int n;
	cin >> n;

	int iR, iG, iB;

	for (int i = 0; i < n; i++)
	{
		before[R_] = arr[R_]; 
		before[G_] = arr[G_]; 
		before[B_] = arr[B_];

		cin >> iR >> iG >> iB;
		arr[R_] = iR + min(before[G_], before[B_]);
		arr[G_] = iG + min(before[R_], before[B_]);
		arr[B_] = iB + min(before[R_], before[G_]);

		//debug
		//cout << "phase 1 { " << arr[R_] << " " << arr[G_] << " " << arr[B_] << " }" << endl << endl;
	}

	cout << min(arr[R_], min(arr[G_], arr[B_]));

	return 0;
}