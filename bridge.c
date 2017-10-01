#include "bridge.h"


void* runSemaphore(void* flag)
{
	while(1)
	{
		if(*(int*)flag == 1)
			*(int*)flag = 2;
		else// (*(int*)flag == 2)
			*(int*)flag = 1;
		//printf("semaphore flag %d\n",*(int*)flag  );
		int time = 0;
		if(flag_bridge1 == (int*)flag)     time = timeSemaphore1; 
        else if(flag_bridge2 == (int*)flag)time = timeSemaphore2;
		else if(flag_bridge3 == (int*)flag)time = timeSemaphore3;
		else 							   time = timeSemaphore4;
		printf("tiempo delay : %d\n" ,1000000*time );
		usleep(1000000*time);
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

		//printf("officer flag in %d\n",*(int*)flag  );
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
		//printf("jungleLaw flag in %d\n",*(int*)flag  );
		usleep(1000000);
	
	}
}

