#include <cstdio>
#include <iostream>
#include <string>

using namespace::std;

typedef struct King{
	int x, y;
}King_t;
typedef struct Stone{
	int x, y;
}Stone_t;
typedef struct Coord{
	int x, y;	
}Coord_t;

enum eDIR{
	R = 0,
	L,
	B,
	T,
	RT,
	LT,
	RB,
	LB,
	DIR_MAX, //8
};

Coord coord[DIR_MAX] =
{
	{1,  0},		//R	
	{-1, 0},		//L
	{0, -1}, 	//B
	{0,  1}, 	//T
	{1,  1}, 	//RT
	{-1, 1}, 	//LT
	{1, -1},		//RB
	{-1,-1},	//LB
};

string dir[DIR_MAX] = 
{
	"R",
	"L",
	"B",
	"T",
	"RT",
	"LT",
	"RB",
	"LB",
};

int getNum(char ch)
{
	return ch-'A'+1;
}

void Move(Coord&way);
void PrintKing();
void PrintStone();

King king; 
Stone stone;

int main(void)
{
	char x;
	int y;
	int n;
	
	cin>>x>>king.y;
	king.x = getNum(x);
	cin>>x>>stone.y;
	stone.x =  getNum(x);
	

	cin>>n;
	string s;
	for(int i = 0; i < n; i++)
	{
		cin>>s;
		if( s.compare(dir[B]) ==0)
		{
			Move( coord[B] );
		}
		else if ( s.compare(dir[T]) ==0)
		{
			Move( coord[T] );	
		}
		else if ( s.compare(dir[R]) ==0 )
		{
			Move( coord[R] );	
		}
		else if ( s.compare(dir[L]) ==0)
		{
			Move( coord[L] );	
		}
		else if ( s.compare(dir[RT]) ==0)
		{
			Move( coord[RT] );	
		}
		else if ( s.compare(dir[LT]) ==0)
		{
			Move( coord[LT] );	
		}
		else if ( s.compare(dir[RB]) ==0)
		{
			Move( coord[RB] );	
		}
		else 
		{
			Move( coord[LB] );
		}
	}
	
	PrintKing();
	PrintStone();
}

void PrintKing()
{
	char kx = king.x+'A'-1;
	cout<< kx<<king.y<<endl;
}
void PrintStone()
{
	char sx = stone.x +'A'-1;
	cout<< sx<<stone.y<<endl;
}

void Move(Coord& way)
{
	int tx = king.x + way.x;
	int ty = king.y + way.y;
	if( tx >= 1 && tx <= 8 && ty>=1 && ty <= 8 )
	{
		if( ty == stone.y && tx == stone.x )
		{
			int kx = stone.x + way.x;
			int ky = stone.y + way.y;
			if( kx >= 1 && kx <= 8 && ky>=1 && ky <= 8 )
			{
				king.x = tx;
				king.y = ty;
				stone.x = kx;
				stone.y = ky;

			//	PrintKing();
			//	PrintStone();
			}
			else
			{
				// do nothing.
			}
		}
		else
		{
			king.x = tx;
			king.y = ty;
			

		}
	}
	else
	{
		// do nothing	
	}
}