testGenerator:
		gcc -W testGenerator.c carsGenerator.c -o testGenerator -lm

testParser:
		gcc -W testParser.c parser.c -o testParser

clean:
		rm testG