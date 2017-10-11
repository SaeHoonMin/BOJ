#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace::std;

int dp[1001];
int arr[1001] = {-1,};

int main()
{
    int n;
    cin>>n;
    for(int i  = 1; i <= n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int ans = 0;
    
    
    for(int i = 1; i<=n; i++)
    {
        dp[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if( arr[j] < arr[i] )
            {
                dp[i] = max(dp[i], dp[j]+1 );
            }   
        }
        
        if(dp[i] > ans)
            ans =dp[i];
    }
    
    cout<<ans;
}