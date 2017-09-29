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

int main(int argc, char const *argv[])
{
	getDataConfig();
 	int type_sched;
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
	 		type_sched = SJF;
	 	} 
	 	else if (strncmp(schThreads, "Round_Robin", 11) == 0)
	 	{
	 		type_sched = ROUND_ROBIN;
	 	}
	 	else if (strncmp(schThreads, "Real_time", 9) == 0)
	 	{
	 		type_sched = REAL_TIME;
	 	}
	 	else if (strncmp(schThreads, "FIFO", 4) == 0)
	 	{
	 		type_sched = FIFO;
	 	}
	 	else if (strncmp(schThreads, "Priority", 8) == 0)
	 	{
	 		type_sched = PRIORITY_QUEUE;
	 	}	

	 	attr[0] = type_bridgeControl;
	 	attr[1] = timeSemaphore;
	 	attr[2] = kOfficer;
	 	attr[3] = type_sched;
	 	attr[4] = largeBridge;
	 	attr[5] = mediaExponential;
	 	attr[6] = averageSpeed;
	 	attr[7] = procAmbulances;
	 	attr[8] = procRadioactive;

	 	setParam(attr,i);
 }

	long* t = (long*)malloc( sizeof(long));
	*t = 0;
	pthread_t generator_izq ;
	pthread_create(&generator_izq, NULL, generateCars, (void *)t);

	usleep(10000);

	long* t2 = (long*)malloc( sizeof(long));
	*t2 = NUM_CARS;
	pthread_t generator_der ;
	pthread_create(&generator_der, NULL, generateCars, (void *)t2);

	int joinResult;
	//joinResult = pthread_join(generator_izq, NULL);
	//joinResult = pthread_join(generator_der, NULL);

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
