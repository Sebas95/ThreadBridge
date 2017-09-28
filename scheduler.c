#include <stdio.h>
#include "scheduler.h"






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




void* generateCars(void *initial_car_id)
{
	float spawnTime;
	int speed;
	int cartype;
  	long x;
  	long initial_id = *(long*)initial_car_id;
  	for(x= initial_id ; x< (NUM_CARS + initial_id) ;x++)
  	{
  		
  		spawnTime = getNextSpawnTime(2);     //alambrado
		speed = getSpeed(5,2);				//alambrado
		cartype = getType(40, 20);			//alambrado

		if(initial_id == 0 )   //alambrado
			append(x, cartype, speed, UNUSED_SCH_PARAM, UNUSED_SCH_PARAM, 0);
		if(initial_id == NUM_CARS )
			append(x, cartype, speed, UNUSED_SCH_PARAM, UNUSED_SCH_PARAM, 1);

		usleep(spawnTime * TIME_FACTOR_USLEEP);
	
	}
	
	if(initial_id == 0 )   //alambrado
		mostrar_lista(0);
	if(initial_id == NUM_CARS )
		mostrar_lista(1);

	return 0;
  
}


