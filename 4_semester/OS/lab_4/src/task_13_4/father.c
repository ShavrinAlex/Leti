#include <stdio.h>
#include <signal.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"

int main() {
   int pid[2];
   char * son[2] = {"son1", "son2"};
   // Создание двух дочерних процессов с помощью fork()
   for(int i = 0; i < 2; i++) {
       if((pid[i] = fork()) == 0) { // Если pid == 0, то это дочерний процесс
           execl(son[i], son[i], NULL); // Запуск исполняемого файла "son[i]"
       }
   }
   // Вывод сообщения "father" и списка всех процессов в системе с помощью "ps"
   printf("father\n");
   system("ps");

   // Отправка сигнала SIGUSR1 каждому дочернему процессу
   for(int i = 0;i < 2; i++) {
       kill(pid[i], SIGUSR1);
   }
   // Вывод времени отправки сигналов и списка всех процессов в системе с помощью "ps"
   time_t st_t;
   st_t = time(NULL);
   printf("signals sended at time %s\n", ctime(&st_t));
   sleep(2);
   system("ps");
}