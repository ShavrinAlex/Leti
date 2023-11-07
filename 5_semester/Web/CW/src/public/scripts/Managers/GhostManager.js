import { GhostStates } from "../enums.js";
import { Ghost } from "../Entities/Ghost.js";


export class GhostManager {
    map_manager = null;
    game_manager = null;
    map_sectors = [];

    search(ghost){
        
    }

    chase(ghost){

    }

    afraid(ghost){

    }

    calculate_sectors(){
        let count_areas = 0;
        for (let i = 0; i < this.game_manager.objects.length; i++){
            if (this.game_manager.objects[i] instanceof Ghost){
                count_areas++;
            }
        }

        
    }

    update(ghost){
        if (!this.map_areas || !this.map_manager || !this.game_manager){
            return;
        }

        if (!this.map_areas){
            this.calculate_sectors();
        }

        switch (ghost.state){
            case GhostStates.search:
                this.search();
                break;
            case GhostStates.chase:
                this.chase(ghost);
                break;
            case GhostStates.afraid:
                this.afraid(ghost);
                break;
        }
    }

    aStar(){

    }
}