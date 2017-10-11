#include <iostream>
#include <stdio.h>
using namespace::std;
int set[21];

int main(void)
{
    int n;
    cin>>n;
    char s[20];
    int val;
    
    for(int i = 0 ; i< n ;i++)
    {
        scanf("%s", s);
        
        if( s[0] == 'e' )
        {
            for(int i = 1 ; i<=20 ; i++)
            {
                set[i] = 0;
            }
        }
        else if ( s[1] =='l' && s[2]=='l')
        {
            for(int i = 1 ; i<=20 ; i++)
            {
                set[i] = 1;
            }
        }
        else
        {
            scanf("%d",&val);
            if( s[0] == 'a' )
            {
                set[val] = 1;
            }
            else if( s[0] == 'r' )
            {
                set[val] = 0;
            }
            else if( s[0] == 'c' )
            {
                printf("%d\n",set[val]);
            }
            else if( s[0] == 't' )
            {
                if(set[val])
                    set[val] = 0;
                else
                    set[val] = 1;
            }
        }
    }
}