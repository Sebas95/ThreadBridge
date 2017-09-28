#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "bridge.h"
#include "managerThread.h"
#include "parser.h"
#include "carsGenerator.h"


#define NUM_CARS    1000

#define FIFO    	   33
#define SJF			   42
#define ROUND_ROBIN    55
#define PRIORITY_QUEUE 77
#define REAL_TIME      66




void fifoScheduler()
{

}

void SJFScheduler()
{

}

void RoundRobinScheduler()
{

}

void PriorityQueueScheduler()
{

}

void RealTimeScheduler()
{

}




void* generateCars(void *unused)
{
	
  	long x;
  	for(x=0;x<NUM_CARS;x++){
  		
  		float spawnTime;
		int speed;
		int cartype;
  		spawnTime = getNextSpawnTime(2);     //alambrado
		speed = getSpeed(5,2);				//alambrado
		cartype = getType(40, 20);			//alambrado

		//pthread_t threads[NUM_CARS];

		usleep(spawnTime * 100*100000);
		printf("Spawn time: %f\n", spawnTime);
		printf("Speed: %d\n", speed);
		printf("Type: %d\n", cartype);
	}
  /* Last thing that main() should do */
  pthread_exit(NULL);
}



int main(int argc, char const *argv[])
{
	int type_sched = FIFO ; //alambrado

	long t = 0;
	pthread_t generator ;
	pthread_create(&generator, NULL, generateCars, (void *)t);
	pthread_exit(NULL);

	
	if (type_sched == FIFO)
	{
		fifoScheduler();
	}
	else if (type_sched == ROUND_ROBIN )	
	{
		RoundRobinScheduler();
	}
	else if (type_sched == PRIORITY_QUEUE )
	{
		PriorityQueueScheduler();
	}
	else if (type_sched == SJF  )		
	{
		SJFScheduler();
	}
	else if (type_sched == REAL_TIME  )		
	{
		RealTimeScheduler();
	}

	

	return 0;
}