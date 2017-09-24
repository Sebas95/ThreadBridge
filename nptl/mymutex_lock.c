#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/param.h>
#include <not-cancel.h>
#include "pthreadP.h"
#include <atomic.h>
#include <lowlevellock.h>
#include <stap-probe.h>

int
__mymutex_lock (pthread_mutex_t *mutex)
{
	return __pthread_mutex_lock (mutex);
}

