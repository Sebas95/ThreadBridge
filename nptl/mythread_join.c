#include <stdio.h>
#include "pthreadP.h"

int mythread_join (pthread_t threadid, void **thread_return){
	//printf("mythread_join");
	return pthread_join(threadid, thread_return);
}
