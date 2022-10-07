CC = g++
LINK_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
COMPILE_FLAGS = -c -Wall
OBJ_FOLDER = ./ObjectFiles/

all: $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Cell.o $(OBJ_FOLDER)CellView.o $(OBJ_FOLDER)ChangeMapEvent.o $(OBJ_FOLDER)CommandReader.o $(OBJ_FOLDER)Controller.o $(OBJ_FOLDER)Entity.o $(OBJ_FOLDER)EntityView.o $(OBJ_FOLDER)Game.o $(OBJ_FOLDER)GameElement.o $(OBJ_FOLDER)GraphicArts.o $(OBJ_FOLDER)Map.o $(OBJ_FOLDER)MapView.o $(OBJ_FOLDER)Observable.o $(OBJ_FOLDER)Player.o $(OBJ_FOLDER)PlayerView.o $(OBJ_FOLDER)StartDialog.o $(OBJ_FOLDER)FireDamageEvent.o $(OBJ_FOLDER)WinEvent.o $(OBJ_FOLDER)SetHealthEvent.o $(OBJ_FOLDER)SetArmorEvent.o $(OBJ_FOLDER)SetEnergyEvent.o $(OBJ_FOLDER)UnconditionalEventFactory.o $(OBJ_FOLDER)ConditionalEventFactory.o $(OBJ_FOLDER)EventView.o $(OBJ_FOLDER)EventGenerator.o
	$(CC) $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Cell.o $(OBJ_FOLDER)CellView.o $(OBJ_FOLDER)ChangeMapEvent.o $(OBJ_FOLDER)CommandReader.o $(OBJ_FOLDER)Controller.o $(OBJ_FOLDER)Entity.o $(OBJ_FOLDER)EntityView.o $(OBJ_FOLDER)Game.o $(OBJ_FOLDER)GameElement.o $(OBJ_FOLDER)GraphicArts.o $(OBJ_FOLDER)Map.o $(OBJ_FOLDER)MapView.o $(OBJ_FOLDER)Observable.o $(OBJ_FOLDER)Player.o $(OBJ_FOLDER)PlayerView.o $(OBJ_FOLDER)StartDialog.o $(OBJ_FOLDER)FireDamageEvent.o $(OBJ_FOLDER)WinEvent.o $(OBJ_FOLDER)SetHealthEvent.o $(OBJ_FOLDER)SetArmorEvent.o $(OBJ_FOLDER)SetEnergyEvent.o  $(OBJ_FOLDER)UnconditionalEventFactory.o $(OBJ_FOLDER)ConditionalEventFactory.o $(OBJ_FOLDER)EventView.o $(OBJ_FOLDER)EventGenerator.o -o sfml-app $(LINK_FLAGS)

$(OBJ_FOLDER)main.o: ./Logic/Code/main.cpp ./Logic/Headlines/StartDialog.hpp ./Logic/Headlines/Game.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/main.cpp -o $(OBJ_FOLDER)main.o

$(OBJ_FOLDER)Cell.o: ./Logic/Code/Cell.cpp ./Logic/Headlines/Cell.hpp ./Logic/Headlines/Observable.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/Cell.cpp -o $(OBJ_FOLDER)Cell.o

$(OBJ_FOLDER)CellView.o: ./Graphic/Code/CellView.cpp ./Graphic/Headlines/CellView.hpp ./Logic/Headlines/Cell.hpp ./Logic/Headlines/Observer.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/Code/CellView.cpp -o $(OBJ_FOLDER)CellView.o

$(OBJ_FOLDER)ChangeMapEvent.o: ./Logic/Code/ChangeMapEvent.cpp ./Logic/Headlines/ChangeMapEvent.hpp ./Logic/Headlines/UnconditionalEvent.hpp ./Logic/Headlines/Map.hpp ./Logic/Headlines/Cell.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/ChangeMapEvent.cpp -o $(OBJ_FOLDER)ChangeMapEvent.o

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

$(OBJ_FOLDER)FireDamageEvent.o: ./Logic/Code/FireDamageEvent.cpp ./Logic/Headlines/FireDamageEvent.hpp ./Logic/Headlines/UnconditionalEvent.hpp ./Logic/Headlines/Player.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/FireDamageEvent.cpp -o $(OBJ_FOLDER)FireDamageEvent.o

$(OBJ_FOLDER)WinEvent.o: ./Logic/Code/WinEvent.cpp ./Logic/Headlines/WinEvent.hpp ./Logic/Headlines/UnconditionalEvent.hpp ./Logic/Headlines/Game.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/WinEvent.cpp -o $(OBJ_FOLDER)WinEvent.o

$(OBJ_FOLDER)SetHealthEvent.o: ./Logic/Code/SetHealthEvent.cpp ./Logic/Headlines/SetHealthEvent.hpp ./Logic/Headlines/ConditionalEvent.hpp ./Logic/Headlines/Player.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/SetHealthEvent.cpp -o $(OBJ_FOLDER)SetHealthEvent.o

$(OBJ_FOLDER)SetArmorEvent.o: ./Logic/Code/SetArmorEvent.cpp ./Logic/Headlines/SetArmorEvent.hpp ./Logic/Headlines/ConditionalEvent.hpp ./Logic/Headlines/Player.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/SetArmorEvent.cpp -o $(OBJ_FOLDER)SetArmorEvent.o

$(OBJ_FOLDER)SetEnergyEvent.o: ./Logic/Code/SetEnergyEvent.cpp ./Logic/Headlines/SetEnergyEvent.hpp ./Logic/Headlines/ConditionalEvent.hpp ./Logic/Headlines/Player.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/SetEnergyEvent.cpp -o $(OBJ_FOLDER)SetEnergyEvent.o

 $(OBJ_FOLDER)UnconditionalEventFactory.o: ./Logic/Code/UnconditionalEventFactory.cpp ./Logic/Headlines/UnconditionalEventFactory.hpp ./Logic/Headlines/FireDamageEvent.hpp ./Logic/Headlines/ChangeMapEvent.hpp ./Logic/Headlines/WinEvent.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/UnconditionalEventFactory.cpp -o $(OBJ_FOLDER)UnconditionalEventFactory.o

 $(OBJ_FOLDER)ConditionalEventFactory.o: ./Logic/Code/ConditionalEventFactory.cpp ./Logic/Headlines/ConditionalEventFactory.hpp ./Logic/Headlines/SetArmorEvent.hpp ./Logic/Headlines/SetEnergyEvent.hpp ./Logic/Headlines/SetHealthEvent.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/ConditionalEventFactory.cpp -o $(OBJ_FOLDER)ConditionalEventFactory.o

$(OBJ_FOLDER)EventView.o: ./Graphic/Code/EventView.cpp ./Graphic/Headlines/EventView.hpp ./Logic/Headlines/Position.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/Code/EventView.cpp -o $(OBJ_FOLDER)EventView.o

$(OBJ_FOLDER)EventGenerator.o: ./Logic/Code/EventGenerator.cpp ./Logic/Headlines/EventGenerator.hpp ./Logic/Headlines/ConditionalEventFactory.hpp ./Logic/Headlines/UnconditionalEventFactory.hpp ./Logic/Headlines/Map.hpp ./Graphic/Headlines/MapView.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Code/EventGenerator.cpp -o $(OBJ_FOLDER)EventGenerator.o
	
clean:
	rm $(OBJ_FOLDER)*.o
	