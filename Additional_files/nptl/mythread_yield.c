#include <stdio.h>
#include "pthreadP.h"

int mythread_yield (void){
	//printf("mythread_yield");
	return pthread_yield();
}
