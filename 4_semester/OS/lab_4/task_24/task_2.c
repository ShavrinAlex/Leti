#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <errno.h>

long long int OPS_AMOUNT = 10;

void* func_fifo(int arg) {
    int marker = *((int*))arg;
    int dummy = 0;
    for (int i = 0; i < OPS_AMOUNT; i++) {
        dummy++;
    }
    printf("FIFO : %d\n", marker);
    pthread_exit(NULL);
}

void* func_rr(int arg) {
    int marker = *((int*))arg; 
    int dummy = 0;
   for (int i = 0; i < OPS_AMOUNT; i++) {
        dummy++;
    }
    printf("RR : %d\n", marker);
    pthread_exit(NULL);
}

int main() {
    const int NUM_THREADS = 12;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attrs[NUM_THREADS];
    struct sched_param params[NUM_THREADS];
    int priorityFIFO = 50;
    int priorityRR = 50;
    for (int i = 0; i < NUM_THREADS; i++) {
        
        pthread_attr_init(&attrs[i]);
        pthread_attr_setinheritsched(&attrs[i], PTHREAD_EXPLICIT_SCHED);
        if (i % 2 == 0){
         params[i].sched_priority = priorityRR;
         pthread_attr_setschedpolicy(&attrs[i], SCHED_RR);
         pthread_attr_setschedparam(&attrs[i], &params[i]);
         pthread_create(&threads[i], &attrs[i], func_rr, &i);
         }
        else{
         params[i].sched_priority = priorityFIFO;
         pthread_attr_setschedpolicy(&attrs[i], SCHED_FIFO);
         pthread_attr_setschedparam(&attrs[i], &params[i]);
         pthread_create(&threads[i], &attrs[i], func_fifo, &i);
      }
      /*
         params[i].sched_priority = priorityRR;
         pthread_attr_init(&attrs[i]);
         pthread_attr_setschedpolicy(&attrs[i], SCHED_RR);
         pthread_attr_setschedparam(&attrs[i], &params[i]);
         pthread_create(&threads[i], &attrs[i], func_rr, i); 
        */
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished\n");

    return 0;
}