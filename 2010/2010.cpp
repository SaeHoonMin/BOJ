#include <iostream>
using namespace::std;
int main()
{
    int a,b,n;
    b=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(i!=0)
            b--;
        cin>>a;
        b+=a;
    }
    cout<<b;
}