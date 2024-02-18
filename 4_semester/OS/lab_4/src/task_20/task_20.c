#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include "time.h"
#include "unistd.h"
#include <stdlib.h>
pthread_t t1, tn;  // объявляем две переменные типа pthread_t для хранения идентификаторов нитей выполнения.
void * thread1() {  // функция, которую будет выполнять первая нить.
   printf("Thread_1 is started\n");  // выводим сообщение о том, что первая нить начала работу.
   time_t timer;
   timer = time(NULL);
   int n = 1;
   for(int i = 0; i <7; i++) {  // выполняем цикл 7 раз.
      time_t end = time(NULL);  // получаем текущее время.
      printf("th1 n=%d, time=%ld\n", n *= 2, -timer + end);  // выводим значение переменной n и время выполнения нити.
      sleep(5);  // приостанавливаем выполнение нити на 5 секунд.
      pthread_kill(tn, SIGUSR1);
      system("ps axhf > thread1.txt");  // записываем информацию о работающих процессах в файл
   }
   
}
void * threadn() {  // функция, которую будет выполнять вторая нить.
   printf("Thread_n is started\n");  // выводим сообщение о том, что вторая нить начала работу.
   time_t timer;
   timer = time(NULL);
   int n = 1;
   for(int i = 0; i <10; i++) {  // выполняем цикл 10 раз.
      time_t end = time(NULL);  // получаем текущее время.
      system("ps axhf > threadn.txt");  // записываем информацию о работающих процессах в файл.
      printf("th2 n=%d, time=%ld\n", n *= 3, -timer + end);  // выводим значение переменной n и время выполнения нити.
      sleep(1);  // приостанавливаем выполнение нити на 1 секунду.
   }
}
int main() {
   system("ps axhf > file.txt");  // записываем информацию о работающих процессах в файл.
   pthread_create(&t1, NULL, thread1, NULL);  // создаем первую нить.
   pthread_create(&tn, NULL, threadn, NULL);  // создаем вторую нить.
   system("ps axhf >> file.txt");  // добавляем информацию о работающих процессах в файл
   pthread_join(t1, NULL);  // ждем завершения первой нити.
   //pthread_join(tn, NULL);  // ждем завершения второй нити.
   system("ps axhf >> file.txt");  // добавляем информацию о работающих процессах в файл.
}