#include <stdio.h>
#include <pthread_create>

int mythread_detach(){
	printf("mythread_detach");
	return 0;
}