#include <stdio.h>

int main()
    {
	int arr[1000];
    
    int i=1;
    int index=0;
    
    int a, b;
	int sum=0;
    
    scanf("%d %d",&a,&b);
    
   	while(1)
    {
      if(index<1000)
      {
         int j=0;
         for(;j<i;j++)
         {
			 if(index>=1000)
				 break;
             arr[index]=i;   
             index++;
         }
      }
	  else
		  break;
      i++;
    }

	for(;a-1<=b-1;a++)
	{
		sum+=arr[a-1];
	}
    printf("%d",sum);
}