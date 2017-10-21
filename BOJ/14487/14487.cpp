#include <iostream>
#include <algorithm>
using namespace::std;
int main(void)
{
    int n,a,sum=0, maxnum=-999;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        maxnum = max(a, maxnum);
        sum+=a;
    }
    cout<< sum-maxnum;
}