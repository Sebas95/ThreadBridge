#include "arduino-serial-lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fd = 0;
	char puertoUSB[12]  = "/dev/ttyACM0";
	//printf("%s\n",puertoUSB);
    fd = serialport_init(puertoUSB, 9600);
    if( fd==-1 ) printf("couldn't open port");
    serialport_write(fd, "1;4;8;12;2;2;6;22;0;7;10;31;");  //mando el tipo de carro
    serialport_flush(fd);
    serialport_write(fd, "1;5;8;12;2;3;6;22;0;6;10;31;");  //mando el tipo de carro
    serialport_flush(fd);
    serialport_write(fd, "1;6;8;12;2;4;6;22;0;5;10;31;");  //mando el tipo de carro
    serialport_flush(fd);
    serialport_write(fd, "1;7;8;12;2;5;6;22;0;4;10;31;");  //mando el tipo de carro
    serialport_flush(fd);
    //serialport_write(fd, "10000"); // mando la velocidad 
    //serialport_flush(fd); 
    //serialport_write(fd, "10"); // mando el largo del puente
    //serialport_flush(fd);
    //serialport_write(fd, "2");   //mando direccion
    //if(!quiet) printf("opened port %s\n",serialport);	serialport_flush(fd);
	return 0;
}