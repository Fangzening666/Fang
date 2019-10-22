#include"lib.h"
#include<dlfcn.h>

int main()
{
	int a[MAX];
	void *handle;
	void (*f1)();
	int (*f2)(),(*f3)();
	char* error;
	
	handle = dlopen("/home/mouslet/Fang/linuxprogram/week6/code/dynamic/libtest.so",RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1=dlsym(handle,"urand");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f2=dlsym(handle,"max");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f3=dlsym(handle,"sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1(a,MAX);
	printf("max=%d \n*********\n",f2(a,MAX));
	printf("sum=%d \n*********\n",f3(a,MAX));
	
	if(dlclose(handle)<0)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	return 0;
}
