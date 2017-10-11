#include <iostream>
using namespace::std;
int arr[1001];
int dp[1001];

int findMax(int i)
{
    int max = 0;
    
    for( int j = 1; j < i ; j++)
    {
        if(arr[j] < arr[i] && max < dp[j])
            max = dp[j];
    }
    
    return max;
}

int main(void)
{
    int n;
    cin>>n;
    
    for(int i = 1; i<= n; i++)
    {
        cin>>arr[i];
    }
    
    dp[1] = 1;
    int max = 1;
    for( int i = 2; i<= n; i++)
    {
        dp[i] = findMax(i) + 1;
        if(dp[i] > max)
            max = dp[i];
    }
    cout<<max;
}