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

		gcc -Wall main.c parser.c scheduler.c car.c carsGenerator.c bridge.c managerThreads.c -o main -std=c99 -I ~/glibc-2.23/build/usr/include -L ~/glibc-2.23/build/usr/lib -lpthread -lm
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/glibc-2.23/build/usr/lib

clean:
		rm testG
