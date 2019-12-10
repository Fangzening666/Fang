#include"my.h"

#define NUM_THREADS   8

char *messages[NUM_THREADS];

struct thread_data{
		int thread_id;
		int sum;
		char *message;
};

struct thread_data thread_data_arry[NUM_THREADS];

void *PrintHello(void *threadarg){
	int taskid,sum;
	char *Hello_msg;
	struct thread_data *my_data;
	sleep(1);
	my_data = (struct thread_data *)threadarg;
	taskid = my_data->thread_id;
	sum = my_data->sum;
	Hello_msg = my_data->message;
	printf("Thread %d: %s Sum=%d\n",taskid,Hello_msg,sum);
	pthread_exit(NULL);

}
	int main(int argc,char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int *taskids[NUM_THREADS];
	int rc,t,sum;
	sum = 0;
	messages[0]= "English : Hello World！";
	messages[1]= "French : Hello World！";
	messages[2]= "Spanish : Hello World！";
	messages[3]= "English3 : Hello World！";
	messages[4]= "German : Hello World！";
	messages[5]= "Aussian : Hello World！";
	messages[6]= "Japan : Hello World！";
	messages[7]= "Latin : Hello World！";
	for(t=0;t<NUM_THREADS;t++)
{
	sum = sum + t;
	thread_data_arry[t].thread_id=t;
	thread_data_arry[t].sum=sum;
	thread_data_arry[t].message=messages[t];
	printf("Creating thread %d\n",t);
	rc=pthread_create(&threads[t],NULL,PrintHello,(void *)&thread_data_arry[t]);
	if(rc){
		printf("ERROR,return code f is %d\n",rc);
		exit(-1);
	}
	
}
	pthread_exit(NULL);
	
}
