#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "bridge.h"
#include "managerThread.h"
#include "carsGenerator.h"

void fifoScheduler();

void SJFScheduler();

void RoundRobinScheduler();

void PriorityQueueScheduler();

void RealTimeScheduler();

void* generateCars(void *initial_car_id);