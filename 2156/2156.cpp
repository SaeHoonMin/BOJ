#include <iostream>
using namespace::std;
int dp[10001];
int grape[10001];
int main()
{
    int n;
    cin>>n;
    for(int i =  1 ; i<= n; i++)
    {
        cin>>grape[i];
    }
    
    dp[1] = grape[1];
    dp[2] = grape[2] + dp[1];
    
    for( int i = 3; i <= n ; i++)
    {
        dp[i] = max( max( dp[i-2] + grape[i], dp[i-1]),
                     grape[i] + grape[i-1] + dp[i-3] );
    }
    
    cout<<dp[n];
}
