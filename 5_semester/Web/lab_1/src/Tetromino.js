import { TETROMINO_NAMES, TETROMINO_COLORS, TETROMINO_SHAPES, PLAYFIELD_COLUMNS } from "./Utils.js";

export class Tetromino {
    constructor (tetromino_name) {
        this.name = tetromino_name in TETROMINO_NAMES ? tetromino_name : TETROMINO_NAMES[1];
        this.color = TETROMINO_COLORS[this.name];
        this.shape = TETROMINO_SHAPES[this.name];

        this.coordinates = {x: Math.floor(PLAYFIELD_COLUMNS / 2) - Math.floor(this.shape.length / 2), y: 0};
    }

    rotate () {
        const N = this.shape.length;
        const rotated_matrix = [];
        for (let i = 0; i < N; i++) {
            rotated_matrix[i] = [];
            for (let j = 0; j < N; j++) {
            rotated_matrix[i][j] = matrix[N - j - 1][i];
            }
        }
        this.shape = rotated_matrix;
    }
}
