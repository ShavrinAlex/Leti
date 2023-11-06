import { Sprite } from "./HelperClasses/Sprite.js"
import { Directions, GhostStates, SpriteSuffixs, PlayerStates } from "../enums.js";
import { Bonus } from "../Entities/Bonus.js";
import { Player } from "../Entities/Player.js";
import { Ghost } from "../Entities/Ghost.js";


export class SpriteManager {
    /* Класс менеджера спрайтов */
    image = new Image();
    sprites = new Array();
    imgLoaded = false;
    jsonLoaded = false;
    map_manager = null;

    loadAtlas(atlasJson, atlasImg) {
        let self = this;
        let request = new XMLHttpRequest();
        request.onreadystatechange = function () {
            if (request.readyState === 4 && request.status === 200) {
                self.parseAtlas(request.responseText); 
            }
        };
        request.open("GET", atlasJson, true); 
        request.send();
        this.loadImg(atlasImg);
    }

    loadImg(imgName) { 
        let self = this;
        this.image.onload = function () {
            self.imgLoaded = true;
        };
        this.image.src = imgName;
    }

    parseAtlas(atlasJSON) {
        let atlas = JSON.parse(atlasJSON);
        for (let name in atlas.frames) {
            let frame = atlas.frames[name].frame; 
            let sprite = new Sprite(name, frame.x, frame.y, frame.w, frame.h);
            this.sprites.push(sprite);
        }
        this.jsonLoaded = true; 
    }

    drawSprite(ctx, object) {
        let self = this;
        if (!this.imgLoaded || !this.jsonLoaded) {
            setTimeout(function () { 
                self.drawSprite(ctx, object); 
            }, 100);
        } else {
            let sprite_name = this.getSpriteName(object);
            let x = object.pos_x;
            let y = object.pos_y;
            
            
            let sprite = this.getSprite(sprite_name);
            if(!this.map_manager.isVisible(x, y, sprite.w, sprite.h)){
                return;
            }

            x -= this.map_manager.view.x;
            y -= this.map_manager.view.y;

            ctx.drawImage(this.image, sprite.x, sprite.y, sprite.w, sprite.h, x, y, sprite.w, sprite.h);
        }
    }

    getSpriteName(object){
        let sprite_name = object.name;
        if (!(object instanceof Bonus)){
            if (object instanceof Ghost && object.state === GhostStates.afraid){
                sprite_name = 'ghost_afraid';
                sprite_name += `_${object.animation_id}`
            } else if (object instanceof Player && (object.state == PlayerStates.dead)){
                sprite_name = 'pacdeath';
                //console.log(sprite_name)
            }
            switch(object.direction){
                case Directions.up:
                    if (object instanceof Ghost){
                        sprite_name += SpriteSuffixs.right;
                    } else {
                        sprite_name += SpriteSuffixs.up;
                    }
                    break;
                case Directions.down:
                    if (object instanceof Ghost){
                        sprite_name += SpriteSuffixs.left;
                    } else {
                        sprite_name += SpriteSuffixs.down;
                    }
                    break;
                case Directions.left:
                    sprite_name += SpriteSuffixs.left;
                    break;
                case Directions.right:
                    sprite_name += SpriteSuffixs.right;
                    break;
                default:
                    break;
            }
            if (object instanceof Player){
                sprite_name += `_${object.animation_id}`;
            }
        }
        return sprite_name;
    }

    getSprite(name) { 
        for (let i = 0; i < this.sprites.length; i++) {
            let sprite = this.sprites[i];
            if (sprite.name === name) {
                return sprite;
            }
        }
        return null;
    }
}