#include"uhead.h"

int usum(int *a,int n)
{
	int sum=0,i;
	for(i=0;i<n;i++)
{
	sum=sum+a[i];
}
	return sum;
}

void urand(int *a,int n)
{
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++)
{
	a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
	
}
}

void showa(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
{
	printf("a[%d]=%d\n",i,a[i]);
	
}
}
void showb(int *b,int n)
{
	int i;
	for(i=0;i<n;i++)
{
	printf("b[%d]=%d\n",i,b[i]);
	
}


}

void bsort(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int  compare1(const void *a,const void *b)
{
      int *p1=(int*)a;
      int *p2=(int*)b;
      return (*p1-*p2);
}

void copy(int *a,int *b,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
}