import { GameObject } from "./GameObject.js";


export class Bonus extends GameObject {
    /* Класс бонуса для игрока */
    type = null;

    draw(ctx) { 
        this.sprite_manager.drawSprite(ctx, this.name, this.pos_x, this.pos_y);
    }

    kill() { 
        this.game_manager.deleteObject(this.id);
    }
}