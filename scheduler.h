#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "bridge.h"
#include "managerThread.h"
#include "carsGenerator.h"
#include "scheduler.h"

#define FIFO    	   33
#define SJF			   42
#define ROUND_ROBIN    55
#define PRIORITY_QUEUE 77
#define REAL_TIME      66

#define NUM_CARS 	   3
#define UNUSED_SCH_PARAM 0 //para establecer un parametro de carro que no se usa en un scheduler
#define TIME_FACTOR_USLEEP 1000000

struct thread_data {
   int  thread_id;
   int numberBridge; //between [1-4][1-2]
}; 


void fifoScheduler(int speed, int cartype, int id, int number_bridge);

void SJFScheduler();

void RoundRobinScheduler();

void PriorityQueueScheduler();

void RealTimeScheduler();

void* generateCars(void *threadar);

void setParam(int *, int);

void generateCarsAux(float spawnTime,int speed, int cartype , int initial_id ,int id, int type_sched, int number_bridge);