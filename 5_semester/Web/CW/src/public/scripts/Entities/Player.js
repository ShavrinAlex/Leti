import { Entity } from "./Entity.js";
import { Bonus } from "./Bonus.js"
import { Ghost } from "./Ghost.js"
import { Bonuses, States } from "../enums.js";


export class Player extends Entity {
    /* Класс игрока */

    lifetime = 0;
    points = 0;
    power = false;
    animation_id = 0;
    /*
    constructor (x, y, w, h, lifetime=100) {
        super(x, y, w, h);
        this.lifetime = lifetime;
    }
    */

    kill() { 
        this.lifetime = 0;
    }

    take_bonus(bonus){
        switch(bonus.type){
            case Bonuses.simple_pill:
                this.points += 100;
                break;
            case Bonuses.power_pill:
                let self = this;
                self.power = true;
                setTimeout(function (){
                    self.power = false;
                    console.log(self.power);
                }, 1000);
                console.log(self.power);
                break;
            case Bonuses.cherry:
                this.points += 300;
                break;
        }
        console.log(bonus.type, this.points);
    }

    onTouchWall(){
        /* Метод, орабатывающий столкновение со стеной */

        //this.state = States.stay;
    }

    onTouchObjet(obj) {
        
        if(obj instanceof Bonus) {
            this.take_bonus(obj);
            obj.kill();
        } else if (obj instanceof Ghost) {
            // this.kill
            console.log('kill')
        }
    }

    draw(ctx) { 
        this.sprite_manager.drawSprite(ctx, this.name, this.pos_x, this.pos_y, this.direction, this.animation_id);
    }

}