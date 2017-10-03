#include <stdlib.h>
#include "parser.h"
#include "scheduler.h"
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>

#include <string.h>
#include <stdio.h>



#define SCREEN_WIDTH 1564
#define SCREEN_HEIGHT 881
#define X_BASE 40
#define Y_BASE 20
#define WIDTH_BRIDGE 190
#define SPACE_BETWEEN_BRIDGE 30
#define HEIGHT_CAR 50
#define WIDTH_CAR 50



int largeBridge1 = 0;
int largeBridge2 = 0;
int largeBridge3 = 0;
int largeBridge4 = 0;

void * nullptr = NULL;

/**
*  Sends the parser configurations variables to scheduler programs
*
*/
void configure()
{

	int* type_sched = malloc(sizeof(int));
	getDataConfig();
 	
 	for (int i = 1; i < NUM_BRIDGES+1 ; ++i)
 	{	
 		Bridge _puente;
 		_puente = getVarBridge(i);
 		int* attr = malloc(sizeof(int)*9);
	 	int type_bridgeControl;
	 	
	 	char* schThreads = _puente->schThreads;
	 	char* schBridge = _puente->schBridge;
	 	int timeSemaphore = _puente->timeSemaphore;
	 	int kOfficer = _puente->kOfficer;
	 	int largeBridge = _puente->largeBridge;
	 	if (i == 1)
	 		largeBridge1 = largeBridge;
	 	else if (i == 2)
	 		largeBridge2 = largeBridge;
	 	else if (i == 3)
	 		largeBridge3 = largeBridge;
	 	else if (i == 4)
	 		largeBridge4 = largeBridge;
	 	int mediaExponential = _puente->mediaExponential;
		int averageSpeed = _puente->averageSpeed;
		int procAmbulances = _puente->procAmbulances;
		int procRadioactive = _puente->procRadioactive;
	 	
	 	if (strncmp(schBridge, "Official", 8) == 0)
	 		type_bridgeControl = Official;
	 	else if (strncmp(schBridge, "Jungle", 6) == 0)
	 		type_bridgeControl = Jungle;
	 	else if (strncmp(schBridge, "Semaphore", 9) == 0)
	 		type_bridgeControl = Semaphore;

	 	if (strncmp(schThreads, "SJF", 3) == 0)
	 		*type_sched = SJF; 
	 	else if (strncmp(schThreads, "Round_Robin", 11) == 0)
	 		*type_sched = ROUND_ROBIN;
	 	else if (strncmp(schThreads, "Real_time", 9) == 0)
	 		*type_sched = REAL_TIME;
	 	else if (strncmp(schThreads, "FIFO", 4) == 0)
	 		*type_sched = FIFO;
	 	else if (strncmp(schThreads, "Priority", 8) == 0)
	 		*type_sched = PRIORITY_QUEUE;
	 	
			/*printf("\n%d: schBridge: %s\n", i, _puente->schBridge);
 			printf("%d: timeSemaphore: %d\n", i, _puente->timeSemaphore);
 			printf("%d: kOfficer: %d\n", i, _puente->kOfficer);
 			printf("%d: schThreads: %s\n", i, _puente->schThreads);
 			printf("%d: largeBridge: %d\n", i, _puente->largeBridge);
 			printf("%d: mediaExponential: %d\n", i, _puente->mediaExponential);
 			printf("%d: averageSpeed: %d\n", i, _puente->averageSpeed);
 			printf("%d: procAmbulances: %d\n", i, _puente->procAmbulances);
 			printf("%d: procRadioactive: %d\n", i, _puente->procRadioactive);
 			*/
	 	attr[0] = type_bridgeControl;
	 	attr[1] = timeSemaphore;
	 	attr[2] = kOfficer;
	 	attr[3] = *type_sched;
	 	attr[4] = largeBridge;
	 	attr[5] = mediaExponential;
	 	attr[6] = averageSpeed;
	 	attr[7] = procAmbulances;
	 	attr[8] = procRadioactive;

	 	setParam(attr,i); //send configuration to scheduler
 	}
}

/**
*   Create threads for bridges' controls e.g officer, jungle law, semaphore 
*
*/
void configure_bridges()
{
	//init flags
	flag_bridge1 = (int*)malloc(sizeof(int));
	flag_bridge2 = (int*)malloc(sizeof(int));
	flag_bridge3 = (int*)malloc(sizeof(int));
	flag_bridge4 = (int*)malloc(sizeof(int));
	*flag_bridge1 = 1;
	*flag_bridge2 = 1;
	*flag_bridge3 = 1;
	*flag_bridge4 = 1;

	 bridge_1_in_use = (int*)malloc(sizeof(int));
     bridge_2_in_use = (int*)malloc(sizeof(int));
     bridge_3_in_use = (int*)malloc(sizeof(int));
     bridge_4_in_use = (int*)malloc(sizeof(int));
     *bridge_1_in_use = 0;
     *bridge_2_in_use = 0;
     *bridge_3_in_use = 0;
     *bridge_4_in_use = 0;

     carrosPasados1 = (int*)malloc(sizeof(int));
     carrosPasados2 = (int*)malloc(sizeof(int));
     carrosPasados3 = (int*)malloc(sizeof(int));
     carrosPasados4 = (int*)malloc(sizeof(int));
     *carrosPasados1 = 0;
     *carrosPasados2 = 0;
     *carrosPasados3 = 0;
     *carrosPasados4 = 0;

     flagSincronizacionOfficial1 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficial2 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficial3 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficial4 = (int*)malloc(sizeof(int));

     *flagSincronizacionOfficial1 = 1;
     *flagSincronizacionOfficial2 = 1;
     *flagSincronizacionOfficial3 = 1;
     *flagSincronizacionOfficial4 = 1;

     flagSincronizacionOfficialScheduler1 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficialScheduler2 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficialScheduler3 = (int*)malloc(sizeof(int));
     flagSincronizacionOfficialScheduler4 = (int*)malloc(sizeof(int)); 

     *flagSincronizacionOfficialScheduler1 = 0;
     *flagSincronizacionOfficialScheduler2 = 0;
     *flagSincronizacionOfficialScheduler3 = 0;
     *flagSincronizacionOfficialScheduler4 = 0;

	for (int i = 1; i < NUM_BRIDGES + 1; ++i)
 	{
		Bridge _puente;
	 	_puente = getVarBridge(i);
	 	char* schBridge = _puente->schBridge;
	 	pthread_t* temp_b_control = malloc(sizeof(pthread_t));


	 	if      (strncmp(schBridge, "Official", 8) == 0)
	 	{
	 		if(i==1) pthread_create(temp_b_control, NULL, runOfficer, (void *)flag_bridge1);
	 		if(i==2) pthread_create(temp_b_control, NULL, runOfficer, (void *)flag_bridge2);
	 		if(i==3) pthread_create(temp_b_control, NULL, runOfficer, (void *)flag_bridge3);
	 		if(i==4) pthread_create(temp_b_control, NULL, runOfficer, (void *)flag_bridge4);
	 		
	 	}
		else if (strncmp(schBridge, "Jungle", 6) == 0)
		{
			if(i==1) pthread_create(temp_b_control, NULL, runJungleLaw, (void *)flag_bridge1);
	 		if(i==2) pthread_create(temp_b_control, NULL, runJungleLaw, (void *)flag_bridge2);
	 		if(i==3) pthread_create(temp_b_control, NULL, runJungleLaw, (void *)flag_bridge3);
	 		if(i==4) pthread_create(temp_b_control, NULL, runJungleLaw, (void *)flag_bridge4);
		}
		else if (strncmp(schBridge, "Semaphore", 9) == 0)
		{ 	
			if(i==1) pthread_create(temp_b_control, NULL, runSemaphore, (void *)flag_bridge1);
	 		if(i==2) pthread_create(temp_b_control, NULL, runSemaphore, (void *)flag_bridge2);
	 		if(i==3) pthread_create(temp_b_control, NULL, runSemaphore, (void *)flag_bridge3);
	 		if(i==4) pthread_create(temp_b_control, NULL, runSemaphore, (void *)flag_bridge4);
 		}	
    }
}




/*
 * Loads an bridge into a texture on the rendering device
 * @param file The bridge file to load
 * @param ren The renderer to load the texture onto
 * @return the loaded texture, or nullptr if something went wrong.
 */
SDL_Texture* loadTexture(const char* file, SDL_Renderer *ren){
	SDL_Texture *texture = IMG_LoadTexture(ren, file);
	if (texture == nullptr){
		printf("Error in loadTexture\n");
	}
	return texture;
}
/*
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
 * width and height
 * @param tex The source texture we want to draw
 * @param rend The renderer we want to draw too
 * @param x The x coordinate to draw too
 * @param y The y coordinate to draw too
 * @param w The width of the texture to draw
 * @param h The height of the texture to draw
 */
void renderTextureFull(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}
/*
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
 * the texture's width and height
 * @param tex The source texture we want to draw
 * @param rend The renderer we want to draw too
 * @param x The x coordinate to draw too
 * @param y The y coordinate to draw too
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderTextureFull(tex, ren, x, y, w, h);
}


int runGUI()
{
	//Start up SDL and make sure it went ok
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Error in SDL_Init\n");
		return 1;
	}

	//Setup our window and renderer
	SDL_Window *window = SDL_CreateWindow("Main Window", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		printf("Error in CreateWindow\n");
		SDL_Quit();
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		printf("Error in CreateRenderer\n");
		//cleanup(window);
		SDL_Quit();
		return 1;
	}

	//The textures we'll be using
	const char* resPathBack = "./img/background.png";
	const char* resPathBridge = "./img/bridge.png";
	const char* resPathCarRight = "./img/carRight.png";
	const char* resPathCarLeft = "./img/carLeft.png";
	const char* resPathAmbulanceRight = "./img/ambulanceRight.png";
	const char* resPathAmbulanceLeft = "./img/ambulanceLeft.png";
	const char* resPathRadioactiveRight = "./img/radioactiveRight.png";
	const char* resPathRadioactiveLeft = "./img/radioactiveLeft.png";

	SDL_Texture *background = loadTexture(resPathBack, renderer);
	SDL_Texture *bridge = loadTexture(resPathBridge, renderer);
	SDL_Texture *carRight = loadTexture(resPathCarRight, renderer);
	SDL_Texture *carLeft = loadTexture(resPathCarLeft, renderer);
	SDL_Texture *ambulanceRight = loadTexture(resPathAmbulanceRight, renderer);
	SDL_Texture *ambulanceLeft = loadTexture(resPathAmbulanceLeft, renderer);
	SDL_Texture *radioactiveRight = loadTexture(resPathRadioactiveRight, renderer);
	SDL_Texture *radioactiveLeft = loadTexture(resPathRadioactiveLeft, renderer);
	//Make sure they both loaded ok
	if (background == nullptr || bridge == nullptr){
		//cleanup(background, bridge, renderer, window);
		SDL_Quit();
		return 1;
	}

	int* dataBridge1;
	int* dataBridge2;
	int* dataBridge3;
	int* dataBridge4;
	
	//A sleepy rendering loop
	while (true) {
		//Clear the window
		SDL_RenderClear(renderer);

		renderTexture(background, renderer, 0, 0);

		//Draw our bridge in the center of the window
		//We need the foreground bridge's width to properly compute the position
		//of it's top left corner so that the bridge will be centered
		int x1 = X_BASE;
		int y1 = Y_BASE;
		int largeBridgeLocal1 = 500 + 100*largeBridge1;
		renderTextureFull(bridge, renderer, x1, y1, largeBridgeLocal1, WIDTH_BRIDGE);

		int x2 = X_BASE;
		int y2 = y1 + WIDTH_BRIDGE + SPACE_BETWEEN_BRIDGE;
		int largeBridgeLocal2 = 500 + 100*largeBridge2;
		renderTextureFull(bridge, renderer, x2, y2, largeBridgeLocal2, WIDTH_BRIDGE);

		int x3 = X_BASE;
		int y3 = y2 + WIDTH_BRIDGE + SPACE_BETWEEN_BRIDGE;
		int largeBridgeLocal3 = 500 + 100*largeBridge3;
		renderTextureFull(bridge, renderer, x3, y3, largeBridgeLocal3, WIDTH_BRIDGE);

		int x4 = X_BASE;
		int y4 = y3 + WIDTH_BRIDGE + SPACE_BETWEEN_BRIDGE;
		int largeBridgeLocal4 = 500 + 100*largeBridge4;
		renderTextureFull(bridge, renderer, x4, y4, largeBridgeLocal4, WIDTH_BRIDGE);

		printf("Llego2\n");
		dataBridge1 = getDataBridge(1);
		printf("Llego3\n");
		dataBridge2 = getDataBridge(2);
		dataBridge3 = getDataBridge(3);
		dataBridge4 = getDataBridge(4);

		//////////// PARA PUENTE 1 ///////////
		int xCar1 = dataBridge1[2];
		int yCar1 = y1;
		if (dataBridge1[0] == 0 && dataBridge1[0] == 11)
		{
			renderTextureFull(radioactiveRight, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge1[0] == 0 && dataBridge1[0] == 12)
		{
			renderTextureFull(radioactiveLeft, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge1[0] == 1 && dataBridge1[0] == 11)
		{
			renderTextureFull(ambulanceRight, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge1[0] == 1 && dataBridge1[0] == 12)
		{
			renderTextureFull(ambulanceLeft, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge1[0] == 2 && dataBridge1[0] == 11)
		{
			renderTextureFull(carRight, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge1[0] == 2 && dataBridge1[0] == 12)
		{
			renderTextureFull(carLeft, renderer, xCar1, yCar1, HEIGHT_CAR, WIDTH_CAR);
		}
		//////////// FIN PUENTE 1 /////////////

		//////////// PARA PUENTE 2 ///////////
		int xCar2 = dataBridge2[2];
		int yCar2 = y2;
		if (dataBridge2[0] == 0 && dataBridge2[0] == 11)
		{
			renderTextureFull(radioactiveRight, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge2[0] == 0 && dataBridge2[0] == 12)
		{
			renderTextureFull(radioactiveLeft, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge2[0] == 1 && dataBridge2[0] == 11)
		{
			renderTextureFull(ambulanceRight, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge2[0] == 1 && dataBridge2[0] == 12)
		{
			renderTextureFull(ambulanceLeft, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge2[0] == 2 && dataBridge2[0] == 11)
		{
			renderTextureFull(carRight, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge2[0] == 2 && dataBridge2[0] == 12)
		{
			renderTextureFull(carLeft, renderer, xCar2, yCar2, HEIGHT_CAR, WIDTH_CAR);
		}
		//////////// FIN PUENTE 2 /////////////

		//////////// PARA PUENTE 3 ///////////
		int xCar3 = dataBridge3[2];
		int yCar3 = y3;
		if (dataBridge3[0] == 0 && dataBridge3[0] == 11)
		{
			renderTextureFull(radioactiveRight, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 0 && dataBridge3[0] == 12)
		{
			renderTextureFull(radioactiveLeft, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 1 && dataBridge3[0] == 11)
		{
			renderTextureFull(ambulanceRight, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 1 && dataBridge3[0] == 12)
		{
			renderTextureFull(ambulanceLeft, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 2 && dataBridge3[0] == 11)
		{
			renderTextureFull(carRight, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 2 && dataBridge3[0] == 12)
		{
			renderTextureFull(carLeft, renderer, xCar3, yCar3, HEIGHT_CAR, WIDTH_CAR);
		}
		//////////// FIN PUENTE 3 /////////////

		//////////// PARA PUENTE 4 ///////////
		int xCar4 = dataBridge4[2];
		int yCar4 = y4;
		if (dataBridge4[0] == 0 && dataBridge4[0] == 11)
		{
			renderTextureFull(radioactiveRight, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge4[0] == 0 && dataBridge4[0] == 12)
		{
			renderTextureFull(radioactiveLeft, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge3[0] == 1 && dataBridge3[0] == 11)
		{
			renderTextureFull(ambulanceRight, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge4[0] == 1 && dataBridge4[0] == 12)
		{
			renderTextureFull(ambulanceLeft, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge4[0] == 2 && dataBridge4[0] == 11)
		{
			renderTextureFull(carRight, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		} else if (dataBridge4[0] == 2 && dataBridge4[0] == 12)
		{
			renderTextureFull(carLeft, renderer, xCar4, yCar4, HEIGHT_CAR, WIDTH_CAR);
		}
		//////////// FIN PUENTE 4 /////////////



		//Update the screen
		SDL_RenderPresent(renderer);
		//Take a quick break after all that hard work
		SDL_Delay(10);
	}

	//Destroy the various items
	//cleanup(background, bridge, renderer, window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}











int main(int argc, char const *argv[])
{	

	struct thread_data *td1Left = malloc(sizeof(struct thread_data));
	struct thread_data *td2Left = malloc(sizeof(struct thread_data));
	struct thread_data *td3Left = malloc(sizeof(struct thread_data));
	struct thread_data *td4Left = malloc(sizeof(struct thread_data));

	struct thread_data *td1Right = malloc(sizeof(struct thread_data));
	struct thread_data *td2Right = malloc(sizeof(struct thread_data));
	struct thread_data *td3Right = malloc(sizeof(struct thread_data));
	struct thread_data *td4Right = malloc(sizeof(struct thread_data));


	td1Left->thread_initial_id = 0*NUM_CARS;
	td2Left->thread_initial_id = 1*NUM_CARS;
	td3Left->thread_initial_id = 2*NUM_CARS;
	td4Left->thread_initial_id = 3*NUM_CARS;

	td1Right->thread_initial_id = 4*NUM_CARS;
	td2Right->thread_initial_id = 5*NUM_CARS;
	td3Right->thread_initial_id = 6*NUM_CARS;
	td4Right->thread_initial_id = 7*NUM_CARS;

	td1Left->numberBridge = 11;
	td2Left->numberBridge = 21;
	td3Left->numberBridge = 31;
	td4Left->numberBridge = 41;

	td1Right->numberBridge = 12;
	td2Right->numberBridge = 22;
	td3Right->numberBridge = 32;
	td4Right->numberBridge = 42;


	//int type_sched = configure();
	srand(time(NULL));
	configure();
	configure_bridges();
	initColas();
	//long* t = (long*)malloc( sizeof(long));
	//*t = 0;
	pthread_t generator_izq1;
	pthread_t generator_izq2;
	pthread_t generator_izq3;
	pthread_t generator_izq4;

	pthread_t generator_der1;
	pthread_t generator_der2;
	pthread_t generator_der3;
	pthread_t generator_der4;



	pthread_create(&generator_izq1, NULL, generateCars, (void *)td1Left);
	usleep(100);
	pthread_create(&generator_izq2, NULL, generateCars, (void *)td2Left);
	usleep(100);
	pthread_create(&generator_izq3, NULL, generateCars, (void *)td3Left);
	usleep(100);
	pthread_create(&generator_izq4, NULL, generateCars, (void *)td4Left);
	usleep(100);

	pthread_create(&generator_der1, NULL, generateCars, (void *)td1Right);
	usleep(100);
	pthread_create(&generator_der2, NULL, generateCars, (void *)td2Right);
	usleep(100);
	pthread_create(&generator_der3, NULL, generateCars, (void *)td3Right);
	usleep(100);
	pthread_create(&generator_der4, NULL, generateCars, (void *)td4Right);
	usleep(100);

	//create thread of scheduler
	pthread_t thread_scheduler;
	int* unused = (int*)malloc(sizeof(int));
	*unused = 0;
	pthread_create(&thread_scheduler, NULL, run_sched, (void*)unused);
	
	//create thread of the GUI
	pthread_t thread_GUI;
	//int* unused2 = (int*)malloc(sizeof(int));
	//*unused2 = 0;
	pthread_create(&thread_GUI, NULL, runGUI, (void*)NULL);


  
	pthread_exit(NULL); //the last this main should do
	return 0;
}



//https://www.xmple.com/wallpaper/blue-white-stripes-lines-streaks-1800x2880-c2-0000cd-ffffff-l2-265-530-a-270-f-1.svg