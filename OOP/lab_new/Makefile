CC = g++

all: main.o Cell.o CellView.o CommandReader.o Entity.o EntityView.o Game.o GraphicArts.o Map.o MapView.o Player.o StartDialog.o
	$(CC) main.o Cell.o CellView.o CommandReader.o Entity.o EntityView.o Game.o GraphicArts.o Map.o MapView.o Player.o StartDialog.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp StartDialog.hpp  Game.hpp
	$(CC) -c main.cpp

Cell.o: Cell.cpp Cell.hpp
	$(CC) -c Cell.cpp

CellView.o: CellView.cpp CellView.hpp Cell.hpp
	$(CC) -c CellView.cpp

CommandReader.o: CommandReader.cpp CommandReader.hpp
	$(CC) -c CommandReader.cpp

Entity.o: Entity.cpp Entity.hpp Enumerations.hpp
	$(CC) -c Entity.cpp

EntityView.o: EntityView.cpp EntityView.hpp Entity.hpp
	$(CC) -c EntityView.cpp

Game.o: Game.cpp Game.hpp CommandReader.hpp Player.hpp Enumerations.hpp 
	$(CC) -c Game.cpp

GraphicArts.o: GraphicArts.cpp GraphicArts.hpp CellView.hpp MapView.hpp EntityView.hpp
	$(CC) -c GraphicArts.cpp

Map.o: Map.cpp Map.hpp Cell.hpp Position.hpp Enumerations.hpp
	$(CC) -c Map.cpp

MapView.o: MapView.cpp MapView.hpp Map.hpp CellView.hpp
	$(CC) -c MapView.cpp

Player.o: Player.cpp Player.hpp Entity.hpp
	$(CC) -c Player.cpp

StartDialog.o: StartDialog.cpp StartDialog.hpp
	$(CC) -c StartDialog.cpp

clean:
	rm *.o