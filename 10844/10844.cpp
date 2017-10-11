#include <iostream>

using namespace::std;

const int divider = 1000000000;

int dp[101][10] = { 0,0,0,0,0,0,0,0,0,0,
                    0,1,1,1,1,1,1,1,1,1,
                    0,2,2,2,2,2,2,2,2,1,};
                      
int main(void)
{
    int n;
    cin>>n;
    
    for(int i = 3 ; i <= n; i++ )
    {
        for(int j = 1; j <=9 ; j++)
        {
            if(j == 1)
            {
                dp[i][j] = (dp[i-2][j] + dp[i-1][j+1]) % divider;
            }
            else if ( j == 9 )
                dp[i][j] = (dp[i-1][j-1]) % divider;
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%divider;
                
           // cout<< dp[i][j] <<" " ;
          //  cout<<"  dp"<<i<<","<<j<<" : " <<dp[i][j];
        }
       // cout<<endl;
    }
    
    int sum=0;
    for(int i = 1; i <= 9; i++)
    {
      //  cout<<"sum+"<<dp[n][i]<<" is "<<sum<<endl;
        sum = (sum +dp[n][i]) %divider;
    }
    cout<<sum;

}