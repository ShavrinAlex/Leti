#include <stdio.h>
#include <sched.h>

int main(){
	struct sched_param shdprm;
  	int pid, n=10;
 	pid = fork();
 	if (pid == -1){
   		error("fork");
   		exit(1);
 	}
 	shdprm.sched_priority = 50;

      	if (sched_setscheduler (0, SCHED_FIFO, &shdprm) == -1) {
              perror ("SCHED_SETSCHEDULER");
	}
	printf ("Текущая политика планирования для текущего процесса: ");
      	switch (sched_getscheduler (0)) {
              case SCHED_FIFO:
                      printf ("SCHED_FIFO\n");
                      break;
              case SCHED_RR:
                      printf ("SCHED_RR\n");
                      break;
              case SCHED_OTHER:

                      printf ("SCHED_OTHER\n");
                      break;
              case -1:
                      perror ("SCHED_GETSCHEDULER");
                      break;
              default:
                      printf ("Неизвестная политика планирования\n");

      	}
 	while(1){
	       if (pid == 0) {
		 	printf("new pid = %d, ppid =%d \n", getpid(),getppid() );
		       	for(int i=0;i<100;i++)
		               n+=n;
	       } else {
			 printf("parent pid = %d, ppid =%d \n", getpid(),getppid() );
			 for (int i=0;i<10000;i++)
		               n*=n;

	       }
 	}
 	printf("n = %d, Завершение процесса\n",n);
 	exit(1);
}

