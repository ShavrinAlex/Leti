#include <stdio.h>

int main(){
    printf("Значение OPEN_MAX = %d\n", sysconf(FOPEN_MAX));
    return 0;
}