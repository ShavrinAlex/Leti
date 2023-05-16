#include <stdio.h>

int main(){
       int pid,ppid;
       pid = getpid();
       ppid = getppid();
       printf("SON PARAMS: pid=%i ppid=%i\n",pid,ppid);
       sleep(15);
       //return 0;
       exit(1);
}

