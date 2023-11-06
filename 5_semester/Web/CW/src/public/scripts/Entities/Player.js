import { Entity } from "./Entity.js";
import { Bonus } from "./Bonus.js"
import { Ghost } from "./Ghost.js"
import { Bonuses, PlayerStates } from "../enums.js";


export class Player extends Entity {
    /* Класс игрока */

    lifetime = 0;
    points = 0;
    power = false;
    state = PlayerStates.stay;
    /*
    constructor (x, y, w, h, lifetime=100) {
        super(x, y, w, h);
        this.lifetime = lifetime;
    }
    */

    kill() { 
        this.game_manager.deleteObject(this.id);
    }

    take_bonus(bonus){
        switch(bonus.type){
            case Bonuses.simple_pill:
                this.points += 100;
                break;
            case Bonuses.power_pill:
                this.game_manager.power_mode();
                break;
            case Bonuses.cherry:
                this.points += 300;
                break;
        }
        console.log(bonus.type, this.points);
    }

    onTouchObjet(obj) {
        if(obj instanceof Bonus) {
            this.take_bonus(obj);
            obj.kill();
        } else if (obj instanceof Ghost) {
            if (this.power){
                obj.kill();
            } else {
                this.kill();
            }
        }
    }

    draw(ctx) { 
        this.sprite_manager.drawSprite(ctx, this);
    }

}