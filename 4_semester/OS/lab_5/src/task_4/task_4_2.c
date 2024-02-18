#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int child(void);
int parent(pid_t);

int main(){
  pid_t cpid;
  if ((cpid = fork()) == 0)
    child();
  else
    parent(cpid);
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

/* Обработчик сигнала для SIGRTMIN */
void rt_handler(int signum, siginfo_t *siginfo, void * extra){
    printf("received signal %d value = %d\n", siginfo->si_signo, siginfo->si_int);
    sleep(1);
    printf("processed signal %d value = %d\n", siginfo->si_signo, siginfo->si_int);
}

int parent(pid_t cpid){
    //Ждем 3 сек пока запустится дочерний процесс
    sleep(3);
    union sigval value;
    for (int i = 12; i > -1; i--){
        /* Дополнительная информация для SIGRTMIN+i*/
        value.sival_int = i * 10;
        /* Отправка дочернему процессу */
        sigqueue(cpid, SIGRTMIN, value);
        printf("sended signal %d value = %d\n", SIGRTMIN, value.sival_int);
    }
}

int child(void){
    mysig(SIGRTMIN, rt_handler);

    for(;;) {
        pause();
    }
}