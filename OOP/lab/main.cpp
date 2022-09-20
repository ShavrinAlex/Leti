#include "StartDialog.h"
#include "MainLoop.h"
#include <SFML/Graphics.hpp>
#define SIZE_CELL 98


int main(){
    StartDialog sd = StartDialog();
    sf::RenderWindow window(sf::VideoMode(sd.getHeight()*SIZE_CELL , sd.getWidth()*SIZE_CELL ), "My game");
    window.setFramerateLimit(60);

    MainLoop ml = MainLoop();
    ml.setPlayerPosition(sd.getPlayerPosition());

    float CurrentFrame = 0;
    sf::Clock clock;

    ml.setMapSize(sd.getHeight(), sd.getWidth());
    ml.executor(&window);
    
    return 0;
};

 /*
    //start dialog
    int n, m;
    std::cout<<"Введите размеры поля (n на m клеток):\n";
    std::cout<<"Высота: ";
    std::cin>>n;
    std::cout<<"Ширина: ";
    std::cin>>m;

    //App
    sf::RenderWindow window(sf::VideoMode(m*98, n*98), "My game");
    window.setFramerateLimit(60);

    Map mp = Map(m, n);
    Player p = Player("", 100, 100, 98, 98);
    float CurrentFrame = 0;
    sf::Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не мощности/загруженности процессора). 
    while (window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/800; //скорость игры

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }


        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
            p.set_direction(0);
            p.set_speed(0.1f);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))){
            p.set_direction(1);
            p.set_speed(0.1);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))){
            p.set_direction(2);
            p.set_speed(0.1);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))){
            p.set_direction(3);
            p.set_speed(0.1);
        }
        
            
        

        window.clear();
        p.update(time, &mp);
        mp.update(&p);
        mp.draw(&window);
        p.draw(&window);
        window.display();
    }
    //end app
    */
