#include"lib.h"

int max(int *a,int n)
{
	int i=0,max=0;
	max=a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		
	}
	return max;
}
