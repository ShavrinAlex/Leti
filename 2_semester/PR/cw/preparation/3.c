#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void*b){
	const char *f = (const char *)a;
	const char *s = (const char *)b;
	int len_f = strlen(f);
	int len_s = strlen(s);
	return f - s;
}

void printText(char **text, int len){
	for (int i = 0; i < len; i++){
		printf("%s", text[i]);
	}
}

int main(){
	//read
	char **text = malloc(100*sizeof(char*));
	for (int j = 0; j < 100; j++){
		*(text+j) = calloc(200, sizeof(char));
	}
	char c1;
	char c2;
	int i = 0; //row
	int j = 0; //colum
	while (1){
		scanf("%c%c", &c1, &c2);
		text[i][j++] = c1;
		text[i][j++] = c2;
		if (c1 == '.' && c2 == ' '){
			i++;
			j = 0;
		}
		if (c1 == '\n' || c2 == '\n'){
			break;
		}
	}
	qsort(text, i, sizeof(char*), cmp);
	printText(text, i);	
	return 0;
}
