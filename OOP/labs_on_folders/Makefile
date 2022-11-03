CC = g++
LINK_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
COMPILE_FLAGS = -c -Wall -g
OBJ_FOLDER = ./ObjectFiles/

all: $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Game.o $(OBJ_FOLDER)Cell.o $(OBJ_FOLDER)CellView.o $(OBJ_FOLDER)KeyboardCommandReader.o $(OBJ_FOLDER)CommandReaderMediator.o $(OBJ_FOLDER)PlayerController.o $(OBJ_FOLDER)EnemiesController.o $(OBJ_FOLDER)GameController.o $(OBJ_FOLDER)Entity.o $(OBJ_FOLDER)EntityView.o $(OBJ_FOLDER)GraphicArts.o $(OBJ_FOLDER)Map.o $(OBJ_FOLDER)MapView.o $(OBJ_FOLDER)Observable.o $(OBJ_FOLDER)Player.o $(OBJ_FOLDER)PlayerView.o $(OBJ_FOLDER)StartMapSizeDialog.o $(OBJ_FOLDER)StartLogParametrsDialog.o $(OBJ_FOLDER)EventOnGame.o $(OBJ_FOLDER)EventOnMap.o $(OBJ_FOLDER)EventOnPlayer.o $(OBJ_FOLDER)EndGameEvent.o $(OBJ_FOLDER)WinGameEvent.o $(OBJ_FOLDER)SetHealthEvent.o $(OBJ_FOLDER)SetArmorEvent.o $(OBJ_FOLDER)SetEnergyEvent.o $(OBJ_FOLDER)SetWallEvent.o $(OBJ_FOLDER)SetWinGameEvent.o $(OBJ_FOLDER)FactoryEventOnMap.o $(OBJ_FOLDER)FactoryEventOnGame.o $(OBJ_FOLDER)FactoryEventOnPlayer.o $(OBJ_FOLDER)EventView.o $(OBJ_FOLDER)Generator.o $(OBJ_FOLDER)EventGenerator.o $(OBJ_FOLDER)EnemyGenerator.o $(OBJ_FOLDER)Log.o $(OBJ_FOLDER)LogMediator.o $(OBJ_FOLDER)ConsoleLogger.o $(OBJ_FOLDER)FileLogger.o $(OBJ_FOLDER)LogController.o $(OBJ_FOLDER)GameControllCommandsConverter.o $(OBJ_FOLDER)GameControllCommandsReader.o
	$(CC) $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Game.o $(OBJ_FOLDER)Cell.o $(OBJ_FOLDER)CellView.o $(OBJ_FOLDER)KeyboardCommandReader.o $(OBJ_FOLDER)CommandReaderMediator.o $(OBJ_FOLDER)PlayerController.o $(OBJ_FOLDER)EnemiesController.o $(OBJ_FOLDER)GameController.o $(OBJ_FOLDER)Entity.o $(OBJ_FOLDER)EntityView.o $(OBJ_FOLDER)GraphicArts.o $(OBJ_FOLDER)Map.o $(OBJ_FOLDER)MapView.o $(OBJ_FOLDER)Observable.o $(OBJ_FOLDER)Player.o $(OBJ_FOLDER)PlayerView.o $(OBJ_FOLDER)StartMapSizeDialog.o $(OBJ_FOLDER)StartLogParametrsDialog.o $(OBJ_FOLDER)EventOnGame.o $(OBJ_FOLDER)EventOnMap.o $(OBJ_FOLDER)EventOnPlayer.o $(OBJ_FOLDER)EndGameEvent.o $(OBJ_FOLDER)WinGameEvent.o $(OBJ_FOLDER)SetHealthEvent.o $(OBJ_FOLDER)SetArmorEvent.o $(OBJ_FOLDER)SetEnergyEvent.o $(OBJ_FOLDER)SetWallEvent.o $(OBJ_FOLDER)SetWinGameEvent.o $(OBJ_FOLDER)FactoryEventOnMap.o $(OBJ_FOLDER)FactoryEventOnGame.o $(OBJ_FOLDER)FactoryEventOnPlayer.o $(OBJ_FOLDER)EventView.o $(OBJ_FOLDER)Generator.o $(OBJ_FOLDER)EventGenerator.o $(OBJ_FOLDER)EnemyGenerator.o $(OBJ_FOLDER)Log.o $(OBJ_FOLDER)LogMediator.o $(OBJ_FOLDER)ConsoleLogger.o $(OBJ_FOLDER)FileLogger.o $(OBJ_FOLDER)LogController.o $(OBJ_FOLDER)GameControllCommandsConverter.o $(OBJ_FOLDER)GameControllCommandsReader.o -o sfml-app $(LINK_FLAGS)

$(OBJ_FOLDER)main.o: ./Logic/main.cpp ./Logic/StartDialogs/StartMapSizeDialog/StartMapSizeDialog.hpp ./Logic/GameFacadePattern/Game.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/main.cpp -o $(OBJ_FOLDER)main.o

$(OBJ_FOLDER)GraphicArts.o: ./Graphic/GraphicArts/GraphicArts.cpp ./Graphic/GraphicArts/GraphicArts.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/GraphicArts/GraphicArts.cpp -o $(OBJ_FOLDER)GraphicArts.o

$(OBJ_FOLDER)Game.o: ./Logic/GameFacadePattern/Game.cpp ./Logic/GameFacadePattern/Game.hpp ./Logic/CommandReader/KeyboardCommandReader/KeyboardCommandReader.hpp ./Logic/Entities/Player/Player.hpp ./Logic/Utility/Enumerations.hpp ./Logic/Controllers/EntitiesControllers/PlayerController/PlayerController.hpp ./Logic/Controllers/GameController/GameController.hpp ./Logic/MediatorPattern/CommandReaderMediator/CommandReaderMediator.hpp ./Graphic/GraphicArts/GraphicArts.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/GameFacadePattern/Game.cpp -o $(OBJ_FOLDER)Game.o

$(OBJ_FOLDER)Cell.o: ./Logic/Cell/Cell.cpp ./Logic/Cell/Cell.hpp ./Logic/ObserverPattern/Observable/Observable.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Cell/Cell.cpp -o $(OBJ_FOLDER)Cell.o

$(OBJ_FOLDER)CellView.o: ./Graphic/CellView/CellView.cpp ./Graphic/CellView/CellView.hpp ./Logic/Cell/Cell.hpp ./Logic/ObserverPattern/Observer.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/CellView/CellView.cpp -o $(OBJ_FOLDER)CellView.o

$(OBJ_FOLDER)KeyboardCommandReader.o: ./Logic/CommandReader/KeyboardCommandReader/KeyboardCommandReader.cpp ./Logic/CommandReader/KeyboardCommandReader/KeyboardCommandReader.hpp ./Logic/MediatorPattern/GameElement/GameElementDescription.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/CommandReader/KeyboardCommandReader/KeyboardCommandReader.cpp -o $(OBJ_FOLDER)KeyboardCommandReader.o

$(OBJ_FOLDER)CommandReaderMediator.o: ./Logic/MediatorPattern/CommandReaderMediator/CommandReaderMediator.cpp ./Logic/MediatorPattern/CommandReaderMediator/CommandReaderMediator.hpp ./Logic/MediatorPattern/Mediator.hpp ./Logic/Controllers/GameController/GameController.hpp ./Logic/Controllers/EntitiesControllers/PlayerController/PlayerController.hpp ./Logic/Utility/Enumerations.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/MediatorPattern/CommandReaderMediator/CommandReaderMediator.cpp -o $(OBJ_FOLDER)CommandReaderMediator.o

$(OBJ_FOLDER)PlayerController.o: ./Logic/Controllers/EntitiesControllers/PlayerController/PlayerController.cpp ./Logic/Controllers/EntitiesControllers/PlayerController/PlayerController.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Controllers/EntitiesControllers/PlayerController/PlayerController.cpp -o $(OBJ_FOLDER)PlayerController.o

$(OBJ_FOLDER)EnemiesController.o: ./Logic/Controllers/EntitiesControllers/EnemiesController/EnemiesController.cpp ./Logic/Controllers/EntitiesControllers/EnemiesController/EnemiesController.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Controllers/EntitiesControllers/EnemiesController/EnemiesController.cpp -o $(OBJ_FOLDER)EnemiesController.o

$(OBJ_FOLDER)GameController.o: ./Logic/Controllers/GameController/GameController.cpp ./Logic/Controllers/GameController/GameController.hpp ./Logic/GameFacadePattern/Game.hpp ./Logic/Entities/Player/Player.hpp ./Logic/ObserverPattern/Observer.hpp ./Logic/Utility/Enumerations.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Controllers/GameController/GameController.cpp -o $(OBJ_FOLDER)GameController.o

$(OBJ_FOLDER)Entity.o: ./Logic/Entities/Entity/Entity.cpp ./Logic/Entities/Entity/Entity.hpp ./Logic/Utility/Enumerations.hpp ./Logic/ObserverPattern/Observable/Observable.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Entities/Entity/Entity.cpp -o $(OBJ_FOLDER)Entity.o 

$(OBJ_FOLDER)EntityView.o: ./Graphic/EntitiesView/EntityView/EntityView.cpp ./Graphic/EntitiesView/EntityView/EntityView.hpp ./Logic/Entities/Entity//Entity.hpp ./Logic/MediatorPattern/Mediator.hpp ./Logic/ObserverPattern/Observer.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/EntitiesView/EntityView/EntityView.cpp -o $(OBJ_FOLDER)EntityView.o

$(OBJ_FOLDER)GameElement.o : ./Logic/MediatorPattern/GameElement/GameElement.cpp ./Logic/MediatorPattern/GameElement/GameElement.hpp ./Logic/MediatorPattern/Mediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/MediatorPattern/GameElement/GameElement.cpp -o $(OBJ_FOLDER)GameElement.o

$(OBJ_FOLDER)Map.o: ./Logic/Map/Map.cpp ./Logic/Map/Map.hpp ./Logic/Cell/Cell.hpp ./Logic/Utility/Position.hpp ./Logic/Utility/Enumerations.hpp ./Logic/MediatorPattern/Mediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Map/Map.cpp -o $(OBJ_FOLDER)Map.o
 
$(OBJ_FOLDER)MapView.o: ./Graphic/MapView/MapView.cpp ./Graphic/MapView/MapView.hpp ./Logic/Map/Map.hpp ./Graphic/CellView/CellView.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/MapView/MapView.cpp -o $(OBJ_FOLDER)MapView.o

$(OBJ_FOLDER)Observable.o: ./Logic/ObserverPattern/Observable/Observable.cpp ./Logic/ObserverPattern/Observable/Observable.hpp ./Logic/ObserverPattern/Observer.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/ObserverPattern/Observable/Observable.cpp -o $(OBJ_FOLDER)Observable.o

$(OBJ_FOLDER)Player.o: ./Logic/Entities/Player/Player.cpp ./Logic/Entities/Player/Player.hpp ./Logic/Entities/Entity/Entity.hpp ./Logic/MediatorPattern/Mediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Entities/Player/Player.cpp -o $(OBJ_FOLDER)Player.o

$(OBJ_FOLDER)PlayerView.o: ./Graphic/EntitiesView/PlayerView/PlayerView.cpp ./Graphic/EntitiesView/EntityView/EntityView.hpp ./Logic/Entities/Player/Player.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/EntitiesView/PlayerView/PlayerView.cpp -o $(OBJ_FOLDER)PlayerView.o

$(OBJ_FOLDER)StartMapSizeDialog.o: ./Logic/StartDialogs/StartMapSizeDialog/StartMapSizeDialog.cpp ./Logic/StartDialogs/StartMapSizeDialog/StartMapSizeDialog.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/StartDialogs/StartMapSizeDialog/StartMapSizeDialog.cpp -o $(OBJ_FOLDER)StartMapSizeDialog.o

$(OBJ_FOLDER)StartLogParametrsDialog.o: ./Logic/StartDialogs/StartLogParametrsDialog/StartLogParametrsDialog.cpp  ./Logic/StartDialogs/StartLogParametrsDialog/StartLogParametrsDialog.cpp
	$(CC) $(COMPILE_FLAGS) ./Logic/StartDialogs/StartLogParametrsDialog/StartLogParametrsDialog.cpp -o $(OBJ_FOLDER)StartLogParametrsDialog.o

$(OBJ_FOLDER)EventOnGame.o: ./Logic/Events/EventsOnGame/EventOnGame/EventOnGame.cpp ./Logic/Events/EventsOnGame/EventOnGame/EventOnGame.hpp ./Logic/Events/Event.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnGame/EventOnGame/EventOnGame.cpp -o $(OBJ_FOLDER)EventOnGame.o

$(OBJ_FOLDER)EventOnMap.o: ./Logic/Events/EventsOnMap/EventOnMap/EventOnMap.cpp ./Logic/Events/EventsOnMap/EventOnMap/EventOnMap.hpp ./Logic/Events/Event.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnMap/EventOnMap/EventOnMap.cpp -o $(OBJ_FOLDER)EventOnMap.o

$(OBJ_FOLDER)EventOnPlayer.o: ./Logic/Events/EventsOnPlayer/EventOnPlayer/EventOnPlayer.cpp ./Logic/Events/EventsOnPlayer/EventOnPlayer/EventOnPlayer.hpp ./Logic/Events/Event.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnPlayer/EventOnPlayer/EventOnPlayer.cpp -o $(OBJ_FOLDER)EventOnPlayer.o

$(OBJ_FOLDER)SetWallEvent.o: ./Logic/Events/EventsOnMap/SetWallEvent/SetWallEvent.cpp ./Logic/Events/EventsOnMap/SetWallEvent/SetWallEvent.hpp ./Logic/Events/EventsOnMap/EventOnMap/EventOnMap.hpp ./Logic/Map/Map.hpp ./Logic/Cell/Cell.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnMap/SetWallEvent/SetWallEvent.cpp -o $(OBJ_FOLDER)SetWallEvent.o
	
$(OBJ_FOLDER)SetWinGameEvent.o: ./Logic/Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.cpp ./Logic/Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.hpp ./Logic/Events/EventsOnMap/EventOnMap/EventOnMap.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.cpp -o $(OBJ_FOLDER)SetWinGameEvent.o

$(OBJ_FOLDER)EndGameEvent.o: ./Logic/Events/EventsOnGame/EndGameEvent/EndGameEvent.cpp ./Logic/Events/EventsOnGame/EndGameEvent/EndGameEvent.hpp ./Logic/Events/EventsOnGame/EventOnGame/EventOnGame.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnGame/EndGameEvent/EndGameEvent.cpp -o $(OBJ_FOLDER)EndGameEvent.o

$(OBJ_FOLDER)WinGameEvent.o: ./Logic/Events/EventsOnGame/WinGameEvent/WinGameEvent.cpp ./Logic/Events/EventsOnGame/WinGameEvent/WinGameEvent.hpp ./Logic/Events/EventsOnGame/EventOnGame/EventOnGame.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnGame/WinGameEvent/WinGameEvent.cpp -o $(OBJ_FOLDER)WinGameEvent.o

$(OBJ_FOLDER)SetHealthEvent.o: ./Logic/Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.cpp ./Logic/Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.hpp ./Logic/Events/EventsOnPlayer/EventOnPlayer/EventOnPlayer.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.cpp -o $(OBJ_FOLDER)SetHealthEvent.o

$(OBJ_FOLDER)SetArmorEvent.o: ./Logic/Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.cpp ./Logic/Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.hpp ./Logic/Events/EventsOnPlayer/EventOnPlayer/EventOnPlayer.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.cpp -o $(OBJ_FOLDER)SetArmorEvent.o

$(OBJ_FOLDER)SetEnergyEvent.o: ./Logic/Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.cpp ./Logic/Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.hpp ./Logic/Events/EventsOnPlayer/EventOnPlayer/EventOnPlayer.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.cpp -o $(OBJ_FOLDER)SetEnergyEvent.o

$(OBJ_FOLDER)FactoryEventOnMap.o: ./Logic/FactoriesPattern/FactoryEventOnMap/FactoryEventOnMap.cpp ./Logic/FactoriesPattern/FactoryEventOnMap/FactoryEventOnMap.hpp ./Logic/Events/EventsOnMap/SetWallEvent/SetWallEvent.hpp ./Logic/Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/FactoriesPattern/FactoryEventOnMap/FactoryEventOnMap.cpp -o $(OBJ_FOLDER)FactoryEventOnMap.o

$(OBJ_FOLDER)FactoryEventOnGame.o: ./Logic/FactoriesPattern/FactoryEventOnGame/FactoryEventOnGame.cpp ./Logic/FactoriesPattern/FactoryEventOnGame/FactoryEventOnGame.hpp ./Logic/Events/EventsOnGame/EndGameEvent/EndGameEvent.hpp ./Logic/Events/EventsOnGame/WinGameEvent/WinGameEvent.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/FactoriesPattern/FactoryEventOnGame/FactoryEventOnGame.cpp -o $(OBJ_FOLDER)FactoryEventOnGame.o

$(OBJ_FOLDER)FactoryEventOnPlayer.o: ./Logic/FactoriesPattern/FactoryEventOnPlayer/FactoryEventOnPlayer.cpp ./Logic/FactoriesPattern/FactoryEventOnPlayer/FactoryEventOnPlayer.hpp ./Logic/Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.hpp ./Logic/Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.hpp ./Logic/Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/FactoriesPattern/FactoryEventOnPlayer/FactoryEventOnPlayer.cpp -o $(OBJ_FOLDER)FactoryEventOnPlayer.o

$(OBJ_FOLDER)EventView.o: ./Graphic/EventView/EventView.cpp ./Graphic/EventView/EventView.hpp ./Logic/Utility/Position.hpp
	$(CC) $(COMPILE_FLAGS) ./Graphic/EventView/EventView.cpp -o $(OBJ_FOLDER)EventView.o

$(OBJ_FOLDER)Generator.o: ./Logic/Generators/Generator/Generator.cpp ./Logic/Generators/Generator/Generator.hpp ./Logic/Map/Map.hpp ./Graphic/MapView/MapView.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Generators/Generator/Generator.cpp -o $(OBJ_FOLDER)Generator.o

$(OBJ_FOLDER)EventGenerator.o: ./Logic/Generators/EventGenerator/EventGenerator.cpp ./Logic/Generators/EventGenerator/EventGenerator.hpp ./Logic/FactoriesPattern/FactoryEventOnPlayer/FactoryEventOnPlayer.hpp ./Logic/FactoriesPattern/FactoryEventOnMap/FactoryEventOnMap.hpp ./Logic/FactoriesPattern/FactoryEventOnGame/FactoryEventOnGame.hpp ./Logic/Map/Map.hpp ./Graphic/MapView/MapView.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Generators/EventGenerator/EventGenerator.cpp -o $(OBJ_FOLDER)EventGenerator.o

$(OBJ_FOLDER)EnemyGenerator.o: ./Logic/Generators/EnemyGenerator/EnemyGenerator.cpp ./Logic/Generators/EnemyGenerator/EnemyGenerator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Generators/EnemyGenerator/EnemyGenerator.cpp -o $(OBJ_FOLDER)EnemyGenerator.o

$(OBJ_FOLDER)Log.o: ./Logic/Logging/Log/Log.cpp ./Logic/Logging/Log/Log.hpp ./Logic/Utility/Enumerations.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Logging/Log/Log.cpp -o $(OBJ_FOLDER)Log.o

$(OBJ_FOLDER)LogMediator.o: ./Logic/MediatorPattern/LogMediator/LogMediator.cpp ./Logic/MediatorPattern/LogMediator/LogMediator.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/MediatorPattern/LogMediator/LogMediator.cpp -o $(OBJ_FOLDER)LogMediator.o

$(OBJ_FOLDER)ConsoleLogger.o: ./Logic/Logging/Loggers/ConsoleLogger/ConsoleLogger.cpp ./Logic/Logging/Loggers/ConsoleLogger/ConsoleLogger.hpp ./Logic/Logging/Loggers/Logger.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Logging/Loggers/ConsoleLogger/ConsoleLogger.cpp -o $(OBJ_FOLDER)ConsoleLogger.o

$(OBJ_FOLDER)FileLogger.o: ./Logic/Logging/Loggers/FileLogger/FileLogger.cpp ./Logic/Logging/Loggers/FileLogger/FileLogger.hpp ./Logic/Logging/Loggers/Logger.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Logging/Loggers/FileLogger/FileLogger.cpp -o $(OBJ_FOLDER)FileLogger.o

$(OBJ_FOLDER)LogController.o: ./Logic/Controllers/LogController/LogController.cpp ./Logic/Controllers/LogController/LogController.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/Controllers/LogController/LogController.cpp -o $(OBJ_FOLDER)LogController.o

$(OBJ_FOLDER)GameControllCommandsConverter.o: ./Logic/CommandReader/GameControllCommandsConverter/GameControllCommandsConverter.cpp ./Logic/CommandReader/GameControllCommandsConverter/GameControllCommandsConverter.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/CommandReader/GameControllCommandsConverter/GameControllCommandsConverter.cpp -o $(OBJ_FOLDER)GameControllCommandsConverter.o

$(OBJ_FOLDER)GameControllCommandsReader.o: ./Logic/CommandReader/GameControllCommandsReader/GameControllCommandsReader.cpp ./Logic/CommandReader/GameControllCommandsReader/GameControllCommandsReader.hpp
	$(CC) $(COMPILE_FLAGS) ./Logic/CommandReader/GameControllCommandsReader/GameControllCommandsReader.cpp -o $(OBJ_FOLDER)GameControllCommandsReader.o
	
clean:
	rm $(OBJ_FOLDER)*.o
	