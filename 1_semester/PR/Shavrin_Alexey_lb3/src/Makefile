CC = gcc

all: main.o get_first_symbol.o read_sentence.o get_len_text.o get_new_text.o print_new_text.o free_text.o
	$(CC) main.o get_first_symbol.o read_sentence.o get_len_text.o get_new_text.o print_new_text.o free_text.o -o main

main.o: main.c get_len_text.h get_new_text.h print_new_text.h free_text.h
	$(CC) -c main.c

get_first_symbol.o: get_first_symbol.c
	$(CC) -c get_first_symbol.c

read_sentence.o: read_sentence.c get_first_symbol.h
	$(CC) -c read_sentence.c

get_len_text.o: get_len_text.c read_sentence.h free_text.h
	$(CC) -c get_len_text.c

get_new_text.o: get_new_text.c
	$(CC) -c get_new_text.c

print_new_text.o: print_new_text.c
	$(CC) -c print_new_text.c

free_text.o: free_text.c
	$(CC) -c free_text.c

clean:
	rm -f *.o main
