import { Entity } from "./Entity.js";


export class Ghost extends Entity{
    /* Класс привидения */

    lifetime = 0;
    is_afraid = false;
    /*
    constructor (x, y, w, h, lifetime=100) {
        super(x, y, w, h);
        this.lifetime = lifetime;
    }
    */

    draw(ctx) { 
        this.sprite_manager.drawSprite(ctx, this.name, this.pos_x, this.pos_y, this.direction);
    }

    update() { 

    }
    
    onTouchEntity(obj) { 

    }

    kill() { 

    }
}