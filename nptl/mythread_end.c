#include <stdio.h>
#include <pthread_create>

int mythread_end(){
	printf("mythread_end");
	return 0;
}