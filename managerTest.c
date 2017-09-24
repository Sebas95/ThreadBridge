#include "managerThread.h"
#include <stdio.h>

 int main() {

 	Nodo _temp;

    push(3);
    mostrar_lista();
    
    push(4);
    mostrar_lista();

    append(1);
    mostrar_lista();

    append(2);
    mostrar_lista();

    push(10);
    mostrar_lista();

    append(15);
    mostrar_lista();
    _temp = pop();
    printf( "\nidTread del nodo retornado: %d\n", _temp->idThread);
    mostrar_lista();


 	return 0;
 }