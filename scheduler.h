#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "bridge.h"
#include "managerThread.h"
#include "carsGenerator.h"

#define FIFO    	   33
#define SJF			   42
#define ROUND_ROBIN    55
#define PRIORITY_QUEUE 77
#define REAL_TIME      66

#define NUM_CARS 	   3
#define UNUSED_SCH_PARAM 0 //para establecer un parametro de carro que no se usa en un scheduler
#define TIME_FACTOR_USLEEP 1000000

void fifoScheduler();

void SJFScheduler();

void RoundRobinScheduler();

void PriorityQueueScheduler();

void RealTimeScheduler();

void* generateCars(void *initial_car_id);