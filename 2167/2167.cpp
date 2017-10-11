#include <iostream>
using namespace::std;


int arr[301][301];

int main()
{
    int n, m;
    cin>>n>>m;
    
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1 ;j<= m ;j++)
        {
            cin>>arr[i][j];

        }
    }
    
    int k;
    cin>>k;
    for(int l = 0; l< k; l++)
    {
        int x1 ,y1 , x2, y2;
        cin>>x1>>y1>>x2>>y2;
        
        int sum = 0;
    	for(int b= x1 ;b<=x2;b++)
    	{
    		for(int a = y1;a<=y2;a++)
    			sum+=arr[b][a];
		}
	
    
        cout<<sum<<"\n";
    }
}
