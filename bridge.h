#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int* bridge_1_in_use;
int* bridge_2_in_use;
int* bridge_3_in_use;
int* bridge_4_in_use;

void* runSemaphore(void* flag);

void* runOfficer(void* flag);

void* runJungleLaw(void* flag);

