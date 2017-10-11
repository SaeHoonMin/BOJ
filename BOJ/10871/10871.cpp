#include <cstdio>
#include <iostream>
using namespace::std;

int main(void)
{
    int n, a, x;
    cin>>n>>a;
    for(int i = 0 ; i < n;  i++)
    {
        scanf("%d",&x);
        if( x < a )
            printf("%d ",x);
    }
}