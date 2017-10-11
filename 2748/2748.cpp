#include <iostream>

using namespace::std;

int main(void)
{
    int n;
    cin>>n;
    
    long long int a = 0;
    long long int b = 1;
    long long int ans;
    
    
    if( n == 0 )
    {
      cout<<a; return 0;   
    }
    else if ( n == 1)
    {
        cout<<b; return 0;
    }
    
    // 0 1 1 2 3 5...
    
    for(int  i = 2; i<= n; i++)
    {
        ans = a+b;
        a = b;
        b = ans;
    }
 
    cout<<ans;
    
}