import { GhostStates, Directions } from "../enums.js";
import { Ghost } from "../Entities/Ghost.js";
import { AStar } from "./HelperClasses/A*.js";



export class GhostManager {
    map_manager = null;
    game_manager = null;

    search(ghost, ghost_pos){
        let new_direction;
        
    }

    chase(ghost, ghost_pos, player_pos){
        let next_tile = AStar(this.map_manager.mapMatrix, ghost_pos, player_pos)[1];
        console.log(next_tile);
        let dir_x = next_tile.x - ghost_pos.x;
        let dir_y = next_tile.y - ghost_pos.y;
        switch(dir_x){
            case 1:
                ghost.request_direction = Directions.right;
                break;
            case -1:
                ghost.request_direction = Directions.left;
                break;
        }

        switch(dir_y){
            case 1:
                ghost.request_direction = Directions.down;
                break;
            case -1:
                ghost.request_direction = Directions.up;
                break;
        }
    }

    afraid(ghost){

    }

    update(ghost){
        let ghost_pos = {'x': Math.round(ghost.pos_x / this.map_manager.tSize.x), 'y': Math.round(ghost.pos_y / this.map_manager.tSize.x)};
        let player_pos = {'x': Math.round(this.game_manager.player.pos_x / this.map_manager.tSize.x), 'y': Math.round(this.game_manager.player.pos_y / this.map_manager.tSize.x)};

        if (Math.abs(ghost_pos.x - player_pos.x) < 5 || Math.abs(ghost_pos.y - player_pos.y)){
            ghost.state = GhostStates.chase;
        } else {
            ghost.state = GhostStates.search;
        }

        switch (ghost.state){
            case GhostStates.search:
                this.search(ghost, ghost_pos);
                break;
            case GhostStates.chase:
                this.chase(ghost, ghost_pos, player_pos);
                break;
            case GhostStates.afraid:
                //this.afraid(ghost);
                break;
        }
    }
}