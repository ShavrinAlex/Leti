import { States, Directions } from "../enums.js";


export class PhysicManager {
    map_manager = null;
    game_manager = null;

    update(obj) {
        if(obj.state ===  States.stay){
            return "stop"; 
        }
        //console.log("old ", obj.pos_x, pos_y)
        if (obj.direction !== obj.request_direction){
            if (obj.pos_x % this.map_manager.tSize.x == 0 && obj.pos_y % this.map_manager.tSize.y == 0){
                if (!this.is_wall_collision(obj.pos_x, obj.pos_y, {'x': obj.speed, 'y': obj.speed}, obj.request_direction)){
                    obj.direction = obj.request_direction;
                }
            }
        }

        if (this.is_wall_collision(obj.pos_x, obj.pos_y, {'x': obj.speed, 'y': obj.speed}, obj.direction)){
            return 'break';
        }
        let next_position = this.getNextPosition(obj.pos_x, obj.pos_y, obj.speed, obj.direction);
        let object = this.objectAtXY(obj, next_position.x, next_position.y); 
        if(object !== null && obj.onTouchObjet){
            obj.onTouchObjet(object);
        }
        obj.pos_x = next_position.x;
        obj.pos_y = next_position.y;
    return "move";
    }

    getNextPosition(x, y, offset, direction){
        let newX = x;
        let newY = y;
       
        switch(direction){
            case Directions.up:
                newY -= offset;
                break;
            case Directions.down:
                newY += offset;
                break;
            case Directions.left:
                newX -= offset;
                break;
            case Directions.right:
                newX += offset;
                break;
        }
        if (newX > this.map_manager.mapSize.x - this.map_manager.tSize.x){
            newX %= this.map_manager.mapSize.x - this.map_manager.tSize.x;
        } else if (newX < 0) {
            newX = this.map_manager.mapSize.x - this.map_manager.tSize.x;
        }
        newY %= this.map_manager.mapSize.y;
        return {'x': newX,'y': newY};
    }

    is_wall_collision(x, y, offset, direction){
        let tile_position = {'x': x, 'y': y};
        let round_func;
        switch(direction){
            case Directions.up:
                tile_position.y -= offset.y;
                round_func = Math.floor;
                break;
            case Directions.down:
                tile_position.y += offset.y;
                round_func = Math.ceil;
                break;
            case Directions.left:
                tile_position.x -= offset.x;
                round_func = Math.floor;
                break;
            case Directions.right:
                tile_position.x += offset.x;
                round_func = Math.ceil;
                break;
        } 
        tile_position.x %= this.map_manager.mapSize.x;

        if (tile_position.x > this.map_manager.mapSize.x - this.map_manager.tSize.x){
            tile_position.x %= this.map_manager.mapSize.x - this.map_manager.tSize.x;
        } else if (tile_position.x < 0) {
            tile_position.x = this.map_manager.mapSize.x - this.map_manager.tSize.x;
        }
        //console.log(tile_position)
        //console.log(this.map_manager.getTilesetIdx(tile_position.x, tile_position.y, round_func));
        return 0 !== this.map_manager.getTilesetIdx(tile_position.x, tile_position.y, round_func);
    }
    /*
    getNextTile(obj, next_position){
        tile_position = {'x': next_position.x, 'y': next_position.y};
        console.log(tile_position)
        switch(obj.direction){
            case Directions.up:
                tile_position.y -= 0;
                break;
            case Directions.down:
                tile_position.y += obj.size_y;
                break;
            case Directions.left:
                tile_position.x -= 0;
                break;
            case Directions.right:
                tile_position.x += obj.size_x;
                break;
        }
        tile_position.x %= this.map_manager.mapSize.x;
        tile_position.y %= this.map_manager.mapSize.y;
        let tile = his.map_manager.getTilesetIdx(tile_position.x, tile_position.y);
       //console.log(tile_position, tile)
    }
    */
    objectAtXY(obj, x, y) { 
        for(let i = 0; i < this.game_manager.objects.length; i++) {
            let e = this.game_manager.objects[i]; 
            if(e.name !== obj.name) {
                if (x + obj.size_x - 1 < e.pos_x || y + obj.size_y - 1 < e.pos_y ||
                    x > e.pos_x + e.size_x - 1 || y > e.pos_y + e.size_y - 1) {
                    continue;
                }
                return e;
            }
        }
        return null;
    }
}