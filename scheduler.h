#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "bridge.h"
#include "managerThreads.h"
#include "carsGenerator.h"
#include "car.h"

#define RADIOACTIVE 0
#define AMBULANCE   1
#define NORMAL      2


#define FIFO    	   33
#define SJF			   42
#define ROUND_ROBIN    55
#define PRIORITY_QUEUE 77
#define REAL_TIME      66

#define NUM_CARS 	   4
#define UNUSED 0 //para establecer un parametro de carro que no se usa en un scheduler
#define TIME_FACTOR_USLEEP 1000000

//DEFINE TRANSITIONS

#define NEW_READY 100
#define READY_RUNNING 200
#define RUNNING_TERMINATED 300
#define NUM_BRIDGES    4

struct thread_data {
   int  thread_initial_id;
   int numberBridge; //between [1-4][1-2]
}; 

void* run_sched(void* unused);

void initColas();

void fifoScheduler(int speed, int cartype, int id, int number_bridge, int transition,int id_cola);

void SJFScheduler();

void RoundRobinScheduler();

void PriorityQueueScheduler();

void RealTimeScheduler();

void* generateCars(void *threadar);

void setParam(int *, int);

void callSched(int speed, int cartype , int id,int number_bridge, int transition, int cola_id);

Cola determineCola(int cola_id);

int getPriority(int cartype);

void runNextCar( int number_bridge, int id_cola);

//Definition of head pointers of each queue
Cola cola11;
Cola cola12;
Cola cola21;
Cola cola22;
Cola cola31;
Cola cola32;
Cola cola41;
Cola cola42;





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