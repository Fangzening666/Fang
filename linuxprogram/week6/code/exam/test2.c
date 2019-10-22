#include"lib.h"

int main()
{
	int a[MAX];
	urand(a,MAX);


	printf("max=%d \n*********\n",max(a,MAX));
	printf("sum=%d \n*********\n",sum(a,MAX));

	return 0;
}
