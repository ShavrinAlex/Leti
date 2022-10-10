CC = g++
LINK_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
COMPILE_FLAGS = -c -Wall
OBJ_FOLDER = ./ObjectFiles/

all: $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Cell.o $(OBJ_FOLDER)CellView.o $(OBJ_FOLDER)CommandReader.o $(OBJ_FOLDER)Controller.o $(OBJ_FOLDER)Entity.o $(OBJ_FOLDER)EntityView.o $(OBJ_FOLDER)Game.o $(OBJ_FOLDER)GameElement.o $(OBJ_FOLDER)GraphicArts.o $(OBJ_FOLDER)Map.o $(OBJ_FOLDER)MapView.o $(OBJ_FOLDER)Observable.o $(OBJ_FOLDER)Player.o $(OBJ_FOLDER)PlayerView.o $(OBJ_FOLDER)StartDialog.o $(OBJ_FOLDER)EventOnGame.o $(OBJ_FOLDER)EventOnMap.o $(OBJ_FOLDER)EventOnPlayer.o $(OBJ_FOLDER)EndGameEvent.o $(OBJ_FOLDER)WinGameEvent.o $(OBJ_FOLDER)SetHealthEvent.o $(OBJ_FOLDER)SetArmorEvent.o $(OBJ_FOLDER)SetEnergyEvent.o $(OBJ_FOLDER)SetWallEvent.o $(OBJ_FOLDER)SetWinGameEvent.o $(OBJ_FOLDER)FactoryEventOnMap.o $(OBJ_FOLDER)FactoryEventOnGame.o $(OBJ_FOLDER)FactoryEventOnPlayer.o $(OBJ_FOLDER)EventView.o $(OBJ_FOLDER)EventGenerator.o
	$(CC) $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Cell.o $(OBJ_FOLDER)CellView.o $(OBJ_FOLDER)CommandReader.o $(OBJ_FOLDER)Controller.o $(OBJ_FOLDER)Entity.o $(OBJ_FOLDER)EntityView.o $(OBJ_FOLDER)Game.o $(OBJ_FOLDER)GameElement.o $(OBJ_FOLDER)GraphicArts.o $(OBJ_FOLDER)Map.o $(OBJ_FOLDER)MapView.o $(OBJ_FOLDER)Observable.o $(OBJ_FOLDER)Player.o $(OBJ_FOLDER)PlayerView.o $(OBJ_FOLDER)StartDialog.o $(OBJ_FOLDER)EventOnGame.o $(OBJ_FOLDER)EventOnMap.o $(OBJ_FOLDER)EventOnPlayer.o $(OBJ_FOLDER)EndGameEvent.o $(OBJ_FOLDER)WinGameEvent.o $(OBJ_FOLDER)SetHealthEvent.o $(OBJ_FOLDER)SetArmorEvent.o $(OBJ_FOLDER)SetEnergyEvent.o $(OBJ_FOLDER)SetWallEvent.o $(OBJ_FOLDER)SetWinGameEvent.o $(OBJ_FOLDER)FactoryEventOnMap.o $(OBJ_FOLDER)FactoryEventOnGame.o $(OBJ_FOLDER)FactoryEventOnPlayer.o $(OBJ_FOLDER)EventView.o $(OBJ_FOLDER)EventGenerator.o -o sfml-app $(LINK_FLAGS)

$(OBJ_FOLDER)main.o: ./Logic/Code/main.cpp ./Logic/Headlines/StartDialog.hpp ./Logic/Headlines/Game.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/main.cpp -o $(OBJ_FOLDER)main.o

$(OBJ_FOLDER)Cell.o: ./Logic/Code/Cell.cpp ./Logic/Headlines/Cell.hpp ./Logic/Headlines/Observable.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/Cell.cpp -o $(OBJ_FOLDER)Cell.o

$(OBJ_FOLDER)CellView.o: ./Graphic/Code/CellView.cpp ./Graphic/Headlines/CellView.hpp ./Logic/Headlines/Cell.hpp ./Logic/Headlines/Observer.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/Code/CellView.cpp -o $(OBJ_FOLDER)CellView.o

$(OBJ_FOLDER)CommandReader.o: ./Logic/Code/CommandReader.cpp ./Logic/Headlines/CommandReader.hpp ./Logic/Headlines/Mediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/CommandReader.cpp -o $(OBJ_FOLDER)CommandReader.o

$(OBJ_FOLDER)Controller.o: ./Logic/Code/Controller.cpp ./Logic/Headlines/Controller.hpp ./Logic/Headlines/Mediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/Controller.cpp -o $(OBJ_FOLDER)Controller.o

$(OBJ_FOLDER)Entity.o: ./Logic/Code/Entity.cpp ./Logic/Headlines/Entity.hpp ./Logic/Headlines/Enumerations.hpp ./Logic/Headlines/Observable.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/Entity.cpp -o $(OBJ_FOLDER)Entity.o

$(OBJ_FOLDER)EntityView.o: ./Graphic/Code/EntityView.cpp ./Graphic/Headlines/EntityView.hpp ./Logic/Headlines/Entity.hpp ./Logic/Headlines/Mediator.hpp ./Logic/Headlines/Observer.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/Code/EntityView.cpp -o $(OBJ_FOLDER)EntityView.o

$(OBJ_FOLDER)Game.o: ./Logic/Code/Game.cpp ./Logic/Headlines/Game.hpp ./Logic/Headlines/CommandReader.hpp ./Logic/Headlines/Player.hpp ./Logic/Headlines/Enumerations.hpp ./Logic/Headlines/Controller.hpp ./Graphic/Headlines/GraphicArts.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/Game.cpp -o $(OBJ_FOLDER)Game.o

$(OBJ_FOLDER)GameElement.o : ./Logic/Code/GameElement.cpp ./Logic/Headlines/GameElement.hpp ./Logic/Headlines/Mediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/GameElement.cpp -o $(OBJ_FOLDER)GameElement.o

$(OBJ_FOLDER)GraphicArts.o: ./Graphic/Code/GraphicArts.cpp ./Graphic/Headlines/GraphicArts.hpp ./Graphic/Headlines/CellView.hpp ./Graphic/Headlines/MapView.hpp ./Graphic/Headlines/EntityView.hpp ./Graphic/Headlines/PlayerView.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/Code/GraphicArts.cpp -o $(OBJ_FOLDER)GraphicArts.o

$(OBJ_FOLDER)Map.o: ./Logic/Code/Map.cpp ./Logic/Headlines/Map.hpp ./Logic/Headlines/Cell.hpp ./Logic/Headlines/Position.hpp ./Logic/Headlines/Enumerations.hpp ./Logic/Headlines/Mediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/Map.cpp -o $(OBJ_FOLDER)Map.o
 
$(OBJ_FOLDER)MapView.o: ./Graphic/Code/MapView.cpp ./Graphic/Headlines/MapView.hpp ./Logic/Headlines/Map.hpp ./Graphic/Headlines/CellView.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/Code/MapView.cpp -o $(OBJ_FOLDER)MapView.o

$(OBJ_FOLDER)Observable.o: ./Logic/Code/Observable.cpp ./Logic/Headlines/Observable.hpp ./Logic/Headlines/Observer.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/Observable.cpp -o $(OBJ_FOLDER)Observable.o

$(OBJ_FOLDER)Player.o: ./Logic/Code/Player.cpp ./Logic/Headlines/Player.hpp ./Logic/Headlines/Entity.hpp ./Logic/Headlines/Mediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/Player.cpp -o $(OBJ_FOLDER)Player.o

$(OBJ_FOLDER)PlayerView.o: ./Graphic/Code/PlayerView.cpp ./Graphic/Headlines/EntityView.hpp ./Logic/Headlines/Player.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/Code/PlayerView.cpp -o $(OBJ_FOLDER)PlayerView.o

$(OBJ_FOLDER)StartDialog.o: ./Logic/Code/StartDialog.cpp ./Logic/Headlines/StartDialog.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/StartDialog.cpp -o $(OBJ_FOLDER)StartDialog.o

$(OBJ_FOLDER)EventOnGame.o: ./Logic/Code/EventOnGame.cpp ./Logic/Headlines/EventOnGame.hpp ./Logic/Headlines/Event.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/EventOnGame.cpp -o $(OBJ_FOLDER)EventOnGame.o

$(OBJ_FOLDER)EventOnMap.o: ./Logic/Code/EventOnMap.cpp ./Logic/Headlines/EventOnMap.hpp ./Logic/Headlines/Event.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/EventOnMap.cpp -o $(OBJ_FOLDER)EventOnMap.o

$(OBJ_FOLDER)EventOnPlayer.o: ./Logic/Code/EventOnPlayer.cpp ./Logic/Headlines/EventOnPlayer.hpp ./Logic/Headlines/Event.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/EventOnPlayer.cpp -o $(OBJ_FOLDER)EventOnPlayer.o

$(OBJ_FOLDER)SetWallEvent.o: ./Logic/Code/SetWallEvent.cpp ./Logic/Headlines/SetWallEvent.hpp ./Logic/Headlines/EventOnMap.hpp ./Logic/Headlines/Map.hpp ./Logic/Headlines/Cell.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/SetWallEvent.cpp -o $(OBJ_FOLDER)SetWallEvent.o
	
$(OBJ_FOLDER)SetWinGameEvent.o: ./Logic/Code/SetWinGameEvent.cpp ./Logic/Headlines/SetWinGameEvent.hpp ./Logic/Headlines/EventOnMap.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/SetWinGameEvent.cpp -o $(OBJ_FOLDER)SetWinGameEvent.o

$(OBJ_FOLDER)EndGameEvent.o: ./Logic/Code/EndGameEvent.cpp ./Logic/Headlines/EndGameEvent.hpp ./Logic/Headlines/EventOnGame.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/EndGameEvent.cpp -o $(OBJ_FOLDER)EndGameEvent.o

$(OBJ_FOLDER)WinGameEvent.o: ./Logic/Code/WinGameEvent.cpp ./Logic/Headlines/WinGameEvent.hpp ./Logic/Headlines/EventOnGame.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/WinGameEvent.cpp -o $(OBJ_FOLDER)WinGameEvent.o

$(OBJ_FOLDER)SetHealthEvent.o: ./Logic/Code/SetHealthEvent.cpp ./Logic/Headlines/SetHealthEvent.hpp 
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/SetHealthEvent.cpp -o $(OBJ_FOLDER)SetHealthEvent.o

$(OBJ_FOLDER)SetArmorEvent.o: ./Logic/Code/SetArmorEvent.cpp ./Logic/Headlines/SetArmorEvent.hpp ./Logic/Headlines/EventOnPlayer.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/SetArmorEvent.cpp -o $(OBJ_FOLDER)SetArmorEvent.o

$(OBJ_FOLDER)SetEnergyEvent.o: ./Logic/Code/SetEnergyEvent.cpp ./Logic/Headlines/SetEnergyEvent.hpp ./Logic/Headlines/EventOnPlayer.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/SetEnergyEvent.cpp -o $(OBJ_FOLDER)SetEnergyEvent.o

$(OBJ_FOLDER)FactoryEventOnMap.o: ./Logic/Code/FactoryEventOnMap.cpp ./Logic/Headlines/FactoryEventOnMap.hpp ./Logic/Headlines/SetWinGameEvent.hpp ./Logic/Headlines/SetWallEvent.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/FactoryEventOnMap.cpp -o $(OBJ_FOLDER)FactoryEventOnMap.o

$(OBJ_FOLDER)FactoryEventOnGame.o: ./Logic/Code/FactoryEventOnGame.cpp ./Logic/Headlines/FactoryEventOnGame.hpp ./Logic/Headlines/EndGameEvent.hpp ./Logic/Headlines/WinGameEvent.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/FactoryEventOnGame.cpp -o $(OBJ_FOLDER)FactoryEventOnGame.o

$(OBJ_FOLDER)FactoryEventOnPlayer.o: ./Logic/Code/FactoryEventOnPlayer.cpp ./Logic/Headlines/FactoryEventOnPlayer.hpp ./Logic/Headlines/SetArmorEvent.hpp ./Logic/Headlines/SetEnergyEvent.hpp ./Logic/Headlines/SetHealthEvent.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/FactoryEventOnPlayer.cpp -o $(OBJ_FOLDER)FactoryEventOnPlayer.o

$(OBJ_FOLDER)EventView.o: ./Graphic/Code/EventView.cpp ./Graphic/Headlines/EventView.hpp ./Logic/Headlines/Position.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/Code/EventView.cpp -o $(OBJ_FOLDER)EventView.o

$(OBJ_FOLDER)EventGenerator.o: ./Logic/Code/EventGenerator.cpp ./Logic/Headlines/EventGenerator.hpp ./Logic/Headlines/FactoryEventOnPlayer.hpp ./Logic/Headlines/FactoryEventOnMap.hpp ./Logic/Headlines/FactoryEventOnGame.hpp ./Logic/Headlines/Map.hpp ./Graphic/Headlines/MapView.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/EventGenerator.cpp -o $(OBJ_FOLDER)EventGenerator.o
	
clean:
	rm $(OBJ_FOLDER)*.o
	