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
  	for(x= *(long*)initial_car_id ; x< (NUM_CARS + *(long*)initial_car_id) ;x++){
  		
  		

		//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
		//pthread_mutex_lock( &mutex1 );

  		spawnTime = getNextSpawnTime(2);     //alambrado
		speed = getSpeed(5,2);				//alambrado
		cartype = getType(40, 20);			//alambrado


		if(*(long*)initial_car_id == 0 )   //alambrado
			setQueue(0);
		if(*(long*)initial_car_id == NUM_CARS )
			setQueue(1);    

		append(x, cartype, speed, 0, 0);
		//mostrar_lista();
		printf("**********************************************\n");

		usleep(spawnTime * 100*100000);
		printf("Spawn time: %f\n", spawnTime);
		printf("Speed: %d\n", speed);
		printf("Type: %d\n", cartype);
		//pthread_mutex_unlock( &mutex1 );
	}
	
	setQueue(0);
	mostrar_lista();
	setQueue(1);  
	mostrar_lista();
  /* Last thing that main() should do */
	//Nodo _aux = pop();

  pthread_exit(NULL);
}



