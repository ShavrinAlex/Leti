#include <stdio.h>

int main(){
	int pid, pid_2;

	pid = fork();
 	if (pid == -1){
		error("fork");
	   	exit(1);
	}
	if (pid == 0) {
	   	printf("new pid = %d, ppid =%d \n", getpid(), getppid() );
	   	/*здесь размещаются вычисления, выполняемые процессом-потомком */
	   	pid_2 = fork();
	       	if(pid_2==0)
		       printf("new pid = %d, ppid = %d \n",getpid(), getppid());
	} else {
	   	printf("parent pid = %d, ppid =%d \n", getpid(), getppid() );
	   	/*здесь размещаются вычисления, выполняемые порождающим процессом*/  
	 }

	 printf("Завершение процесса\n");
	 exit(1);
}

