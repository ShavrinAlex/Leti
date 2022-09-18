CC = g++

all: main.o Map.o Cell.o Player.o
	$(CC) main.o Map.o Cell.o Player.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Map.h
	$(CC) -c main.cpp

Map.o: Map.cpp Cell.h
	$(CC) -c Map.cpp

Cell.o: Cell.cpp
	$(CC) -c Cell.cpp

Player.o: Player.cpp
	$(CC) -c Player.cpp

clean:
	rm -r *.o
