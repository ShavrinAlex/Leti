CC = g++
LINK_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
COMPILE_FLAGS = -c -Wall
OBJ_FOLDER = ./ObjectFiles/

all: $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Cell.o $(OBJ_FOLDER)CellView.o $(OBJ_FOLDER)CommandReader.o $(OBJ_FOLDER)Controller.o $(OBJ_FOLDER)Entity.o $(OBJ_FOLDER)EntityView.o $(OBJ_FOLDER)Game.o $(OBJ_FOLDER)GameElement.o $(OBJ_FOLDER)GraphicArts.o $(OBJ_FOLDER)Map.o $(OBJ_FOLDER)MapView.o $(OBJ_FOLDER)Observable.o $(OBJ_FOLDER)Player.o $(OBJ_FOLDER)PlayerView.o $(OBJ_FOLDER)StartDialog.o
	$(CC) $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Cell.o $(OBJ_FOLDER)CellView.o $(OBJ_FOLDER)CommandReader.o $(OBJ_FOLDER)Controller.o $(OBJ_FOLDER)Entity.o $(OBJ_FOLDER)EntityView.o $(OBJ_FOLDER)Game.o $(OBJ_FOLDER)GameElement.o $(OBJ_FOLDER)GraphicArts.o $(OBJ_FOLDER)Map.o $(OBJ_FOLDER)MapView.o $(OBJ_FOLDER)Observable.o $(OBJ_FOLDER)Player.o $(OBJ_FOLDER)PlayerView.o $(OBJ_FOLDER)StartDialog.o -o sfml-app $(LINK_FLAGS)

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

clean:
	rm $(OBJ_FOLDER)*.o
	