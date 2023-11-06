import { MapManager } from "./MapManager.js";
import { SpriteManager } from "./SpriteManager.js";
import { events_manager } from "./EventsManager.js";
import { PhysicManager } from "./PhysicManager.js";
import { GhostManager } from "./GhostManager.js";

import { Player } from "../Entities/Player.js"
import { Ghost } from "../Entities/Ghost.js"
import { Bonus } from "../Entities/Bonus.js"
import { Actions, Directions, GhostStates, PlayerStates } from "../enums.js";


export class GameManager { 
    canvas = null;
    ctx = null;

    factory = {};
    objects = [];
    player = null;
    gameIntervalId = null;
    powerTimerId_1 = null;
    powerTimerId_2 = null;
    ghostIntervalId = null;
    playerIntervalId = null;

    map_manager = new MapManager();
    sprite_manager = new SpriteManager();
    events_manager = events_manager;
    physic_manager = new PhysicManager();
    ghost_manager = new GhostManager();

    initPlayer(obj) { 
        this.player = obj;
    }

    deleteObject(id) {
        for (let i = 0; i < this.objects.length; i++){
            if (this.objects[i].id == id){
                if (this.objects[i] instanceof Ghost){
                    let ghost_id = this.objects[i].id;
                    this.revive_ghost(ghost_id);
                } else if (this.objects[i] instanceof Player){
                    this.kill_player();
                    break;
                }
                this.objects.splice(i, 1);
            }
        }
    }

    createGameObject(obj_type, id, name, x, y, w, h) {
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
        //game_object.draw(this.ctx);
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

        if (this.is_end_game()){
           this.game_over();
        }

        if (this.player.state !== PlayerStates.dead){
            if (this.events_manager.action !== Actions.stay){
                this.player.state = PlayerStates.move;
            } else {
                this.player.state = PlayerStates.stay;
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
        }

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
        
        this.factory['Player'] = Player;
        this.factory['Ghost'] = Ghost;
        this.factory['Bonus'] = Bonus;

        // Настройка менеджеров игры
        this.map_manager.loadMap(this.events_manager.level);
        this.sprite_manager.loadAtlas("../public/images/atlas.json", "../public/images/atlas.png");
        this.sprite_manager.map_manager = this.map_manager;
        this.physic_manager.map_manager = this.map_manager;
        this.physic_manager.game_manager = this;
        this.ghost_manager.map_manager = this.map_manager;
        this.ghost_manager.game_manager = this;

        this.map_manager.draw(this.canvas, this.ctx);
        this.map_manager.parseEntities(this);   
    }

    power_mode() {
        let self = this;

        if (this.player.power){
            clearTimeout(this.powerTimerId_1);
            clearTimeout(this.powerTimerId_2);
            clearInterval(this.ghostIntervalId);
        }

        this.player.power = true;
        for (let i = 0; i < this.objects.length; i++){
            if (this.objects[i] instanceof Ghost){
                this.objects[i].state = GhostStates.afraid;
                this.objects[i].animation_id = 0;
            }
        }
        this.powerTimerId_1 = setTimeout(() => {
            let ghost_animation_id = 0;
            this.ghostIntervalId = setInterval(function () {
                for (let i = 0; i < self.objects.length; i++){
                    if (self.objects[i] instanceof Ghost){
                        self.objects[i].animation_id = ghost_animation_id;
                    }
                }
                ghost_animation_id++;
                ghost_animation_id %= 2;
            }, 300);
            this.powerTimerId_2 = setTimeout(() => {
                for (let i = 0; i < self.objects.length; i++){
                    if (self.objects[i] instanceof Ghost){
                        self.objects[i].state = GhostStates.search;
                    }
                }
                self.player.power = false;
                clearInterval(self.ghostIntervalId);
            }, 3000);
        }, 5000);
    }   

    kill_player() {
        let self = this;
        clearInterval(this.playerIntervalId);
        this.player.state = PlayerStates.dead;
        let animation_id = 0;
        this.playerIntervalId = setInterval(function () {
            self.player.animation_id = animation_id++;
            animation_id %= 2;
        }, 500);
    }

    revive_ghost(ghost_id) {
        let self = this;
        setTimeout(() => {
            this.map_manager.parseGhost(this, ghost_id);
        }, 8000);
    }

    play(updateWorld) {
        let self = this;
        this.gameIntervalId = setInterval(updateWorld, 50);
        let animation_id = 0;
        this.playerIntervalId = setInterval(function () {
            self.player.animation_id = animation_id++;
            animation_id %= 3;
        }, 100);
    }

    is_end_game(){
        let is_end_game = true;
        this.objects.forEach((object) => {
            if (object instanceof Bonus){
                is_end_game = false;
            }
        })
        return is_end_game;
    }

    game_over(){
        let self = this
        let img = new Image();
        img.src = "../public/images/pac-man/other/pac_man_text/spr_message_2.png"
        img.onload = function () {
            self.ctx.drawImage(img, self.map_manager.mapSize.x/2-44, self.map_manager.mapSize.y/2-36);
            console.log('end')
        }
    }
}

