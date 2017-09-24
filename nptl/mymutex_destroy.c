
#include <errno.h>
#include "pthreadP.h"

#include <stap-probe.h>


int
__mymutex_destroy (pthread_mutex_t *mutex)
{  
  return __pthread_mutex_destroy (mutex);
}

