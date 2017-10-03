#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "bridge.h"


#define NUM_LEDS 10


 int *bridge_1_in_use;
 int *bridge_2_in_use;
 int *bridge_3_in_use;
 int *bridge_4_in_use;

void* advance(void* car_attr);

int* getDataBridge(int bridge);