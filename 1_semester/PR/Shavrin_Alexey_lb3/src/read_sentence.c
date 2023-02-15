#include <stdio.h>
#include <stdlib.h>
#include "get_first_symbol.h"
#define LENGTH_SENT 50

char *read_sentence(){
	int len_sent = LENGTH_SENT;
	char *temp = malloc(len_sent*sizeof(char));
	
	if (temp != NULL){
		char *sentence = temp;
		char symbol = get_first_symbol();
		int i;
		for (i = 0; symbol != '.' && symbol != ';' && symbol != '?' && symbol != '!'; symbol = getchar()){
			sentence[i++] = symbol;
			if (i >= (len_sent - 2)){
				len_sent += LENGTH_SENT;
				temp = realloc(sentence, len_sent*sizeof(char));
				if (temp != NULL){
					sentence = temp;
				}
				else{
					free(sentence);
					return NULL;
				}
			}
		}
		sentence[i++] = symbol;
		sentence[i++] = '\n';
		sentence[i] = '\0';
		return sentence;
	}
	return NULL;
}
