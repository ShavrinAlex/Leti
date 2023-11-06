import { GhostStates } from "../enums.js";
import { Entity } from "./Entity.js";


export class Ghost extends Entity{
    /* Класс привидения */

    lifetime = 0;
    state = GhostStates.stay;

    draw(ctx) { 
        this.sprite_manager.drawSprite(ctx, this);
    }

    update() { 

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