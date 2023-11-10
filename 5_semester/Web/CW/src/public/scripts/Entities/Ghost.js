import { GhostStates } from "../enums.js";
import { Entity } from "./Entity.js";


export class Ghost extends Entity{
    /* Класс привидения */

    lifetime = 0;
    state = GhostStates.stay;
    ghost_manager = null;

    draw(ctx) { 
        this.sprite_manager.drawSprite(ctx, this);
    }

    update() {
        if (Number.isInteger(this.pos_x / 32) && Number.isInteger(this.pos_y / 32)){
            this.ghost_manager.update(this);
        }
        this.physic_manager.update(this);
    }
    
    onTouchEntity(obj) { 
        if (obj instanceof Player && !obj.power){
            obj.kill()
        }
    }

    kill() { 
        this.game_manager.deleteObject(this.id);
    }
}