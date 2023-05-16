#include <stdio.h>
int main(){
 	int pid, n=10;
 	pid = fork();
 	if (pid == -1){
   		error("fork");
   		exit(1);
 	}
 	while(1){
       		if (pid == 0) {
		 	printf("new pid = %d, ppid =%d \n", getpid(),getppid() );
		       	for(int i=0;i<100;i++)
                       		n+=n;
       		}else {
		 	printf("parent pid = %d, ppid =%d \n", getpid(),getppid() );
		       	for (int i=0;i<10000;i++)
                       		n*=n;
       		}
 	}
 	printf("n = %d, Завершение процесса\n",n);
 	exit(1);
}

