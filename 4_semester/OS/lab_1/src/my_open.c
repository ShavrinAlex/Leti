#include <stdio.h>

int main(int argc, char *argv[]){
	char string[50];
	string[0] = '\0';
	scanf("%s", string);

	if (string[0]){
		if (fopen(string,"r") == NULL){
			printf("%s: неудача при попытке открыть файл %s\n", argv[0], string);
 	 	} else{
			printf("%s: файл %s открыт\n", argv[0], string);
		}
	} else{
		printf("открываемый файл не указан\n");
	}
}
