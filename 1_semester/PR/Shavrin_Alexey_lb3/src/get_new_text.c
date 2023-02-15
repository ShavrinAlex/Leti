#include <stdlib.h>
#include <string.h>


void get_new_text(char ***text, int *len_text){
	char **temp = malloc(*len_text*sizeof(char*));
	if (temp != NULL){
		char **new_text = temp;
		int n = 0;	
		for (int i = 0; i < *len_text; i++){
			int len_sent = strlen((*text)[i]);
			if ((*text)[i][len_sent-2] != '?'){
				new_text[n++] = (*text)[i]; 
			}
			else{
				free((*text)[i]);
			}
		}
		free(*text);
		*text = new_text;
		*len_text = n;
	}
}
