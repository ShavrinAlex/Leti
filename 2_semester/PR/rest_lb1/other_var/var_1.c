#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1002
#define M 32
#define X 500


int cmp(const void* a, const void *b){
	const char* f = *(const char**)a;
	const char* s = *(const char**)b;
	return strcmp(f, s);
}

int main(){
	char *text = malloc(N*sizeof(char));
	char *key = malloc(M*sizeof(char));

	//read
	fgets(text, N, stdin);
	fgets(key, M, stdin);
	//partition
	char** words = malloc(X*sizeof(char*));
	char* w = strtok(text, " .");
	int i = 0;
	while (w){
		*(words+i) = w;
		i++;
		w = strtok(NULL, " .");
	}
	
	//qsort
	qsort(words, i, sizeof(char*), cmp);

	//bsearch
	if(strlen(key)<M-1){
                key[strlen(key)-1]='\0';
        }
	char** pos = (char**)bsearch(&key, words, i, sizeof(char*), cmp);

	//print ans
	if (pos)
		printf("exists\n");
	else
		printf("doesn't exist\n");

	//free
	free(words);
	free(key);
	free(text);

	return 0;
}
