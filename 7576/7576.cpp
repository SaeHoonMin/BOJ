#define RIPED		1
#define UNRIPED		0
#define NO_TOMATO	-1

//#define DEBUG 0

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <list>
#include <stdio.h>

using namespace::std;


int ProcessDays();

int m, n;

int  tomatos[1000][1000];

typedef struct tomato_t {
	int m;
	int n;
}tomato;

list<tomato> que;

int totalTomatos = 0;

//void printTomatos()
//{
//	//for debug
//#if DEBUG
//	cout << endl;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << tomatos[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	fflush(stdin);
//	while (getchar() != '\n') {}
//#endif
//}
//
//void printQueue()
//{
//#if DEBUG
//	for (std::list<tomato>::iterator it = que.begin(); it != que.end(); ++it)
//	{
//		std::cout << "[" << (*it).n << "," << (*it).m << "] ";
//	}
//	cout << endl;
//#endif
//}



int main(void)
{
	// input
	cin >> m >> n;
	//tomatos = (int **)malloc(sizeof(int) * n);
	//for (int i = 0; i < n; i++)
	//{
	//	tomatos[i] = (int*)malloc(sizeof(int) * m);
	//}
	

	// input tomatos..
	tomato temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomatos[i][j];
			if (tomatos[i][j] == RIPED)
			{
				//큐에 넣자.
				temp.m = j;
				temp.n = i;
				que.push_back(temp);

				totalTomatos++;
			}
			else if (tomatos[i][j] == UNRIPED)
			{
				totalTomatos++;
			}
		}
	}


	// Check Days..
	int days = 0;

	// if every tomato is riped from the start = 0
	if ( totalTomatos == que.size() )
	{
		cout << 0; 
		return 0;
	}

	totalTomatos -= que.size();

	//cout << "*******before strat *********" << endl;
	//printQueue();cout << endl << endl;
	//fflush(stdin);

	while(true)
	{

		days++;

		int queueSize = que.size();

//#if DEBUG
//		cout <<endl<<"****days "<<days<< " queueSize : " << que.size() << endl;
//#endif

		int ripedCount = 0;

		for (int i = 0; i < queueSize; i++)
		{
			tomato temp = que.front();
			tomato add;

			que.pop_front();

//#if DEBUG
//			cout << "[" << temp.n << "," << temp.m << "]" << endl;
//#endif

			//up
			if ( temp.n -1  >= 0 )
			{
				if (tomatos[temp.n - 1][temp.m] == UNRIPED)
				{
					ripedCount++;

					tomatos[temp.n - 1][temp.m] = RIPED;
					add.m = temp.m;
					add.n = temp.n - 1;
					que.push_back(add);

				//	printTomatos();
				}
			}
			//down
			if (temp.n + 1 < n)
			{
				if (tomatos[temp.n + 1][temp.m] == UNRIPED)
				{
					ripedCount++;

					tomatos[temp.n + 1][temp.m] = RIPED;
					add.m = temp.m;
					add.n = temp.n + 1;
					que.push_back(add);

			//		printTomatos();
				}
			}
			//left
			if (temp.m - 1 >= 0)
			{
				if (tomatos[temp.n][temp.m - 1] == UNRIPED)
				{
					ripedCount++;

					tomatos[temp.n][temp.m - 1] = RIPED;
					add.m = temp.m - 1;
					add.n = temp.n;
					que.push_back(add);


			//		printTomatos();
				}
			}
			//right
			if (temp.m + 1 < m)
			{
				if (tomatos[temp.n][temp.m + 1] == UNRIPED)
				{
					ripedCount++;

					tomatos[temp.n][temp.m + 1] = RIPED;
					add.m = temp.m + 1;
					add.n = temp.n;
					que.push_back(add);


			//		printTomatos();
				}
			}
		}//for

		totalTomatos -= ripedCount;

//#if DEBUG
//		cout << "result.. RIPED : " << ripedCount << " totalTomatos : " << totalTomatos << endl;
//		printQueue();
//		while (getchar() != '\n') {};
//#endif

		if(ripedCount == 0 && totalTomatos != 0) // Every tomato cannot be riped = -1
		{
			cout << -1;
			return 0;
		}
		else if (ripedCount == 0 && totalTomatos == 0)
		{
			cout << days -1 ;
			return 0;
		}


	}
}