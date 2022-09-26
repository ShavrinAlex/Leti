#include "StartDialog.hpp"
#include "Game.hpp"

int main(){
    StartDialog start_dialog = StartDialog();
    Game game = Game(start_dialog.getWidth(), start_dialog.getHeight());
    return game.game_executor();
}
