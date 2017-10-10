testManagerThread:
		gcc -W managerTest.c managerThreads.c -o testManager 

testGenerator:
		gcc -W testGenerator.c carsGenerator.c -o testGenerator -lm

testParser:
		gcc -W testParser.c parser.c -o testParser

testScheduler:
		gcc -Wall -o  scheduler scheduler.c bridge.c managerThreads.c parser.c carsGenerator.c -I ~/glibc-2.23/build/usr/include -L ~/glibc-2.23/build/usr/lib -lpthread -lm
		export LD_LIBRARY_PATH=~/glibc-2.23/build/usr/lib

main:

		gcc -Wall main.c parser.c scheduler.c car.c carsGenerator.c bridge.c managerThreads.c -o main -I ~/glibc-2.23/build/usr/include -L ~/glibc-2.23/build/usr/lib -lpthread -lm -I/usr/local/include/SDL2 -L/usr/local/lib/pkgconfig/ $(shell pkg-config --cflags --libs sdl2) -std=gnu99 -lSDL2_image 
		export LD_LIBRARY_PATH=~/glibc-2.23/build/usr/lib

testGui:
		gcc -Wall main.c parser.c scheduler.c car.c carsGenerator.c bridge.c managerThreads.c arduino-serial-lib.c -o main -I ~/glibc-2.23/build/usr/include -L ~/glibc-2.23/build/usr/lib -lpthread -lm -I/usr/local/include/SDL2 -L/usr/local/lib/pkgconfig/ $(shell pkg-config --cflags --libs sdl2)  -std=gnu99 -lSDL2_image 
		export LD_LIBRARY_PATH=~/glibc-2.23/build/usr/lib

clean:
		rm testG
