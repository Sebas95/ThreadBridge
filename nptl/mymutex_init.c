

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <kernel-features.h>
#include "pthreadP.h"
#include <atomic.h>

#include <stap-probe.h>

int
__mymutex_init (pthread_mutex_t *mutex,
		      const pthread_mutexattr_t *mutexattr)
{
return pthread_mutex_init (mutex,mutexattr) ;
}
