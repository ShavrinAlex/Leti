#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define END "ugabuga\n"
#define BUF_SIZE 20

typedef struct Pair{
	char *word;
	char *translate;
} Pair;


int CompletingDict(Pair *dict){
	char *curr = malloc(50*sizeof(char));
	fgets(curr, 50, stdin);

	int i = 0;
	while (strcmp(curr, END) != 0){
		char *pch = strtok (curr," \n");

		dict[i].word = malloc(sizeof(pch));
		strcpy(dict[i].word, pch);

		pch = strtok (NULL," \n");

		dict[i].translate = malloc(sizeof(pch));
		strcpy(dict[i].translate, pch);

		i++;

		fgets(curr, 50, stdin);
	}
	return i;
}


void TranslateText(Pair *dict, char *text, int count_pair){
	char *pch = strtok (text, " \n");
	while (pch != NULL){
		int f = 0;
		for (int i = 0; i < count_pair; i++){
			if (strcasecmp(pch, dict[i].word) == 0){
				printf("%s ", dict[i].translate);
				f++;
				break;
			}
		}
		if (!f){
			printf("<unknown> ");
		}
		pch = strtok (NULL, " \n");
	}
	printf("\n");
}


void FreeMemory(Pair *dict, char *text, int count_pair){
	//free elements of dict
	for (int i = 0; i < count_pair; i++){
		free(dict[i].word);
		free(dict[i].translate);
	}

	//free dict
	free(dict);
	dict = NULL;

	//free text
	free(text);
	text = NULL;
}


int main(){
	//create dict
	Pair *dict = malloc(BUF_SIZE*sizeof(Pair));

	//checking error
	if (dict == NULL){return -1;}

	//compliting a dict
	int count_pair = CompletingDict(dict);

	//read text 
	char *text = malloc(256*sizeof(char));
	if (text == NULL){return -1;}	//checking error
	fgets(text, 256, stdin);

	//translate text
	TranslateText(dict, text, count_pair);

	//free memory
	FreeMemory(dict, text, count_pair);	
	return 0;
}
