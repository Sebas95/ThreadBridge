#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS    5
#define _OPEN_THREADS                                                           
#define _GNU_SOURCE

void *PrintHello(void *threadid)
{
  long tid;
  tid = (long)threadid;
  printf("Hello World! It's me, thread #%ld!\n", tid);
  pthread_exit(NULL);
}

void unit_test_createANDexit(void){
  //---------------------------------------------mythread_create;
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0;t<NUM_THREADS;t++){
    printf("In main: creating thread %ld\n", t);
    rc = mythread_create(&threads[t], NULL, PrintHello, (void *)t,1);
    if (rc){
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
      }
    }
  //---------------------------------------------mythread_exit;
  /* Last thing that main() should do */
  printf("Aqui terminando\n");
  mythread_end(NULL);
  printf("Aqui termino");
}

//---------------------------Join test

int unit_test_join(){
    pthread_t thread_id;
    char *b;
    int* thread_number = malloc(sizeof(void));
    *thread_number = 1;
    mythread_create (&thread_id, NULL,PrintHello, thread_number,1);

    mythread_join(thread_id,(void**)&b); //here we are reciving one pointer 
                                        //value so to use that we need double pointer 
    printf("Im at unit test join\n"); 
    free(b); // lets free the memory
    return 0;
}


//--------------------------------Yield test

/*
                                                                                                                             
void *thread(void *arg) {                                                       
                                                                                
  //A simple loop with only puts() would allow a thread to write several       
  //lines in a row.                                                               
  //With pthread_yield(), each thread gives another thread a chance before        
  //it writes its next line
                                                                                
  while (1) {                                                                   
    puts((char*) arg);                                                          
    pthread_yield();                                                        
  }                                                                             
}                                                                               
                                                                                
unit_test_yield() {                                                                        
  pthread_t t1, t2, t3;                                                         
                                                                                
  if (pthread_create(&t1, NULL, thread, "thread 1") != 0) {                     
    perror("pthread_create() error");                                           
    exit(1);                                                                    
  }                                                                             
                                                                                
  if (pthread_create(&t2, NULL, thread, "thread 2") != 0) {                     
    perror("pthread_create() error");                                           
    exit(2);                                                                    
  }                                                                             
                                                                                
  if (pthread_create(&t3, NULL, thread, "thread 3") != 0) {                     
    perror("pthread_create() error");                                           
    exit(3);                                                                    
  }                                                                             
                                                                                
  sleep(1);                                                                     
                                                                                
  exit(0); // this will tear all threads down 
}   

*/

//----------------------------------------Test detach

void *threadfunc(void *parm)
{
  printf("Inside secondary thread\n");
  return NULL;
}

int unit_test_detach()
{
  pthread_t             thread;
  int                   rc=0;


  printf("Create thread using attributes that allow join or detach\n");
  rc = mythread_create(&thread, NULL, threadfunc, NULL,1);
  //checkResults("pthread_create()\n", rc);

  sleep(5);

  printf("Detach the thread after it terminates\n");
  rc = mythread_detach(thread);
  //checkResults("pthread_detach()\n", rc);

  printf("Detach the thread again (expect ESRCH)\n");
  rc = mythread_detach(thread);
  if (rc < 0) {
    printf("Got an unexpected result! rc=%d\n",
           rc);
    exit(1);
  }
  printf("Second detach fails correctly\n");

  /* sleep() isn't a very robust way to wait for the thread */
  sleep(5);
  printf("Main completed\n");
  return 0;
}


int main(int argc, char *argv[])
{
  unit_test_createANDexit();
  //unit_test_join();
  //unit_test_yield();
  //unit_test_detach();
}
