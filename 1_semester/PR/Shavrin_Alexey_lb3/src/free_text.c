#include <stdlib.h>


void free_text(char ***text, int len_text){
	for (int i = 0; i < len_text; i++){
		free((*text)[i]);
	}
	free(*text);
}
