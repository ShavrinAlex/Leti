#include <stdio.h>


void print_new_text(char ***text, int len_text, int len_new_text){
	for (int i = 0; i < len_new_text; i++){
		printf("%s", (*text)[i]);
	}
	printf("Количество предложений до %d и количество предложений после %d\n", len_text-1, len_new_text-1);
}
