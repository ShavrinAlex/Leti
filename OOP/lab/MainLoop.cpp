#include <SFML/Graphics.hpp>
#include "MainLoop.h"
#include <iostream>

//player
void MainLoop::setPlayerPosition(Position pp){
    player_position = pp;
};

//map
void MainLoop::setMapSize(int h, int w){
    map_height = h;
    map_width = w;
};

//executor main loop
int MainLoop::executor(sf::RenderWindow* window){
    Map map = Map(map_height, map_width);
    //map.movePlayer(player_position);
    Player player = Player("", 98, 98);
    Drawer drawer = Drawer();
    CommandReader cmdrdr = CommandReader();
    Controller cntrlr = Controller(&player, &map, &drawer);
    player.setController(&cntrlr);
    drawer.setController(&cntrlr);
    map.setPlayerPosition(player_position);
    map.update();
    float timer = 0;
    sf::Clock clock;
    //std::cout<<"map "<<map.getPlayerPosition().x<<' '<<map.getPlayerPosition().y<<'\n';
    //std::cout<<cntrlr.getPlayerPosition().x<<' '<<cntrlr.getPlayerPosition().y<<'\n';
    //std::cout<<"x = "<<cntrlr.getPlayerWidth()<<" y = "<<cntrlr.getPlayerHeight()<<'\n';
    while (window->isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        timer += time;
        int key_was_pressed = 0;

        sf::Event event;
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window->close();
            }
        }
        
        int key = cmdrdr.getPressedKey();
        enum {STAY, RIGHT, LEFT, UP, DOWN};
        if (timer > 150){
            switch (key){
                case 'D':
                    //std::cout<<"d\n";
                    player.move(RIGHT);
                    break;
                case 'A':
                    player.move(LEFT);
                    break;
                case 'W':
                    player.move(UP);
                    break;
                case 'S':
                    player.move(DOWN);
                    key_was_pressed = 1;
                    break;
                case 'Q':
                    window->close();
                    break;
                default:
                    break;
            }
            timer = 0;
        }
        window->clear();
        map.update();
        drawer.drawMap(window);
        drawer.drawPlayer(window);
        //player.draw(window);
        window->display();
    }
    return 0;
};