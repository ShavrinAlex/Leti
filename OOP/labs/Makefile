CC = g++

all: main.o Cell.o CellView.o CommandReader.o Controller.o Entity.o EntityView.o Game.o GameElement.o GraphicArts.o Map.o MapView.o Player.o PlayerView.o StartDialog.o
	$(CC) main.o Cell.o CellView.o CommandReader.o Controller.o Entity.o EntityView.o Game.o GameElement.o GraphicArts.o Map.o MapView.o Player.o PlayerView.o StartDialog.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp StartDialog.hpp  Game.hpp
	$(CC) -c main.cpp

Cell.o: Cell.cpp Cell.hpp
	$(CC) -c Cell.cpp

CellView.o: CellView.cpp CellView.hpp Cell.hpp
	$(CC) -c CellView.cpp

CommandReader.o: CommandReader.cpp CommandReader.hpp Mediator.hpp
	$(CC) -c CommandReader.cpp

Controller.o: Controller.cpp Controller.hpp Mediator.hpp
	$(CC) -c Controller.cpp

Entity.o: Entity.cpp Entity.hpp Enumerations.hpp
	$(CC) -c Entity.cpp

EntityView.o: EntityView.cpp EntityView.hpp Entity.hpp Mediator.hpp
	$(CC) -c EntityView.cpp

Game.o: Game.cpp Game.hpp CommandReader.hpp Player.hpp Enumerations.hpp Controller.hpp
	$(CC) -c Game.cpp

GameElement.o : GameElement.cpp GameElement.hpp Mediator.hpp
	$(CC) -c GameElement.cpp

GraphicArts.o: GraphicArts.cpp GraphicArts.hpp CellView.hpp MapView.hpp EntityView.hpp PlayerView.hpp
	$(CC) -c GraphicArts.cpp

Map.o: Map.cpp Map.hpp Cell.hpp Position.hpp Enumerations.hpp Mediator.hpp
	$(CC) -c Map.cpp

MapView.o: MapView.cpp MapView.hpp Map.hpp CellView.hpp
	$(CC) -c MapView.cpp

Player.o: Player.cpp Player.hpp Entity.hpp Mediator.hpp
	$(CC) -c Player.cpp

PlayerView.o: PlayerView.cpp EntityView.hpp Player.hpp
	$(CC) -c PlayerView.cpp

StartDialog.o: StartDialog.cpp StartDialog.hpp
	$(CC) -c StartDialog.cpp

clean:
	rm *.o
	