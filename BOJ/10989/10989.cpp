#include <iostream>
#include <stdio.h>
int arr[10001];
int main(void)
{
    int n, a; 
    std::cin>>n;
    for( int i = 0; i< n; i++)
    {
        std::cin>>a;
        arr[a]++;
    }
    for( int i = 0; i< 10001; i++)
    {
         for( int j  = 0 ; j< arr[i] ; j++)
            printf("%d\n",i);
    }

}