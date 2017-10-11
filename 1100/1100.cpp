#include <iostream>
#include <string>

using namespace::std;
using std::string;

int main()
{
	char c;
	int white=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cin>>c;
			if(i%2==0 && j%2==1)
			{
			}
			else if(i%2==1 && j%2==0)
			{
			}
			else
				if(c=='F')
					white++;
		}
	}
	cout<<white;

}