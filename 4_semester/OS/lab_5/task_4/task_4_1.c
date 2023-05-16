#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int child(void);
int parent(pid_t);

/* Обработчик сигнала */
void rt_handler(int signum);

int main(){
  pid_t cpid;
  if ((cpid = fork()) == 0)
    child();
  else
    parent(cpid);
}

int parent(pid_t cpid){
    union sigval value;
    /* Спим, пока запускается дочерний процесс */
    sleep(3);
    for (int i = 1; i < 30; i+=3){
        /* Дополнительная информация для SIGRTMIN+i*/
        value.sival_int = i * 10;
        /* Отправка дочернему процессу SIGRTMIN + i*/
        sigqueue(cpid, SIGRTMIN, value);
        printf("sended signal %d value = %d\n", SIGRTMIN, value.sival_int);
    }
}

int child(void){
    siginfo_t siginfo;
    struct sigaction action;
    struct timespec tv;
    int count = 0;
    /* Устанавливаем SA_SIGINFO */
    //action.sa_flags = SA_SIGINFO;

    action.sa_sigaction = rt_handler;

    if (sigaction(SIGRTMIN, &action, NULL) == -1){
        perror("sigaction");
        return 0;
    }
    for(;;) {
        pause();
    }
}

/* Обработчик сигнала для SIGRTMIN */
void rt_handler(int signum){
    printf("received signal %d \n", signum);
}