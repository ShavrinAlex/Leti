import { Entity } from "./Entity.js";
import { Bonus } from "./Bonus.js"
import { Ghost } from "./Ghost.js"
import { Bonuses, PlayerStates, Sounds } from "../enums.js";


export class Player extends Entity {
    /* Класс игрока */

    lifetime = 0;
    points = 0;
    power = false;
    state = PlayerStates.stay;
    sound_manager = null;
    /*
    constructor (x, y, w, h, lifetime=100) {
        super(x, y, w, h);
        this.lifetime = lifetime;
    }
    */
    update() {
        this.physic_manager.update(this);
    }

    kill() { 
        this.game_manager.deleteObject(this.id);
    }

    take_bonus(bonus){
        switch(bonus.type){
            case Bonuses.simple_pill:
                this.points += 100;
                if (!this.power){
                    this.sound_manager.play(Sounds.pill, {'volume': 0.7});
                }
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
                this.sound_manager.play(Sounds.ghost);
            } else {
                this.kill();
            }
        }
    }

    draw(ctx) { 
        this.sprite_manager.drawSprite(ctx, this);
    }

}