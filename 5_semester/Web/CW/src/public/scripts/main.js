import { GameManager } from "./Managers/GameManager.js";


let game_manager = new GameManager();
game_manager.loadAll();

function updateWorld(){
    game_manager.update();
}

game_manager.play(updateWorld);

