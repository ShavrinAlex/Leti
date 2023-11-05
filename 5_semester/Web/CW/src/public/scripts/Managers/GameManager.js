import { MapManager } from "./MapManager.js";
import { SpriteManager } from "./SpriteManager.js";
import { events_manager } from "./EventsManager.js";
import { PhysicManager } from "./PhysicManager.js";

import { Player } from "../Entities/Player.js"
import { Ghost } from "../Entities/Ghost.js"
import { Bonus } from "../Entities/Bonus.js"
import { Actions, Directions, States } from "../enums.js";

export class GameManager { 
    canvas = null;
    ctx = null;

    factory = {};
    objects = [];
    player = null;

    map_manager = new MapManager();
    sprite_manager = new SpriteManager();
    events_manager = events_manager;
    physic_manager = new PhysicManager();

    initPlayer(obj) { 
        this.player = obj;
    }

    deleteObject(id) {
        for (let i = 0; i < this.objects.length; i++){
            if (this.objects[i].id == id){
                this.objects.splice(i, 1);
            }
        }
    }

    createGameObject(obj_type, id, name, x, y, w, h) {
        try {
            let game_object = new this.factory[obj_type];
            game_object.id = id
            game_object.name = name;
            game_object.pos_x = x;
            game_object.pos_y = y - h;
            game_object.size_x = w;
            game_object.size_y = h;
            game_object.sprite_manager = this.sprite_manager;
            game_object.game_manager = this;

            if(obj_type !== "Bonus"){
                game_object.physic_manager = this.physic_manager;
            } else {
                game_object.type = name;
            }

            this.objects.push(game_object)
            if(obj_type === "Player"){
                this.initPlayer(game_object);
            }

            game_object.draw(this.ctx);
        } catch (ex) {
            console.log("Error while creating: [" + id + "] " + obj_type + ", " + ex);
        }
    }

    draw(){
        this.objects.forEach((object) => {
            object.draw(this.ctx)
        })
    }

    update() {
        if(this.player === null){
            return;
        }

        if (this.events_manager.action !== Actions.stay){
            this.player.state = States.move;
        } else {
            this.player.state = States.stay;
        }

        switch (this.events_manager.action) {
            case Actions.move_up:
                this.player.request_direction = Directions.up;
                break;
            case Actions.move_down:
                this.player.request_direction = Directions.down;
                break;
            case Actions.move_left:
                this.player.request_direction = Directions.left;
                break;
            case Actions.move_right:
                this.player.request_direction = Directions.right;
                break;
        }
        //console.log(this.player.state, this.player.direction )

        //console.log(this.player.move_y, this.player.move_x)
        this.objects.forEach(function(e) {
            try {
                e.update();
            } catch(ex) {}
        });

        this.map_manager.draw(this.canvas, this.ctx);
        this.map_manager.centerAt(this.player.pos_x, this.player.pos_y);
        this.draw();
    }

    loadAll() { 
        this.canvas = document.getElementById("play_field");
        this.ctx = this.canvas.getContext("2d");
    
        this.map_manager.loadMap("../public/levels/level_2.json");
        this.sprite_manager.loadAtlas("../public/images/atlas.json", "../public/images/atlas.png");
        this.sprite_manager.map_manager = this.map_manager;
        this.physic_manager.map_manager = this.map_manager;
        this.physic_manager.game_manager = this;

        this.factory['Player'] = Player;
        this.factory['Ghost'] = Ghost;
        this.factory['Bonus'] = Bonus;
        this.map_manager.draw(this.canvas, this.ctx);
        this.map_manager.parseEntities(this);   
    }

    power_mode() {
        let self = this;
        for (let i = 0; i < this.objects; i++){
            if (this.objects[i] instanceof Ghost){
                this.objects[i].is_afraid = true
            }
        }
        setTimeout(() => {
            for (let i = 0; i < this.objects; i++){
                if (this.objects[i] instanceof Ghost){
                    this.objects[i].is_afraid = false
                }
            }
        }, 1000);
    }   
    play(updateWorld) {
        let self = this;
        setInterval(updateWorld, 50);
        let animation_id = 0;
        setInterval(function () {
            self.player.animation_id = animation_id++;
            animation_id %= 3;
        }, 100);
    }
}

