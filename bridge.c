#include "bridge.h"


void* runSemaphore(void* flag)
{
	while(1)
	{
	//	printf("%s\n","running runSemaphore" );
		usleep(10000);
	}
	
}

void* runOfficer(void* flag)
{
	while(1)
	{
	//	printf("%s\n","run officer" );
		usleep(10000);
	}
}

void* runJungleLaw(void* flag)
{
	while(1)
	{
	//	printf("%s\n","run jungle law" );
		usleep(10000);
	}
}

