#include <stdio.h>

int main(){
	int pid, n;
 	pid = fork();
 
 	if (pid == -1){
		error("fork");
	   	exit(1);
	}
	if (pid == 0){
	   	printf("new pid = %d, ppid =%d \n", getpid(),getppid() );
	   	/*здесь размещаются вычисления, выполняемые процессом-потомком */

	} else {
	   	printf("parent pid = %d, ppid =%d \n", getpid(),getppid() );
	   	/*здесь размещаются вычисления, выполняемые порождающим процессом*/
	}	
	printf("Завершение процесса\n");
	exit(1);
}
