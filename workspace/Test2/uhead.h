#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

struct arg{
	float ave;
	int sum;
};

int usum(int *,int);
void urand(int *,int);
void showa(int *,int);
void showb(int *,int);
void bsort(int *,int);
int  compare1(const void *,const void *);
void copy(int *,int *,int);



struct arg operater(int *,int);
