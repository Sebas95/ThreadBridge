#include <stdlib.h>
#include "parser.h"
#include "scheduler.h"

#define FIFO    	   33
#define SJF			   42
#define ROUND_ROBIN    55
#define PRIORITY_QUEUE 77
#define REAL_TIME      66
//-------------------------schBridge defines
#define Official 10
#define Jungle 11
#define Semaphore 12

#define NUM_CARS 	   3


void configure()
{

	int* type_sched = malloc(sizeof(int));
	getDataConfig();
 	
 	for (int i = 1; i < 5; ++i)
 	{	
 		Bridge _puente;
 		_puente = getVarBridge(i);
 		int* attr = malloc(sizeof(int)*9);
	 	int type_bridgeControl;
	 	
	 	char* schThreads = _puente->schThreads;
	 	char* schBridge = _puente->schBridge;
	 	int timeSemaphore = _puente->timeSemaphore;
	 	int kOfficer = _puente->kOfficer;
	 	int largeBridge = _puente->largeBridge;
	 	int mediaExponential = _puente->mediaExponential;
		int averageSpeed = _puente->averageSpeed;
		int procAmbulances = _puente->procAmbulances;
		int procRadioactive = _puente->procRadioactive;
		 	

 		

	 	if (strncmp(schBridge, "Official", 8) == 0)
	 	{
	 		type_bridgeControl = Official;
	 	} 
	 	else if (strncmp(schBridge, "Jungle", 6) == 0)
	 	{
	 		type_bridgeControl = Jungle;
	 	}
	 	else if (strncmp(schBridge, "Semaphore", 9) == 0)
	 	{
	 		type_bridgeControl = Semaphore;
	 	}


	 	if (strncmp(schThreads, "SJF", 3) == 0)
	 	{
	 		*type_sched = SJF;
	 	} 
	 	else if (strncmp(schThreads, "Round_Robin", 11) == 0)
	 	{
	 		*type_sched = ROUND_ROBIN;
	 	}
	 	else if (strncmp(schThreads, "Real_time", 9) == 0)
	 	{
	 		*type_sched = REAL_TIME;
	 	}
	 	else if (strncmp(schThreads, "FIFO", 4) == 0)
	 	{
	 		*type_sched = FIFO;
	 	}
	 	else if (strncmp(schThreads, "Priority", 8) == 0)
	 	{
	 		*type_sched = PRIORITY_QUEUE;
	 	}	
			
			printf("\n%d: schBridge: %s\n", i, _puente->schBridge);
 			printf("%d: timeSemaphore: %d\n", i, _puente->timeSemaphore);
 			printf("%d: kOfficer: %d\n", i, _puente->kOfficer);
 			printf("%d: schThreads: %s\n", i, _puente->schThreads);
 			printf("%d: largeBridge: %d\n", i, _puente->largeBridge);
 			printf("%d: mediaExponential: %d\n", i, _puente->mediaExponential);
 			printf("%d: averageSpeed: %d\n", i, _puente->averageSpeed);
 			printf("%d: procAmbulances: %d\n", i, _puente->procAmbulances);
 			printf("%d: procRadioactive: %d\n", i, _puente->procRadioactive);

	 	attr[0] = type_bridgeControl;
	 	attr[1] = timeSemaphore;
	 	attr[2] = kOfficer;
	 	attr[3] = *type_sched;
	 	attr[4] = largeBridge;
	 	attr[5] = mediaExponential;
	 	attr[6] = averageSpeed;
	 	attr[7] = procAmbulances;
	 	attr[8] = procRadioactive;

	 	setParam(attr,i);
 	}
 	//return *type_sched;
}

/*
void runSched(int type_sched)
{
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
}
*/

int main(int argc, char const *argv[])
{	

	struct thread_data *td1Left = malloc(sizeof(struct thread_data));
	struct thread_data *td2Left = malloc(sizeof(struct thread_data));
	struct thread_data *td3Left = malloc(sizeof(struct thread_data));
	struct thread_data *td4Left = malloc(sizeof(struct thread_data));

	struct thread_data *td1Right = malloc(sizeof(struct thread_data));
	struct thread_data *td2Right = malloc(sizeof(struct thread_data));
	struct thread_data *td3Right = malloc(sizeof(struct thread_data));
	struct thread_data *td4Right = malloc(sizeof(struct thread_data));


	td1Left->thread_id = 0*NUM_CARS;
	td2Left->thread_id = 1*NUM_CARS;
	td3Left->thread_id = 2*NUM_CARS;
	td4Left->thread_id = 3*NUM_CARS;

	td1Right->thread_id = 4*NUM_CARS;
	td2Right->thread_id = 5*NUM_CARS;
	td3Right->thread_id = 6*NUM_CARS;
	td4Right->thread_id = 7*NUM_CARS;

	td1Left->numberBridge = 11;
	td2Left->numberBridge = 21;
	td3Left->numberBridge = 31;
	td4Left->numberBridge = 41;

	td1Right->numberBridge = 12;
	td2Right->numberBridge = 22;
	td3Right->numberBridge = 32;
	td4Right->numberBridge = 42;


	//int type_sched = configure();
	configure();
	initColas();
	//long* t = (long*)malloc( sizeof(long));
	//*t = 0;
	pthread_t generator_izq1;
	pthread_t generator_izq2;
	pthread_t generator_izq3;
	pthread_t generator_izq4;

	pthread_t generator_der1;
	pthread_t generator_der2;
	pthread_t generator_der3;
	pthread_t generator_der4;



	pthread_create(&generator_izq1, NULL, generateCars, (void *)td1Left);
	usleep(100);
	pthread_create(&generator_izq2, NULL, generateCars, (void *)td2Left);
	usleep(100);
	pthread_create(&generator_izq3, NULL, generateCars, (void *)td3Left);
	usleep(100);
	pthread_create(&generator_izq4, NULL, generateCars, (void *)td4Left);
	usleep(100);



	//long* t2 = (long*)malloc( sizeof(long));
	//*t2 = NUM_CARS;
	//pthread_t generator_der;
	pthread_create(&generator_der1, NULL, generateCars, (void *)td1Right);
	usleep(100);
	pthread_create(&generator_der2, NULL, generateCars, (void *)td2Right);
	usleep(100);
	pthread_create(&generator_der3, NULL, generateCars, (void *)td3Right);
	usleep(100);
	pthread_create(&generator_der4, NULL, generateCars, (void *)td4Right);
	usleep(100);
	//runSched(type_sched);
	pthread_exit(NULL); //the last this main should do
	return 0;
}