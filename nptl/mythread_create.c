#include <stdio.h>
#include "pthreadP.h"

int mythread_create (pthread_t *newthread, const pthread_attr_t *attr,
		      void *(*start_routine) (void *), void *arg, short sched){
	
	printf("mythread_create with sched: %d\n",sched);
	return pthread_create(newthread, attr, start_routine, arg);
}