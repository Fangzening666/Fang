#include"uhead.h"

int main()
{
	clock_t start,finish;
	double durationa,durationb;
	int a[MAX];
	int b[MAX];
	struct arg s;
	urand(a,MAX);
	copy(a,b,MAX);

	
	s = operater(a,MAX);

	start = clock();
	bsort(a,MAX);
	finish = clock();
	durationa=(double)(finish-start)/CLOCKS_PER_SEC;

	start = clock();
	qsort(b,MAX,sizeof (int),compare1);
	finish = clock();
	durationb=(double)(finish-start)/CLOCKS_PER_SEC;

	showa(a,MAX);
	printf("sum=%d \n*********\n",usum(a,MAX));
	printf("k.sum=%d \n*********\nk.ave=%f\n",s.sum,s.ave);

	showb(b,MAX);
	printf("sum=%d \n*********\n",usum(b,MAX));

	printf("durationa=%f seconds\n",durationa);
	printf("durationb=%f seconds\n",durationb);
	return 0;

}
