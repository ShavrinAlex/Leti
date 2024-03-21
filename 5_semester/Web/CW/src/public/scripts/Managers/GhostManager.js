import { GhostStates, Directions } from "../enums.js";
import { AStar } from "./HelperClasses/A*.js";



export class GhostManager {
    map_manager = null;
    game_manager = null;

    search(ghost){
        //console.log('search')
        let direction = Math.floor(Math.random() * Object.keys(Directions).length);
        //console.log(direction)
        ghost.request_direction = direction;
        //console.log(ghost.request_direction)
    }

    chase(ghost, ghost_pos, player_pos){
        //console.log('chase')
        let path = AStar(this.map_manager.mapMatrix, ghost_pos, player_pos);
        let next_tile = path[0];
        //console.log(next_tile)
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
        //console.log(next_tile, ghost.request_direction)
    }

    afraid(ghost){

    }

    update(ghost){
        //console.log('update', ghost);
        let ghost_pos = {'x': Math.round(ghost.pos_x / this.map_manager.tSize.x), 'y': Math.round(ghost.pos_y / this.map_manager.tSize.x)};
        let player_pos = {'x': Math.round(this.game_manager.player.pos_x / this.map_manager.tSize.x), 'y': Math.round(this.game_manager.player.pos_y / this.map_manager.tSize.x)};
        //console.log(ghost_pos)
        if (ghost.state !== GhostStates.afraid){
            if (Math.sqrt((player_pos.x - ghost_pos.x)**2 + (player_pos.y - ghost_pos.y)**2) <= 8){
                //console.log(ghost_pos, player_pos, Math.sqrt((player_pos.x - ghost_pos.x)**2 + (player_pos.y - ghost_pos.y)**2) <= 3)
                ghost.state = GhostStates.chase;
            } else {
                ghost.state = GhostStates.search;
            }
        }
        //console.log(ghost.state)
        switch (ghost.state){
            case GhostStates.search:
                this.search(ghost);
                break;
            case GhostStates.chase:
                this.chase(ghost, ghost_pos, player_pos);
                break;
            case GhostStates.afraid:
                this.search(ghost);
                break;
        }
    }
}