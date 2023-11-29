#include <stdlib.h>
#include <string.h>
#include "read_sentence.h"
#include "free_text.h"
#define LENGTH_TEXT 10
#define LAST_SENT "Dragon flew away!\n"


int get_len_text(char ***text){
	int len_text = LENGTH_TEXT;
	char **temp = malloc(len_text*sizeof(char*));
	
	if (temp != NULL){
		*text = temp;
		char *sentence;
		int i = 0;
		for (sentence = read_sentence(); strcmp(sentence, LAST_SENT) != 0; sentence = read_sentence()){
			if (sentence == NULL){
				free_text(text, i);
				return 0;
			}
			(*text)[i++] = sentence;
			if (i >= len_text){
				len_text += LENGTH_TEXT;
				temp = realloc(temp, len_text*sizeof(char*));
				if (temp != NULL){
					(*text) = temp;
				}
				else{
					free_text(text, i);
					return 0;
				}
			}
		}
		(*text)[i++] = sentence;
		return i;	
	}
	return 0;
}
