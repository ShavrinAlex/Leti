import { GameObject } from "./GameObject.js";
import { Directions } from "../enums.js";

export class Entity extends GameObject {
    /* Класс игровой сущности */

    direction = Directions.right;
    request_direction = Directions.right;
    animation_id = 0;
    speed = 8;
    physic_manager = null;
    /*
    update() {
        this.physic_manager.update(this);
    }*/
}