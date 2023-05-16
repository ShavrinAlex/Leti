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

int parent(pid_t cpid){
    union sigval value;
    /* -------- НАЧАЛО 1-ой ЧАСТИ  ----------- */

     /* Спим, пока запускается дочерний процесс */
    sleep(3);
    /* Дополнительная информация для SIGRTMIN */
    value.sival_int = 1;
    /* Отправка дочернему процессу SIGRTMIN */
    sigqueue(cpid, SIGRTMIN+1, value);
    value.sival_int = 2;
    sigqueue(cpid, SIGRTMIN+2, value);
    value.sival_int = 3;
    sigqueue(cpid, SIGRTMIN+3, value);
    value.sival_int = 1;
    sigqueue(cpid, SIGRTMIN+1, value);
    value.sival_int = 0;
    sigqueue(cpid, SIGRTMIN, value);
    
    /* Отправка дочернему процессу SIGRTMIN+1 */
    //sleep(30);
    //value.sival_int = 2;
    //sigqueue(cpid, SIGRTMIN+1, value);
    /* -------- НАЧАЛО 2-ой ЧАСТИ  ----------- */
    /* Наконец, посылаем SIGRTMIN ещё раз */
   // sleep(3);
    //value.sival_int = 3;
    //sigqueue(cpid, SIGRTMIN, value);
    /* --------- КОНЕЦ 2-ой ЧАСТИ  ----------- */
}

int child(void){
    sigset_t mask, oldmask;
    siginfo_t siginfo;
    struct sigaction action;
    struct timespec tv;
    int count = 0, recv_sig;
    /* -------- НАЧАЛО 1-ой ЧАСТИ  ----------- */
    /* Очищаем маску */
    //sigemptyset(&mask);
    /* Добавляем к маске SIGRTMIN */
    //sigaddset(&mask, SIGRTMIN);
    /* Добавляем к маске SIGRTMIN+1 */
    //sigaddset(&mask, SIGRTMIN+1);
    /*
    * Блокируем доставку сигналов SIGRTMIN, SIGRTMIN+1.
    * После возвращения предыдущее значение
    * заблокированной сигнальной маски хранится в oldmask
    */
    //sigprocmask(SIG_BLOCK, &mask, &oldmask);
    /* Задаём время ожидания 1 с */
    tv.tv_sec = 1;
    tv.tv_nsec = 0;
    /*
    * Ждём доставки сигнала. Мы ожидаем 2 сигнала,
    * SIGRTMIN и SIGRTMIN+1. Цикл завершится, когда
    * будут приняты оба сигнала
    */
   /*
    while(count < 2){
        if ((recv_sig = sigtimedwait(&mask, &siginfo, &tv)) == -1){
            if (errno == EAGAIN){
                printf("Timed out\n");
            continue;
            }else{
                perror("sigtimedwait");
                return -1;
            }
        }else{
            printf("signal %d received\n", recv_sig);
            count++;
        }
    }*/
    /* --------- КОНЕЦ 1-ой ЧАСТИ  ----------- */
    /* -------- НАЧАЛО 2-ой ЧАСТИ  ----------- */
    /* Устанавливаем SA_SIGINFO */
    action.sa_flags = SA_SIGINFO;
    /* Очищаем маску */
    sigemptyset(&action.sa_mask);
    /*
    * Регистрируем обработчик сигнала для SIGRTMIN.
    * Обратите внимание, что для регистрации
    * обработчика мы используем интерфейс
    * action.sa_sigaction 
    */
    action.sa_sigaction = rt_handler;
    if (sigaction(SIGRTMIN+3, &action, NULL) == -1){
        perror("sigaction");
        return 0;
    }
    if (sigaction(SIGRTMIN+2, &action, NULL) == -1){
        perror("sigaction");
        return 0;
    }
    if (sigaction(SIGRTMIN, &action, NULL) == -1){
        perror("sigaction");
        return 0;
    }
    if (sigaction(SIGRTMIN+1, &action, NULL) == -1){
        perror("sigaction");
        return 0;
    }
    for(;;) {
        pause();
    }
    /* Wait from SIGRTMIN */
    //sigsuspend(&oldmask);
    /* --------- КОНЕЦ 2-ой ЧАСТИ  ----------- */
}

/* Обработчик сигнала для SIGRTMIN */
void rt_handler(int signum, siginfo_t *siginfo, void * extra){
    printf("signal %d received. code = %d, value = %d\n",siginfo->si_signo, siginfo->si_code, siginfo->si_int);
    //sleep(3);
}