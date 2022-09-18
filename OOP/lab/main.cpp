#include "Map.h"


int main(){
    sf::RenderWindow window(sf::VideoMode(640, 480), "My game");
    Map mp;
    
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
