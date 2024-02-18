#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE

pthread_t thread1;
sigset_t set;
int thread_id;
void *thread_func(void *args) {
    thread_id = gettid();
    printf("Thread started. %d\n", thread_id);
    while(1) {
        int signum;
        sigwait(&set, &signum);
        printf("Received signal %d\n", signum);
        if (signum == SIGUSR1){
            break;
        }
    }
    sleep(2);
    printf("ending thread!\n");
    pthread_exit(NULL);
}

void sig_handler(int signum){
}

int main() {
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, SIG_IGN);
    sigemptyset(&set);
    sigaddset(&set, SIGTERM);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGUSR1);
    if(pthread_create(&thread1, NULL, thread_func, NULL)) {
        printf("Error creating thread\n");
        return 1;
    }
    printf("Main thread started. PID: %d\n", getpid());
    int i = 0;
    pthread_join(thread1, NULL);
    printf("main is ending\n");
    return 0;
}