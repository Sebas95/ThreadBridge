#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "bridge.h"


#define NUM_LEDS 10




void* advance(void* car_attr);

int* getDataBridge(int bridge);