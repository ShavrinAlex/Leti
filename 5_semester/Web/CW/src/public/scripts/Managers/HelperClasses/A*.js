import { CellStates } from "../../enums";

const INFINITY = 1000000

class Node{
    constructor (x, y, is_wall, finish){
        this.x = x;
        this.y = y;
        this.is_wall = is_wall;
        this.g = INFINITY;
        this.h = this.heuristic(finish);
        this.f = INFINITY;
        this.parent = null;
    }

    heuristic (finish) {
        // This is the Manhattan distance
        let d1 = Math.abs (finish.x - this.x);
        let d2 = Math.abs (finish.y - this.y);
        return d1 + d2;
    }
}   


export function AStar(map, start, end){
    let graph = create_graph(map, end);
    end_node = graph(end.x, end.y);
    start_node = graph(start.x, start.y);
    start_node.g = 0;
    start_node.f = start_node.g + start_node.h;
    let Q = [];
    let U = [];
    Q.push(start);

    while (Q.length){
        let best_node_index = get_best_node_index(Q);
        let current_node = Q[best_node_index];
        if (JSON.stringify(current_node) === JSON.stringify(end_node)){
            console.log('end');

            return get_path(current_node);
        }

        Q.splice(best_node_index, 1);
        U.push(current_node);

        let neighbors = get_neighbors(graph, current_node);

        for (let i = 0; i < neighbors.length; i++){
            let current_neighbor = neighbors[i];
            if (current_neighbor.is_wall){
                continue;
            }

            let g_score = current_node.g + 1; // 1 is the distance from a node to it's neighbor

            if (is_in_array(U, current_neighbor) && g_score >= current_neighbor.g){
                continue;
            }

            if (!is_in_array(U, current_neighbor) || g_score < current_neighbor.g){
                current_neighbor.parent = current_node;
                current_neighbor.g = g_score;
                current_neighbor.f = current_neighbor.g + current_neighbor.h;

                if (!is_in_array(Q, current_neighbor)){
                    Q.push(current_neighbor);
                }
            }
        }
    }
    console.log('path not found');
    return false;
}

function create_graph(map, end){
    let graph = [];
    for (let y = 0; y < map.length; y++){
        let row = [];
        for (let x = 0; x < map[y].length; x++){
            row.push(new Node(x, y, (map[y][x] !== CellStates.free), end));
        }
        graph.push(row);
    }
}

function get_best_node_index(Q){
    let min_f = 10000000;
    let best_node_index;
    for (let i = 0; i < Q.length; i++){
        if (Q[i].f < min_f){
            min_f = Q[i].f;
            best_node_index = i;
        }
    }
    return best_node_index;
}

function get_neighbors(grid, node) {
    let ret = [];
    let x = node.x;
    let y = node.y;
 
    if(grid[y-1] && grid[y-1][x]) {
      ret.push(grid[y-1][x]);
    }
    if(grid[y+1] && grid[y+1][x]) {
      ret.push(grid[y+1][x]);
    }
    if(grid[y][x-1] && grid[y][x-1]) {
      ret.push(grid[y][x-1]);
    }
    if(grid[y][x+1] && grid[y][x+1]) {
      ret.push(grid[y][x+1]);
    }
    return ret;
}

function is_in_array(array, node){
    let is_in_array = false;
    array.forEach(element => {
        if (JSON.stringify(element) === JSON.stringify(node)){
            is_in_array = true;
        }

    });
    return is_in_array;
}

function get_path(finish){
    let current_node = finish;
    var path = [];
    while(current_node.parent) {
        path.push(current_node);
        current_node = current_node.parent;
    }
    return path.reverse();
}
