#include <stdio.h>
#include <sched.h>

int main (void) {
	struct sched_param shdprm; // значения параметров планирования
	int pid, pid1, pid2, pid3, ppid, status;
	int n, m, l, k; // переменные для задания значений приоритетов,

	n=55;
	//m=63; l=12; k=3; 	// заданные значения приоритетов c политикой RR
	//m=63; l=13; k=4;	// заданные значения приоритетов c политикой FIFO
	m=63; l=63; k=4;	// заданные значения приоритетов c разными политиками
	pid = getpid();
	ppid = getppid();
	printf("FATHER PARAMS: pid=%i ppid=%i\n", pid,ppid);
	shdprm.sched_priority = n;
	if (sched_setscheduler (0, SCHED_FIFO, &shdprm) == -1) {
		perror ("SCHED_SETSCHEDULER");
	}
	if ((pid1=fork()) == 0){
		shdprm.sched_priority = m;
		if (sched_setscheduler (pid1, SCHED_FIFO, &shdprm) == -1)
			perror ("SCHED_SETSCHEDULER_1");
		execl("son_1_task_10_3", "son_1_task_10_3", NULL);
	}
	if ((pid2=fork()) == 0){
		shdprm.sched_priority = l;
		if (sched_setscheduler (pid2, SCHED_RR, &shdprm) == -1)
			perror ("SCHED_SETSCHEDULER_2");
		execl("son_2_task_10_3", "son_2_task_10_3", NULL);
	}
	if ((pid3=fork()) == 0){
		shdprm.sched_priority = k;
		if (sched_setscheduler (pid3, SCHED_FIFO, &shdprm) == -1)
			perror ("SCHED_SETSCHEDULER_3");
		execl("son_3_task_10_3", "son_3_task_10_3", NULL);
	}
	printf("Процесс с pid = %d завершен\n", wait(&status));
	printf("Процесс с pid = %d завершен\n", wait(&status));
	printf("Процесс с pid = %d завершен\n", wait(&status));
	return 0;
}

