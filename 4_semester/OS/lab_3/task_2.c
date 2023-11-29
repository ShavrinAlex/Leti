#include <stdio.h>
 
int main(){
	int pid, n = 10;
	pid = fork();
	
  	if (pid == -1){
    		error("fork");
    		exit(1);
	}
	   
  	if (pid == 0) {
    		printf("new pid = %d, ppid =%d \n", getpid(),getppid() );
    		/*здесь размещаются вычисления, выполняемые процессом-потомком */
    		n*=n;
  	} else {
    		printf("parent pid = %d, ppid =%d \n", getpid(),getppid() );
    		/*здесь размещаются вычисления, выполняемые порождающим процессом*/
   		n+=n;
  	}
   
  	printf("Завершение процесса: n=%d\n",n);
  	exit(1);
}
 
