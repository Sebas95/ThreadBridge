
#include "scheduler.h"

int type_sched;

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
		append(id, cartype, speed, UNUSED, UNUSED,thread_carro,_cola); 
		//mostrar_lista(_cola);
	}
	if(transition == READY_RUNNING)
	{
		runNextCar(number_bridge,id_cola);
	}
}

void SJFScheduler(int speed, int cartype, int id, int number_bridge, int transition, int id_cola)
{
	if(transition == NEW_READY)
	{
		Cola _cola = (Cola)malloc(sizeof(struct cola)); 
		_cola = determineCola(id_cola);
		pthread_t* thread_carro = (pthread_t*)malloc(sizeof(pthread_t));
		int positionToInsert = 0;
		if(listaVacia(_cola) == 1){
			append(id, cartype, speed, UNUSED, UNUSED,thread_carro,_cola);
		}
		else{
			positionToInsert = searchPositionSpeed(speed,_cola);
			insert(positionToInsert,id,cartype,speed, UNUSED, UNUSED, thread_carro,_cola);
		}
	}
	if(transition == READY_RUNNING)
	{
		runNextCar(number_bridge,id_cola); 
	}
}

void RoundRobinScheduler()
{

}

void PriorityQueueScheduler(int speed, int cartype, int id, int number_bridge, int transition, int id_cola)
{
	if(transition == NEW_READY)
	{
		Cola _cola = (Cola)malloc(sizeof(struct cola)); 
		_cola = determineCola(id_cola);
		pthread_t* thread_carro = (pthread_t*)malloc(sizeof(pthread_t));
		int positionToInsert = 0;
		int priority = getPriority(cartype);
		if(listaVacia(_cola) == 1){
			append(id, cartype, speed, priority, UNUSED,thread_carro,_cola);
		}
		else{
			positionToInsert = searchPositionPriority(priority,_cola);
			/*printf("---Position to Insert %d\n", positionToInsert);
			printf("---------------antes-------------------");
			mostrar_lista(_cola);
			*/
			insert(positionToInsert,id,cartype,speed, priority, UNUSED, thread_carro,_cola);
			/*printf("-------------despues---------------------");
			mostrar_lista(_cola);
			*/	
		}
		//mostrar_lista(_cola);
	}
	if(transition == READY_RUNNING)
	{
		runNextCar(number_bridge,id_cola); 
	}
}

void RealTimeScheduler()
{

}

/* Global sched
*
*
*/
void* run_sched(void* unused)
{
	long iter = 0;
	while(iter<40000000)
	{
		usleep(1);
		iter++;
		//if(type_sched != ROUND_ROBIN) desabilitar quantum
			//bridge 1
		if(*flag_bridge1 == 1 && *bridge_1_in_use == 0 && *flagSincronizacionOfficialScheduler1 == 0) //pasen los del lado izquierdo  puente 1
			callSched(UNUSED, UNUSED, UNUSED, 1 ,READY_RUNNING, 11);
		else if (*flag_bridge1 == 2 && *bridge_1_in_use == 0 && *flagSincronizacionOfficialScheduler1 == 0) //pasen los del lado derecho puente 1
			callSched(UNUSED, UNUSED, UNUSED, 1 ,READY_RUNNING, 12);
		//else printf("%s\n","puente 1 ocupado");

		//for bridge 2
		if(*flag_bridge2 == 1 && *bridge_2_in_use == 0 && *flagSincronizacionOfficialScheduler2 == 0) //pasen los del lado izquierdo  puente 1
			callSched(UNUSED, UNUSED, UNUSED, 2 ,READY_RUNNING, 21);
		else if (*flag_bridge2 == 2 && *bridge_2_in_use == 0 && *flagSincronizacionOfficialScheduler2 == 0) //pasen los del lado derecho puente 1
			callSched(UNUSED, UNUSED, UNUSED, 2 ,READY_RUNNING, 22);
		//else printf("%s\n","puente 2 ocupado");		

		//for bridge 3
		if(*flag_bridge3 == 1 && *bridge_3_in_use == 0 && *flagSincronizacionOfficialScheduler3 == 0) //pasen los del lado izquierdo  puente 1
			callSched(UNUSED, UNUSED, UNUSED, 3 ,READY_RUNNING, 31);
		else if (*flag_bridge3 == 2 && *bridge_3_in_use == 0 && *flagSincronizacionOfficialScheduler3 == 0) //pasen los del lado derecho puente 1
			callSched(UNUSED, UNUSED, UNUSED, 3 ,READY_RUNNING, 32);
		//else printf("%s\n","puente 3 ocupado");

		//for bridge 4
		if(*flag_bridge4 == 1 && *bridge_4_in_use == 0 && *flagSincronizacionOfficialScheduler4 == 0 ) //pasen los del lado izquierdo  puente 1
			callSched(UNUSED, UNUSED, UNUSED, 4 ,READY_RUNNING, 41);
		else if (*flag_bridge4 == 2 && *bridge_4_in_use == 0 && *flagSincronizacionOfficialScheduler4 == 0) //pasen los del lado derecho puente 1
			callSched(UNUSED, UNUSED, UNUSED, 4 ,READY_RUNNING, 42);
		//else printf("%s\n","puente 4 ocupado");
		
		
	}
		printf("%s\n", "-----------Finish of scheduler----------");
	return 0;
}


void* generateCars(void *threadarg)
{
	float spawnTime;
	int speed;
	int cartype;
  	long id;
  	
  	int cola_id;
  	struct thread_data *my_data;
  	my_data = (struct thread_data *) threadarg;
  	int initial_id = my_data->thread_initial_id; // CAMBIO INITIAL_ID DE LONG -> INT
  	int numberB = my_data->numberBridge;
  	for(id= initial_id ; id< (NUM_CARS + initial_id) ;id++)
  	{
  		spawnTime = getNextSpawnTime(mediaExponential1);   
		speed = getSpeed(averageSpeed1,3);
		cartype = getType(procRadioactive1, procAmbulances1);
		cola_id = my_data->numberBridge;
		//printf("cola id %d\n", cola_id);
		//printf("carro id %ld\n", id);
		callSched(speed,cartype , id,  numberB,NEW_READY,cola_id);
		usleep(spawnTime * TIME_FACTOR_USLEEP);		
	}
	return 0;
}

	
	
void callSched(int speed, int cartype , int id,int number_bridge, int transition, int cola_id)
{

	if(type_sched == FIFO  )
	{
		fifoScheduler(speed,cartype, id, number_bridge,transition,cola_id);
	}
	else if(type_sched == SJF)
	{
		SJFScheduler(speed,cartype,id,number_bridge,transition,cola_id);
	}
	else if(type_sched == REAL_TIME )
	{

	}
	else if(type_sched == ROUND_ROBIN)
	{

	}
	else if(type_sched == PRIORITY_QUEUE)
	{
		PriorityQueueScheduler(speed,cartype,id,number_bridge,transition,cola_id);
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

void runNextCar( int number_bridge, int id_cola)
{
	Cola _cola = (Cola)malloc(sizeof(struct cola));
	_cola = determineCola(id_cola);
	if( listaVacia(_cola) == 0) //revisa si hay carros en cola
	{
		//mostrar_lista(_cola);
	    Nodo _temporal = (Nodo)malloc(sizeof(struct nodo));

		_temporal = pop(_cola);
		//get thread and attributes

		int* car_attr = (int*)malloc(7*sizeof(int));
		
		car_attr[0] = (int)_temporal->idThread;
		car_attr[1] = (int)_temporal->speed;
		car_attr[2] = id_cola;
		car_attr[3] = number_bridge;
		car_attr[4] = (int)_temporal->type_of_car;
		if(number_bridge == 1)
		{
			car_attr[5] = (int)type_bridgeControl1;
			car_attr[6] = (int)largeBridge1;
		}
		else if(number_bridge == 2)
		{
			car_attr[5] = (int)type_bridgeControl2;
			car_attr[6] = (int)largeBridge2;
		}
		else if(number_bridge == 3)
		{
			car_attr[5] = (int)type_bridgeControl3;
			car_attr[6] = (int)largeBridge3;
		}
		else
		{
			car_attr[5] = (int)type_bridgeControl4;
			car_attr[6] = (int)largeBridge4;
		}
		pthread_create(_temporal->thread, NULL, advance, (void *)car_attr);
		//mostrar_lista(_cola);
		printf("Solcitud para correr en puente %d desde %d cola \n", number_bridge , id_cola );
	
	} 
}


int getPriority(int cartype)
{
	int* priority = malloc(sizeof(int));
	if(cartype == RADIOACTIVE)    *priority = 0;
	else if(cartype == AMBULANCE) *priority = 1;
	else if(cartype == NORMAL)    *priority = (rand() % 4) + 2;
	else *priority = 3;
	return *priority;
}



void setParam(int *attr, int numBridge){

	type_sched = attr[3];
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


