
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

void initColas()
{
	cola11 = getANewCola();
	cola12 = getANewCola();
	cola21 = getANewCola();
	cola22 = getANewCola();
	cola31 = getANewCola();
	cola32 = getANewCola();
	cola41 = getANewCola();
	cola42 = getANewCola();
}

void fifoScheduler(int speed, int cartype, int id, int number_bridge, int transition, int id_cola)
{
	if(transition == NEW_READY)
	{
		Cola _cola = (Cola)malloc(sizeof(struct cola)); 
		_cola = determineCola(id_cola);
		pthread_t* thread_carro = (pthread_t*)malloc(sizeof(pthread_t));
		append(id, cartype, speed, UNUSED_SCH_PARAM, UNUSED_SCH_PARAM,thread_carro,_cola); 
		//mostrar_lista(_cola);
	}
	// HAGA POP SOLO SI getEstadoBridge le dice que puede
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




void* generateCars(void *threadarg)
{
	float spawnTime;
	int speed;
	int cartype;
  	long id;
  	int type_sched;
  	int cola_id;
  	struct thread_data *my_data;
  	my_data = (struct thread_data *) threadarg;

  	int initial_id = my_data->thread_initial_id; // CAMBIO INITIAL_ID DE LONG -> INT
  	int numberB = my_data->numberBridge;

  	for(id= initial_id ; id< (NUM_CARS + initial_id) ;id++)
  	{
  		spawnTime = getNextSpawnTime(mediaExponential1);   
		speed = getSpeed(averageSpeed1,1);
		cartype = getType(procRadioactive1, procAmbulances1);
		cola_id = my_data->numberBridge;
		//printf("cola id %d\n", cola_id);
		//printf("carro id %ld\n", id);
		runSched(spawnTime,speed,cartype ,initial_id , id, type_sched1, numberB,NEW_READY,cola_id);
		usleep(spawnTime * TIME_FACTOR_USLEEP);		
	}
	

	return 0;
  
}

	
	
void runSched(float spawnTime,int speed, int cartype , int initial_id ,int id, int type_sched, 
	int number_bridge, int transition, int cola_id)
{

	if(type_sched == FIFO  )
	{
		fifoScheduler(speed,cartype, id, number_bridge,NEW_READY,cola_id);
	}
	else if(type_sched == SJF)
	{

	}
	else if(type_sched == REAL_TIME )
	{

	}
	else if(type_sched == ROUND_ROBIN)
	{

	}
	else if(type_sched == PRIORITY_QUEUE)
	{

	}
	
}


Cola determineCola(int cola_id)
{
	if     (cola_id == 11)	return cola11;	
	else if(cola_id == 12)	return cola12;
	else if(cola_id == 21)	return cola21;
	else if(cola_id == 22)	return cola22;
	else if(cola_id == 31)	return cola31;
	else if(cola_id == 32)	return cola32;
	else if(cola_id == 41)	return cola41;
	else				 	return cola42;
	
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


