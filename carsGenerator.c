#include "carsGenerator.h"

float x = 0;

float getNextSpawnTime(int median)
{
	float time, lambda;
	lambda = (log(2)/median);
	time = lambda * exp(-1*lambda*x);
	x+= 0.1;
	usleep(100*1000);
	return time;
}

int getSpeed(int average, int variation)
{
	int speed;
	int max = average + variation;
	int min = average - variation;
	if(average-variation <= 0) printf("Error cambiar varianza o average\n" );
	speed = rand()%(max-min + 1) + min;

	return speed;
}

/*
	Gets the type of car:
	0: Radioactive
	1: Ambulance
	2: Normal
*/
int getType(int rad, int amb)
{
	int typeCar;
	int prob;

	prob = rand() % 101;
	if (prob < rad)
	{
		typeCar = 0;
	}
	else if (prob < (rad + amb))
	{
		typeCar = 1;
	}
	else 
	{
		typeCar = 2;
	}

	return typeCar;
}