#include <iostream>
#include <vector>

using namespace::std;

int main(void)
{
    int n, k;
    int ans =0;
 
    cin>>n>>k;
    
    int * arr = new int[n];
    
    for(int i = 0 ; i<n; i++)
    {
        cin>> arr[i];
    }
    
    for(int i  = n-1; n>=0 ;i--)
    {
        ans += k / arr[i];
        k = k - (arr[i]*(k/arr[i]));
        
        if(k == 0 )
            break;
    }
    cout<<ans;
}