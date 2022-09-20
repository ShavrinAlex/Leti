CC = g++

all: main.o MainLoop.o StartDialog.o Map.o Cell.o Player.o Drawer.o CommandReader.o Controller.o
	$(CC) main.o StartDialog.o MainLoop.o Map.o Cell.o Player.o Drawer.o CommandReader.o Controller.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp MainLoop.h StartDialog.h
	$(CC) -c main.cpp

MainLoop.o: MainLoop.cpp 
	$(CC) -c MainLoop.cpp

StartDialog.o: StartDialog.cpp StartDialog.h Position.h
	$(CC) -c StartDialog.cpp

Map.o: Map.cpp Map.h Cell.h Position.h
	$(CC) -c Map.cpp

Cell.o: Cell.cpp Cell.h
	$(CC) -c Cell.cpp

Player.o: Player.cpp Player.h Map.h Controller.h
	$(CC) -c Player.cpp

Drawer.o: Drawer.cpp Drawer.h Controller.h
	$(CC) -c Drawer.cpp

CommandReader.o: CommandReader.cpp CommandReader.h
	$(CC) -c CommandReader.cpp

Controller.o: Controller.cpp Controller.h Player.h Map.h Drawer.h Position.h
	$(CC) -c Controller.cpp

clean:
	rm -r *.o
