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

int scheduler_type;

int
__mythread_setsched (int* sched_type)
{
	scheduler_type = *sched_type;

	return scheduler_type;
}

