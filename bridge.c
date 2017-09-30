#include "bridge.h"


void* runSemaphore(void* flag)
{
	while(1)
	{
		if(*(int*)flag == 1)
			*(int*)flag = 2;
		else if (*(int*)flag == 2)
			*(int*)flag = 1;
		printf("semaphore flag %d\n",*(int*)flag  );
		usleep(1000000);
	}
	
}

void* runOfficer(void* flag)
{
	while(1)
	{
		if(*(int*)flag == 1)
			*(int*)flag = 2;
		else if (*(int*)flag == 2)
			*(int*)flag = 1;

		printf("officer flag in %d\n",*(int*)flag  );
		usleep(1000000);
	}
}

void* runJungleLaw(void* flag)
{
	while(1)
	{
		
		if(*(int*)flag == 1)
			*(int*)flag = 2;
		else if(*(int*)flag == 2)
			*(int*)flag = 1;
		printf("jungleLaw flag in %d\n",*(int*)flag  );
		usleep(1000000);
	
	}
}

