import { MapManager } from "./MapManager.js";
import { SpriteManager } from "./SpriteManager.js";
import { PhysicManager } from "./PhysicManager.js";
import { GhostManager } from "./GhostManager.js";
import { sm } from "./SoundManager.js";

import { Player } from "../Entities/Player.js"
import { Ghost } from "../Entities/Ghost.js"
import { Bonus } from "../Entities/Bonus.js"
import { Actions, Directions, GameStates, GhostStates, Levels, PlayerStates, Sounds } from "../enums.js";


export class GameManager { 
    canvas = null;
    ctx = null;

    level = null;
    state = null;

    factory = {};

    sprite_manager = new SpriteManager();
    sound_manager = sm;
    events_manager = null;


    constructor (event_manager) {
        this.canvas = document.getElementById("play_field");
        this.ctx = this.canvas.getContext("2d");

        this.factory['Player'] = Player;
        this.factory['Ghost'] = Ghost;
        this.factory['Bonus'] = Bonus;

        this.events_manager = event_manager;
        this.level = event_manager.level;
        this.state = event_manager.game_state;

        this.sprite_manager.loadAtlas("../public/images/atlas.json", "../public/images/atlas.png");

        this.sound_manager.loadArray([Sounds.pill, Sounds.power, Sounds.ghost, Sounds.win, Sounds.loose]);
        this.loadAll();
    }

    initPlayer(obj) { 
        this.player = obj;
        this.player.speed = 8;
        this.player.sound_manager = this.sound_manager;
        let self = this;
        let animation_id = 0;
        this.playerIntervalId = setInterval(function () {
            self.player.animation_id = animation_id++;
            animation_id %= 3;
        }, 100);
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

        if(obj_type === "Ghost"){
            game_object.ghost_manager = this.ghost_manager;
            game_object.speed = 4;
        }

        this.objects.push(game_object)
        if(obj_type === "Player"){
            this.initPlayer(game_object);
        }
        game_object.draw(this.ctx);
    }

    draw(){
        this.objects.forEach((object) => {
            object.draw(this.ctx)
        })
    }

    update() {
        this.showInfo();
        this.check_game_state();

        if (this.state == GameStates.stop){
            //console.log('stop');
            return;
        }
        if(this.player === null){
            return;
        }

        if (this.is_end_game()){
           this.game_win();
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
        //this.map_manager.centerAt(this.player.pos_x, this.player.pos_y);
        this.draw();
    }

    loadAll() { 
        clearTimeout(this.powerTimerId_1);
        clearTimeout(this.powerTimerId_2);
        clearInterval(this.ghostIntervalId);
        this.sound_manager.stopAll();
        this.objects = [];
        this.player = null;

        this.powerTimerId_1 = null;
        this.powerTimerId_2 = null;
        this.ghostIntervalId = null;
        
        //console.log('load all');
        this.map_manager = new MapManager();
        this.physic_manager = new PhysicManager();
        this.ghost_manager = new GhostManager();

        // Настройка менеджеров игры
        this.map_manager.loadMap(this.level);
        
        this.sprite_manager.map_manager = this.map_manager;
        this.physic_manager.map_manager = this.map_manager;
        this.physic_manager.game_manager = this;
        this.ghost_manager.map_manager = this.map_manager;
        this.ghost_manager.game_manager = this;

        this.map_manager.draw(this.canvas, this.ctx);
        this.map_manager.parseEntities(this);
        this.draw(); 
    }

    power_mode() {
        let self = this;

        if (this.player.power){
            clearTimeout(this.powerTimerId_1);
            clearTimeout(this.powerTimerId_2);
            clearInterval(this.ghostIntervalId);
            this.sound_manager.stopAll();
        }

        this.player.power = true;
        for (let i = 0; i < this.objects.length; i++){
            if (this.objects[i] instanceof Ghost){
                this.objects[i].state = GhostStates.afraid;
                this.objects[i].animation_id = 0;
            }
        }
        this.sound_manager.play(Sounds.power, {'volume': 0.7, 'looping': true});
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
                this.sound_manager.stopAll();
            }, 3000);
        }, 5000);
    }   

    kill_player() {
        console.log('kill')
        this.sound_manager.play(Sounds.loose, {'volume': 0.7});
        this.state = GameStates.stop;
        this.events_manager.game_state = this.state;
        console.log(this.state === GameStates.stop)
        //clearInterval(this.gameIntervalId);
        //clearInterval(this.gameIntervalId);
        /*
        clearInterval(this.playerIntervalId);
        this.player.state = PlayerStates.dead;
        let animation_id = 0;
        this.playerIntervalId = setInterval(function () {
            self.player.animation_id = animation_id++;
            animation_id %= 2;
        }, 500);
        */

    }

    revive_ghost(ghost_id) {
        let self = this;
        setTimeout(() => {
            this.map_manager.parseGhost(this, ghost_id);
        }, 4000);
    }

    play(updateWorld) {
        let self = this;
        this.gameIntervalId = setInterval(updateWorld, 50);
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

    game_win(){
        //clearInterval(this.gameIntervalId);
        this.state = GameStates.stop;
        this.events_manager.game_state = this.state;
        let self = this;
        self.sound_manager.stopAll();
        let img = new Image();
        img.src = "../public/images/pac-man/other/pac_man_text/spr_message_2.png"
        img.onload = function () {
            self.ctx.drawImage(img, self.map_manager.mapSize.x/2-44, self.map_manager.mapSize.y/2-36);
            self.sound_manager.play(Sounds.win, {'volume': 0.7});
            console.log('end')
        }
    }

    check_game_state(){
        if (this.state !== this.events_manager.game_state){
            this.state = this.events_manager.game_state;
        }
        if (this.level !== this.events_manager.level){
            console.log('change_level')
            this.end_level();
            this.level = this.events_manager.level;
            this.loadAll();
        }
        if (this.events_manager.is_end_game){
            this.stop_game();
            this.end_level();
            window.location = './game_over';
        }
    }

    end_level(){
        let score_table = JSON.parse(localStorage["pac_man.score_table"]);
        let is_exists_username = false;
        let level = (this.level == Levels.level_1) ? 1 : 2;
        let score = this.player.points;

        /* Updating a user's result or creating a new entry */
        for (let i = 0; i < score_table.length; i++){
            if (score_table[i].name == localStorage["pac_man.username"] && score_table[i].level == level){
                score_table[i].score = score;
                is_exists_username = true;
                break
            }
        }

        if (!is_exists_username){
            score_table.push({
                name: localStorage["pac_man.username"],
                level: level,
                score: score
            })
        }
        
        localStorage["pac_man.score_table"] = JSON.stringify(score_table)
    }

    stop_game(){
        clearInterval(this.gameIntervalId);
        clearTimeout(this.powerTimerId_1);
        clearTimeout(this.powerTimerId_2);
        clearInterval(this.ghostIntervalId);
        clearInterval(this.ghostIntervalId);
        clearInterval(this.playerIntervalId);
    }

    showInfo(){
        if (this.player){
            document.getElementById('username').innerHTML = `Username: ${window.localStorage['pac_man.username']}`;
            document.getElementById('level').innerHTML = `Level: ${(this.level === Levels.level_1) ? 1 : 2}`;
            document.getElementById('score').innerHTML = `Score: ${this.player.points}`;
        }
    }
}

