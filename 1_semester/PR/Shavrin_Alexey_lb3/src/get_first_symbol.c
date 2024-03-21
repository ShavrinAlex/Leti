#include <stdio.h>

char get_first_symbol(){
	char symbol;
	for (symbol = getchar(); symbol == ' ' || symbol == '\t' || symbol == '\n'; symbol = getchar()){}
	return symbol;
}
