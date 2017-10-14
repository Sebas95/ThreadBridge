
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include "pthreadP.h"
#include <lowlevellock.h>
#include <stap-probe.h>



int
__mymutex_unlock (pthread_mutex_t *mutex)
{
  return __pthread_mutex_unlock (mutex);
}

