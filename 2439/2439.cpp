#include <stdio.h>

int main()
    {
int a;
    
    scanf("%d",&a);
    
    for(int i=a-1;i>=0;i--)
   	{
        
        for(int j=0;j<=i-1; j++)
            putchar(' ');
        for(int k=0; k< a - i ; k++)
            putchar('*');
        putchar('\n');
    }
    

}