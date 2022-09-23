#include "StartDialog.hpp"
#include "RenderWindow.hpp"
#include "Game.hpp"

int main(){
    StartDialog start_dialog = StartDialog();
    RenderWindow window = RenderWindow(start_dialog.getWidth(), start_dialog.getHeight(), "hero1");
    Game game = Game(window);
    return game.game_executor();
}
