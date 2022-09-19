#include "Map.h"
#include <iostream>


int main(){
    int n, m;
    std::cout<<"Введите размеры поля (n на m клеток):\n";
    std::cout<<"Высота: ";
    std::cin>>n;
    std::cout<<"Ширина: ";
    std::cin>>m;

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
            std::cout<<"r ";
            std::cout<<p.get_direction()<<'\n';
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))){
            p.set_direction(1);
            p.set_speed(0.1);
            std::cout<<"l ";
            std::cout<<p.get_direction()<<'\n';
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))){
            p.set_direction(3);
            p.set_speed(0.1);
            std::cout<<"u ";
            std::cout<<p.get_direction()<<'\n';
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))){
            p.set_direction(2);
            p.set_speed(0.1);
            std::cout<<"d ";
            std::cout<<p.get_direction()<<'\n';
        }
            
        

        window.clear();
        p.update(time);
        mp.update(&p);
        mp.draw(&window);
        p.draw(&window);
        window.display();
    }
    return 0;
};
