#include <stdio.h>
#include "get_len_text.h"
#include "get_new_text.h"
#include "print_new_text.h"
#include "free_text.h"


int main(){
	char **text;
	int len_text = get_len_text(&text);
	int len_new_text = len_text;
	get_new_text(&text, &len_new_text);
	print_new_text(&text, len_text, len_new_text);
	free_text(&text, len_new_text);
	return 0;
}
