import { GameManager } from "./Managers/GameManager.js";
import { events_manager } from "./Managers/EventsManager.js";
import { sm } from "./Managers/SoundManager.js"


let game_manager = new GameManager(events_manager, sm);

function updateWorld(){
    game_manager.update();
}

game_manager.play(updateWorld);

