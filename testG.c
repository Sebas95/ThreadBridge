#include "carsGenerator.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	float testSpawnTime;
	int testSpeed;
	int testType;

	testSpawnTime = getNextSpawnTime(2);
	printf("Spawn time: %f\n", testSpawnTime);
	testSpawnTime = getNextSpawnTime(2);
	printf("Spawn time2: %f\n", testSpawnTime);

	testSpeed = getSpeed(5, 2);
	printf("Speed: %d\n", testSpeed);
	testSpeed = getSpeed(5, 2);
	printf("Speed2: %d\n", testSpeed);


	testType = getType(40, 20);
	printf("Type: %d\n", testType);
	testType = getType(20, 40);
	printf("Type2: %d\n", testType);

	return 0;
}