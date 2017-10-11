#include <iostream>
#include <math.h>
using namespace::std;

int main(void)
{
    int a, b, c;
    
    cin>>a>>b>>c;
    
    cout<< max( c-b-1, b-a-1 );
}