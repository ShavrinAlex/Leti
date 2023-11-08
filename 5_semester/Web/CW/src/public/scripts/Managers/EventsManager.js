import { Actions, Control, Levels, GameStates } from "../enums.js";
import { sm } from "./SoundManager.js";

export let events_manager = new class EventsManager {
    /* Класс менеджера собитий */

    constructor () { 
        this.action = Actions.move_right;
        this.level = Levels[window.localStorage['pac_man.level']];
        this.game_state = GameStates.stop;
        this.is_end_game = false;

        this.btn_start = document.getElementById("start");
        this.btn_next = document.getElementById("next");

        document.body.addEventListener("keydown", this.onKeyDown);
        this.btn_start.addEventListener('click', this.startGame);
        this.btn_next.addEventListener('click', this.next);
        /*
        this.btn_lvl_1 = document.getElementById("level_1");
        this.btn_lvl_2 = document.getElementById("level_2");
        
        

        this.btn_lvl_1.addEventListener('click', this.setLevel_1);
        this.btn_lvl_2.addEventListener('click', this.setLevel_2);
        
        
        */
    }

    onKeyDown(event) {
        /* Метод, осуществляющий обработку нажатия клавиши */
        
        let action = Control[event.keyCode];
        if (action && events_manager.game_state !== GameStates.stop){
            // Запускаем новое действие
            events_manager.action = Actions[action];
        }
        //sm.play("../public/sounds/waka.wav");
    }
    /*
    setLevel_1(event) {
        if (events_manager.level !== Levels.level_1){
            events_manager.game_state = GameStates.stop;
            events_manager.action = Actions.move_right;
        }
        events_manager.level = Levels.level_1;
    }

    setLevel_2(event) {
        if (events_manager.level !== Levels.level_2){
            events_manager.game_state = GameStates.stop;
            events_manager.action = Actions.move_right;
        }
        events_manager.level = Levels.level_2;
    }

    stopGame(event){
        events_manager.game_state = GameStates.stop;
    }
    */
    startGame(event){
        events_manager.game_state = GameStates.start;
    }

    next(event){
        if (events_manager.level === Levels.level_1){
            events_manager.game_state = GameStates.stop;
            events_manager.level = Levels.level_2;
            window.localStorage['pac_man.level'] = 'level_2';
        } else {
            events_manager.game_state = GameStates.stop;
            events_manager.is_end_game = true;
        }
        
    }
}