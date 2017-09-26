#include "managerThread.h"
#include <stdio.h>

 int main() {

 	Nodo _temp, _buscado;

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

    _buscado = serchNodo(15);     // busca un nodo respecto a su dato.
	int position = serchNodoPosition(15);  //se busca una posicion con respecto a su elemento 
	int mayor = serchNodoPositionHigh(3);

	printf( "\nidTread del nodo retornado: %d\n", _buscado->idThread);
	printf( "\nla posicion es: %d\n", position);
	printf( "\nla posicion del mayor es: %d\n", mayor);

	insert(mayor, 5);
	mostrar_lista();
	insert(4,10);
	mostrar_lista();



 	return 0;
 }