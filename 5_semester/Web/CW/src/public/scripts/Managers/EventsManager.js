import { Actions, Control } from "../enums.js";

export let events_manager = new class EventsManager {
    /* Класс менеджера собитий */

    constructor () { 
        this.action = Actions.stay;

        document.body.addEventListener("keydown", this.onKeyDown);
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