#include <stdio.h>

int main(){
	int pid, pid_2, pid_3, pid_4, pid_5, n = 10;
 	pid = fork();
 	if (pid == -1){
	   	error("fork");
	   	exit(1);
 	}
 	if (pid == 0) {
   		printf("new pid = %d, ppid =%d \n", getpid(),getppid() );
   		/*здесь размещаются вычисления, выполняемые процессом-потомком */
   		n *= n;
 	} else {
   		pid_2 = fork();
   		if (pid_2 == 0){
       			printf("new pid2 = %d, ppid = %d \n", getpid(),getppid());
       			n *= 3;
   		} else {
       			pid_3 = fork();
       			if (pid_3 == 0){
         			printf("new pid3 = %d, ppid = %d \n", getpid(),getppid());
         			n += 100;
       			} else {
               			pid_4 = fork();
               			if (pid_4 == 0){
                       			printf("new pid4 = %d, ppid = %d \n", getpid(),getppid());
                       			n *= 100;
               			} else {
                  			pid_5 = fork();
                  			if (pid_5 == 0){
                      				printf("new pid5 = %d, ppid = %d \n", getpid(),getppid());
                       				n -= 100;
                  			} else {
                          			sleep(2);
                       				printf("parent pid = %d, ppid =%d \n", getpid(),getppid() );
                       				/*здесь размещаются вычисления, выполняемые порождающим процессом*/
                       				n += n;
                  			}
               			}
       			}
   		}
   	}
	printf("Завершение процесса: n=%d\n",n);
	exit(1);
}

