#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int child(void);
int parent(pid_t);

/* Обработчик сигнала */
void rt_handler(int signum, siginfo_t *siginfo, void * extra);

int main(){
  pid_t cpid;
  if ((cpid = fork()) == 0)
    child();
  else
    parent(cpid);
}

/* Обработчик сигнала для SIGRTMIN */
void rt_handler(int signum, siginfo_t *siginfo, void * extra){
    printf("received signal %d value = %d\n", siginfo->si_signo, siginfo->si_int);
    sleep(1);
}

void (*mysig(int sig, void (*hnd)(int, siginfo_t*, void*)))(int, siginfo_t*, void*) {
    // надежная обработка сигналов
    struct sigaction act, oldact;
    act.sa_sigaction = hnd;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGINT);
    act.sa_flags = SA_SIGINFO;
    if (sigaction(sig, &act, &oldact) < 0) {
        perror("sigaction");
        exit(-1);
    }
    return oldact.sa_sigaction;
}

int parent(pid_t cpid){
    union sigval value;
    /* Спим, пока запускается дочерний процесс */
    sleep(3);
    /* Дополнительная информация для SIGRTMIN+i*/
    value.sival_int = -10;
    sigqueue(cpid, SIGUSR1, value);
    printf("sended signal %d value = %d\n", SIGUSR1, value.sival_int);
    sigqueue(cpid, SIGUSR1, value);
    printf("sended signal %d value = %d\n", SIGUSR1, value.sival_int);
   
    value.sival_int = SIGRTMAX;
    for (int i = SIGRTMAX; i > SIGRTMIN; i-=2){
        // Дополнительная информация для SIGRTMIN+i
        value.sival_int -= 2;
        // Отправка дочернему процессу SIGRTMIN + i
        sigqueue(cpid, i, value);
        printf("sended signal %d value = %d\n", i, value.sival_int);
    }
}

int child(void){
    mysig(SIGUSR1, rt_handler);
    for (int i = SIGRTMIN; i <= SIGRTMAX; i++){
        mysig(i, rt_handler);
    }
    for(;;) {
        pause();
    }
}