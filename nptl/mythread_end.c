#include <stdio.h>
#include "pthreadP.h"

void mythread_end(void *value){
	//printf("pthread_exit\n");
	pthread_exit(value);
}
