#include <stdio.h>
#include "scheduler.h"

//---------------------Bridge 1
 int  type_bridgeControl1;
 int  timeSemaphore1;
 int  kOfficer1;
 int  type_sched1;
 int  largeBridge1;
 int  mediaExponential1;
 int  averageSpeed1;
 int  procAmbulances1;
 int  procRadioactive1;
 //---------------------Bridge 2
 int  type_bridgeControl2;
 int  timeSemaphore2;
 int  kOfficer2;
 int  type_sched2;
 int  largeBridge2;
 int  mediaExponential2;
 int  averageSpeed2;
 int  procAmbulances2;
 int  procRadioactive2;
//---------------------Bridge 3
 int  type_bridgeControl3;
 int  timeSemaphore3;
 int  kOfficer3;
 int  type_sched3;
 int  largeBridge3;
 int  mediaExponential3;
 int  averageSpeed3;
 int  procAmbulances3;
 int  procRadioactive3;
//---------------------Bridge 4
 int  type_bridgeControl4;
 int  timeSemaphore4;
 int  kOfficer4;
 int  type_sched4;
 int  largeBridge4;
 int  mediaExponential4;
 int  averageSpeed4;
 int  procAmbulances4;
 int  procRadioactive4;


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


void setParam(int *attr, int numBridge){

	if(numBridge == 1){
		type_bridgeControl1 = attr[0];
	 	timeSemaphore1 = attr[1];
	 	kOfficer1 = attr[2] ;
	 	type_sched1 = attr[3];
	 	largeBridge1 = attr[4];;
	 	mediaExponential1 = attr[5];
	 	averageSpeed1 = attr[6];
	 	procAmbulances1 = attr[7];
	 	procRadioactive1 = attr[8];
	}
	else if(numBridge == 2){
		type_bridgeControl2 = attr[0];
	 	timeSemaphore2 = attr[1];
	 	kOfficer2 = attr[2] ;
	 	type_sched2 = attr[3];
	 	largeBridge2 = attr[4];;
	 	mediaExponential2 = attr[5];
	 	averageSpeed2 = attr[6];
	 	procAmbulances2 = attr[7];
	 	procRadioactive2 = attr[8];
	}
	else if(numBridge == 3){
		type_bridgeControl3 = attr[0];
	 	timeSemaphore3 = attr[1];
	 	kOfficer3 = attr[2] ;
	 	type_sched3 = attr[3];
	 	largeBridge3 = attr[4];;
	 	mediaExponential3 = attr[5];
	 	averageSpeed3 = attr[6];
	 	procAmbulances3 = attr[7];
	 	procRadioactive3 = attr[8];
	}
	else if(numBridge == 4){
		type_bridgeControl4 = attr[0];
	 	timeSemaphore4 = attr[1];
	 	kOfficer4 = attr[2] ;
	 	type_sched4 = attr[3];
	 	largeBridge4 = attr[4];;
	 	mediaExponential4 = attr[5];
	 	averageSpeed4 = attr[6];
	 	procAmbulances4 = attr[7];
	 	procRadioactive4 = attr[8];
	}
}


