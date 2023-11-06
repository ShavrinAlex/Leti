import { Actions, Control, Levels } from "../enums.js";

export let events_manager = new class EventsManager {
    /* Класс менеджера собитий */

    constructor () { 
        this.action = Actions.stay;
        this.level = Levels.level_2;

        document.body.addEventListener("keydown", this.onKeyDown);
        let btn_lvl_1 = document.getElementById("level_1");
        let btn_lvl_2 = document.getElementById("level_2");
        btn_lvl_1.addEventListener('click', (event) => {events_manager.level = Levels.level_1});
        btn_lvl_2.addEventListener('click', (event) => {events_manager.level = Levels.level_2});
    }

    onKeyDown(event) {
        /* Метод, осуществляющий обработку нажатия клавиши */
        
        let action = Control[event.keyCode];
        if (action){
            // Запускаем новое действие
            events_manager.action = Actions[action];
        }
        
    }
}