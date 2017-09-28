#include <stdlib.h>
#include "parser.h"
#include "scheduler.h"

#define FIFO    	   33
#define SJF			   42
#define ROUND_ROBIN    55
#define PRIORITY_QUEUE 77
#define REAL_TIME      66

#define NUM_CARS 	   3

int main(int argc, char const *argv[])
{
	getDataConfig();
 	
 	Bridge _puente;
 	_puente = getVarBridge(1);

 	int type_sched;
 	char* schThreads = _puente->schThreads;

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

	long* t = (long*)malloc( sizeof(long));
	*t = 0;
	pthread_t generator_izq ;
	pthread_create(&generator_izq, NULL, generateCars, (void *)t);

	long* t2 = (long*)malloc( sizeof(long));
	*t2 = NUM_CARS;
	pthread_t generator_der ;
	pthread_create(&generator_der, NULL, generateCars, (void *)t2);

	int joinResult;
	joinResult = pthread_join(generator_izq, NULL);
	joinResult = pthread_join(generator_der, NULL);

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
