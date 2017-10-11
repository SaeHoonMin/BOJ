#include <stdio.h>


int main()
{
	int w, h;
	double diognal;
	int i, j, t;
	scanf("%d %d %d",&i,&w,&h);
	diognal = w * w + h * h;
	for(j=0; j<i; j++)
	{
		scanf("%d",&t);
		if( t <= w || t<=h )
			printf("DA\n");
		else if ( t*t <= diognal )
			printf("DA\n");
		else
			printf("NE\n");
	}

}