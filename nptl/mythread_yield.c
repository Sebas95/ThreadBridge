#include <stdio.h>
#include <pthread_create>

int mythread_yield(){
	printf("mythread_yield");
	return 0;
}