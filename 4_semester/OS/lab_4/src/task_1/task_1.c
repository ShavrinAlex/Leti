#include <stdio.h>
#define COUNT_PROC 12

int main(){
 	long int n=2;
	int pid[COUNT_PROC];

	for (int i = 0; i < COUNT_PROC; i++){
		pid[i] = fork();
		if (pid[i] == -1){
   			error("fork");
   			exit(1);
		}
	}
 	
 	while(1){
		for (int i = 0; i < COUNT_PROC; i++){
       		if (pid[i] == 0) {
		 		printf("%d new pid = %d, ppid =%d \n", i, getpid(),getppid());
		       	for(int j=0; j<2^i+1; j++)
                    n *= n;
			}	
		}
 	}
 	printf("n = %d, Завершение процесса\n", n);
 	exit(1);
}
