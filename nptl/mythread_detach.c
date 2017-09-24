#include <stdio.h>
#include "pthreadP.h"

int mythread_detach(pthread_t th) {
	printf("mythread_detach");
	return pthread_detach(th);
}