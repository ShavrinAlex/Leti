#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char *s1, const char *s2){
    char* result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(){
    FILE* fp;
    fp = fopen("tid_file.txt", "r");
    char str[100];
    if (fp == NULL){
        perror("FILE");
        exit(1);
    }
    fgets(str, 100, fp);
    char* s = concat("kill -10 ", str); //10 == SIGUSR1
    printf("Отправляем сигнал!\n");
    system(s);
    fclose(fp);
    free(s); // ждем сигналов
    return 0;
}