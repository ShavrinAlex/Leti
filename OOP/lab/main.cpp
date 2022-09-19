#include "Map.h"



int main(){
    sf::RenderWindow window(sf::VideoMode(500, 500), "My game");
    Map mp = Map();
    
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    window.clear();
    mp.draw(&window);
    //window.draw();
    window.display();
    }
    return 0;
};
