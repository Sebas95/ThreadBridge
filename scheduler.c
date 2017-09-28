#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "bridge.h"
#include "managerThread.h"
#include "parser.h"
#include "carsGenerator.h"


#define NUM_CARS    3

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



int main(int argc, char const *argv[])
{
	int type_sched = FIFO ; //alambrado

	long* t = (long*)malloc( sizeof(long));
	*t = 0;
	pthread_t generator_izq ;
	pthread_create(&generator_izq, NULL, generateCars, (void *)t);

	long* t2 = (long*)malloc( sizeof(long));
	*t2 = NUM_CARS;
	pthread_t generator_der ;
	pthread_create(&generator_der, NULL, generateCars, (void *)t2);

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