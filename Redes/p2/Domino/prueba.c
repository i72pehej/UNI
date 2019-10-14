
#include <stdio.h>


void main()
	{
	int i, j,k,h;
	h=0;
	k=0;
	for(i=0;i<7;i++)
		{

		for(j=6;j>=h;j--)
		{
		printf("ficha %d : |%d|%d|\n",k,i,j);
		k++;
		}
		h++;
		}
	}