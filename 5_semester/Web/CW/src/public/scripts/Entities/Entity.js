import { GameObject } from "./GameObject.js";
import { States, Directions } from "../enums.js";

export class Entity extends GameObject {
    /* Класс игровой сущности */

    direction = Directions.right;
    request_direction = Directions.right;
    state = States.stay;
    speed = 8;
    physic_manager = null;
    /*
    constructor (x, y, w, h) {
        pos_x = x;
        pos_y = y;
        size_x = w;
        size_y = h;
    }
    */
    update() {
        this.physic_manager.update(this);
    }
}