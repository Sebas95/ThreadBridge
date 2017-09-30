#include "managerThread.h"
#include <stdio.h>


void unitTest_append(){


    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------Prueba del append-------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");


    Cola cola1 = (Cola) malloc(sizeof(Cola));
    cola1 = getANewCola();
    Cola cola2 = (Cola) malloc(sizeof(Cola));
    cola2 = getANewCola();
    pthread_t* thread = malloc(sizeof(pthread_t));

    append(1,0,0,0,0, thread,cola1);
    append(2,0,0,0,0, thread,cola2);
    printf("-------------Cola1--------------");
    mostrar_lista(cola1);
    printf("-------------Cola2--------------");
    mostrar_lista(cola2);

    append(3,0,0, 0, 0, thread,cola1);
    append(4,0,0, 0, 0, thread,cola2);
    printf("-------------Cola1--------------");
    mostrar_lista(cola1);
    printf("-------------Cola2--------------");
    mostrar_lista(cola2);
    
    append(5,0,0, 0, 0, thread,cola1);
    append(6,0,0, 0, 0, thread,cola2);
    printf("-------------Cola1--------------");
    mostrar_lista(cola1);
    printf("-------------Cola2--------------");
    mostrar_lista(cola2);

};

void unitTest_pop(){

    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("---------------Prueba del pop-----------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");

    Cola cola = (Cola) malloc(sizeof(Cola));
    cola = getANewCola();
    Nodo nodoReturned = malloc(sizeof(Nodo));
    pthread_t* thread = malloc(sizeof(pthread_t));

    append(2,0,0,0,0, thread,cola);
    mostrar_lista(cola);

    append(3,0,0, 0, 0, thread,cola);
    mostrar_lista(cola);

    append(5,0,0, 0, 0, thread,cola);
    mostrar_lista(cola);
    nodoReturned = pop(cola);
    printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
    mostrar_lista(cola);
    nodoReturned = pop(cola);
    printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
    mostrar_lista(cola);
    nodoReturned = pop(cola);
    printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
    mostrar_lista(cola);
    nodoReturned = pop(cola);
    printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
    mostrar_lista(cola);
    nodoReturned = pop(cola);
    printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
    mostrar_lista(cola);
    nodoReturned = pop(cola);
    printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
    mostrar_lista(cola);
    printf( "\n--------------------Cola despues del pop :");
    mostrar_lista(cola);

}


void unitTest_insert(){
    Cola cola = (Cola) malloc(sizeof(Cola));
    cola = getANewCola();
    pthread_t* thread = malloc(sizeof(pthread_t));
    
    insert(0,55,0,0, 0, 0, thread,cola);
    printf("\nInsertando en la posicion 0\n");
    mostrar_lista(cola);
    append(77,0,0, 0, 0, thread,cola);
    mostrar_lista(cola);
    printf("\nInsertando en la posicion 1\n");
    insert(1,44,0,0, 0, 0, thread,cola);
    mostrar_lista(cola);
    printf("\nInsertando en la posicion 2\n");
    insert(2,69,0,0, 0, 0, thread,cola);
    mostrar_lista(cola);
    printf("\nInsertando en la posicion 1\n");
    insert(1,1111,0,0, 0, 0, thread,cola);
    mostrar_lista(cola);
}


void unitTest_push(){

    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("---------------Prueba del push----------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");

    Cola cola = (Cola) malloc(sizeof(Cola));
    cola = getANewCola();
    pthread_t* thread = malloc(sizeof(pthread_t));
    push(1,3,0,0,0, thread,cola);
    push(2,3,0,0,0, thread,cola);
    push(3,3,0,0,0, thread,cola);
    push(4,3,0,0,0, thread,cola);
    push(5,3,0,0,0, thread,cola);
    mostrar_lista(cola);
    push(111,3,0,0,0, thread,cola);
    mostrar_lista(cola);
}


void unitTest_searchNodo(){
    Cola cola = (Cola) malloc(sizeof(Cola));
    cola = getANewCola();
    pthread_t* thread = malloc(sizeof(pthread_t));

    append(10,0,0,0,0, thread,cola);
    append(11,0,0,0,0, thread,cola);
    append(22,0,0,0,0, thread,cola);
    append(33,0,0,0,0, thread,cola);
    append(44,0,0,0,0, thread,cola);
    append(55,0,0,0,0, thread,cola);
    append(88,0,0,0,0, thread,cola);

    Nodo nodoBuscado = searchNodo(11,cola);     // busca un nodo respecto a su dato.
    printf("Nodo buscado: %ld\n",nodoBuscado->idThread);
}


void unitTest_searchNodoPositionId(){
    Cola cola = (Cola) malloc(sizeof(Cola));
    cola = getANewCola();
    pthread_t* thread = malloc(sizeof(pthread_t));
    //---------------------0
    append(10,0,0,0,0, thread,cola);
    //---------------------1
    append(11,0,0,0,0, thread,cola);
    //---------------------2
    append(22,0,0,0,0, thread,cola);
    //---------------------3
    append(33,0,0,0,0, thread,cola);
    //---------------------4
    append(44,0,0,0,0, thread,cola);
    //---------------------5
    append(55,0,0,0,0, thread,cola);
    //---------------------6
    append(88,0,0,0,0, thread,cola);
    //---------------------7
    append(2,0,0,0,0, thread,cola);
    //---------------------8
    append(5,0,0,0,0, thread,cola);

    int position = 0; 
    position = searchPositionId(55,cola);
    printf("Posicion del nodo con id 55: %d\n",position);

    position = searchPositionId(11,cola);
    printf("Posicion del nodo con id 11: %d\n",position);

    position = searchPositionId(33,cola);
    printf("Posicion del nodo con id 33: %d\n",position);

    position = searchPositionId(88,cola);
    printf("Posicion del nodo con id 88: %d\n",position);

    position = searchPositionId(88,cola);
    printf("Posicion del nodo con id 88: %d\n",position);

    position = searchPositionId(10,cola);
    printf("Posicion del nodo con id 10: %d\n",position);

    position = searchPositionId(5,cola);
    printf("Posicion del nodo con id 5: %d\n",position);

    position = searchPositionId(2,cola);
    printf("Posicion del nodo con id 2: %d\n",position);

}


void unitTest_searchNodoPositionSpeed(){
    Cola cola = (Cola) malloc(sizeof(Cola));
    cola = getANewCola();
    pthread_t* thread = malloc(sizeof(pthread_t));
    //---------------------0
    append(10,0,10000,0,0, thread,cola);
    //---------------------1
    append(11,0,11000,0,0, thread,cola);
    //---------------------2
    append(22,0,21000,0,0, thread,cola);
    //---------------------3
    append(33,0,330,0,0, thread,cola);
    //---------------------4
    append(44,0,444,0,0, thread,cola);
    //---------------------5
    append(55,0,888,0,0, thread,cola);
    //---------------------6
    append(9012,9012,9012,9012,9012, thread,cola);

    int position = 0; 
    int speed = 0;

    speed = 9012;
    position = searchPositionSpeed(speed,cola);
    printf("Posicion del nodo con velocidad %d: %d\n",speed,position);

    speed = 444;
    position = searchPositionSpeed(speed,cola);
    printf("Posicion del nodo con velocidad %d: %d\n",speed,position);

    speed = 888;
    position = searchPositionSpeed(speed,cola);
    printf("Posicion del nodo con velocidad %d: %d\n",speed,position);

    speed = 210;
    position = searchPositionSpeed(speed,cola);
    printf("Posicion del nodo con velocidad %d: %d\n",speed,position);

    speed = 9012;
    position = searchPositionSpeed(speed,cola);
    printf("Posicion del nodo con velocidad %d: %d\n",speed,position);

    speed = 9012;
    position = searchPositionSpeed(speed,cola);
    printf("Posicion del nodo con velocidad %d: %d\n",speed,position);

    speed = 100;
    position = searchPositionSpeed(speed,cola);
    printf("Posicion del nodo con velocidad %d: %d\n",speed,position);
}

void unitTest_searchPositionPriority(){
    Cola cola = (Cola) malloc(sizeof(Cola));
    cola = getANewCola();

    Cola cola2 = (Cola) malloc(sizeof(Cola));
    cola2 = getANewCola();
    pthread_t* thread = malloc(sizeof(pthread_t));

    append(10,0,0,10,0,thread,cola);
    append(11,0,0,22,0,thread,cola);
    append(22,0,0,30,0,thread,cola);
    append(33,0,0,55,0,thread,cola);
    append(44,0,0,200,0,thread,cola);
    append(55,0,0,300,0,thread,cola);
    append(88,0,0,400,0,thread,cola);

    append(10,0,0,1,0,thread,cola2);
    append(11,0,0,2,0,thread,cola2);
    append(22,0,0,3,0,thread,cola2);
    append(33,0,0,5,0,thread,cola2);
    append(44,0,0,6,0,thread,cola2);
    append(55,0,0,7,0,thread,cola2);
    append(88,0,0,8,0,thread,cola2);

    int mayor = 0;

    //---------------------------- Cola 1
    mayor = searchPositionPriority(14,cola);  //se busca una posicion con respecto a su elemento 
    printf("Cola1: Posicion del nodo: %d\n",mayor);

    //---------------------------- Cola 2   

    mayor = searchPositionPriority(7,cola2);  //se busca una posicion con respecto a su elemento 
    printf("Cola2: Posicion del nodo: %d\n",mayor);     

    //---------------------------- Cola 1

    mayor = searchPositionPriority(24,cola);  //se busca una posicion con respecto a su elemento 
    printf("Cola1: Posicion del nodo: %d\n",mayor); 

    //---------------------------- Cola 2   

    mayor = searchPositionPriority(5,cola2);  //se busca una posicion con respecto a su elemento 
    printf("Cola2: Posicion del nodo: %d\n",mayor); 

    //---------------------------- Cola 1

    mayor = searchPositionPriority(40,cola);  //se busca una posicion con respecto a su elemento 
    printf("Cola1: Posicion del nodo: %d\n",mayor);

    //---------------------------- Cola 2   

    mayor = searchPositionPriority(6,cola2);  //se busca una posicion con respecto a su elemento 
    printf("Cola2: Posicion del nodo: %d\n",mayor); 

    //---------------------------- Cola 1

    mayor = searchPositionPriority(301,cola);  //se busca una posicion con respecto a su elemento 
    printf("Cola1: Posicion del nodo:  %d\n",mayor); 

    //---------------------------- Cola 2   

    mayor = searchPositionPriority(1,cola2);  //se busca una posicion con respecto a su elemento 
    printf("Cola2: Posicion del nodo:  %d\n",mayor); 

}

void giveMeStatus(int listaVaciaReturned){
    if(listaVaciaReturned == 0){
        printf("-----La cola no esta vacia\n");    
    }
    else{
        printf("-----La cola esta vacia\n");
    }
}

void unitTest_colaVacia(){
        int listaVaciaReturned = 0;
        Cola cola = (Cola) malloc(sizeof(Cola));
        cola = getANewCola();
        pthread_t* thread = malloc(sizeof(pthread_t));
        append(1,0,0,0,0, thread,cola);
        listaVaciaReturned = listaVacia(cola);
        giveMeStatus(listaVaciaReturned);
        Nodo nodoReturned = malloc(sizeof(Nodo));
        append(2,0,0,0,0, thread,cola);
        mostrar_lista(cola);

        append(3,0,0, 0, 0, thread,cola);
        mostrar_lista(cola);

        append(5,0,0, 0, 0, thread,cola);
        mostrar_lista(cola);
        nodoReturned = pop(cola);
        printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
        listaVaciaReturned = listaVacia(cola);
        giveMeStatus(listaVaciaReturned);
        mostrar_lista(cola);
        nodoReturned = pop(cola);
        printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
        listaVaciaReturned = listaVacia(cola);
        giveMeStatus(listaVaciaReturned);
        mostrar_lista(cola);
        nodoReturned = pop(cola);
        printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
        listaVaciaReturned = listaVacia(cola);
        giveMeStatus(listaVaciaReturned);
        mostrar_lista(cola);
        nodoReturned = pop(cola);
        printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
        listaVaciaReturned = listaVacia(cola);
        giveMeStatus(listaVaciaReturned);
        printf("listaVaciaReturned: %d\n", listaVaciaReturned);


        mostrar_lista(cola);
        nodoReturned = pop(cola);
        printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
        listaVaciaReturned = listaVacia(cola);
        giveMeStatus(listaVaciaReturned);
        mostrar_lista(cola);
        nodoReturned = pop(cola);
        printf("\n--------------------Id nodo retornado: %ld\n", nodoReturned->idThread);
        listaVaciaReturned = listaVacia(cola);
        giveMeStatus(listaVaciaReturned);
        mostrar_lista(cola);
        printf( "\n--------------------Cola despues del pop :");
        listaVaciaReturned = listaVacia(cola);
        giveMeStatus(listaVaciaReturned);
        mostrar_lista(cola);
    }



 int main() {
    unitTest_append();
    //unitTest_pop();
    //unitTest_insert();
    //unitTest_searchNodo();
    //unitTest_searchNodoPositionId();
    //unitTest_searchNodoPositionSpeed();
    //unitTest_push();
    //unitTest_searchPositionPriority();
    //unitTest_searchPositionPriority();
    //unitTest_colaVacia();
 	return 0;
 }