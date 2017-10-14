
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include "pthreadP.h"
#include <lowlevellock.h>


int
__mymutex_trylock (pthread_mutex_t *mutex)
{
  return __pthread_mutex_trylock (mutex);
}
