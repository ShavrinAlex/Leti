import { Sprite } from "./HelperClasses/Sprite.js"
import { Directions } from "../enums.js";


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

    drawSprite(ctx, name, x, y, direction=undefined, animation_id=undefined) {
        let self = this;
        if (!this.imgLoaded || !this.jsonLoaded) {
            setTimeout(function () { 
                self.drawSprite(ctx, name, x, y, direction); 
            }, 100);
        } else {
            let sprite_name = name;

            switch(direction){
                case Directions.up:
                    sprite_name += '_up';
                    if (name == 'pac_man'){
                        sprite_name += `_${animation_id}`;
                    }
                    break;
                case Directions.down:
                    sprite_name += '_down';
                    if (name == 'pac_man'){
                        sprite_name += `_${animation_id}`;
                    }
                    break;
                case Directions.left:
                    sprite_name += '_left';
                    if (name == 'pac_man'){
                        sprite_name += `_${animation_id}`;
                    }
                    break;
                case Directions.right:
                    sprite_name += '_right';
                    if (name == 'pac_man'){
                        sprite_name += `_${animation_id}`;
                    }
                    break;
                default:
                    break;
            }
            console.log(sprite_name)
            let sprite = this.getSprite(sprite_name);
            if(!this.map_manager.isVisible(x, y, sprite.w, sprite.h)){
                return;
            }

            x -= this.map_manager.view.x;
            y -= this.map_manager.view.y;

            ctx.drawImage(this.image, sprite.x, sprite.y, sprite.w, sprite.h, x, y, sprite.w, sprite.h);
        }
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