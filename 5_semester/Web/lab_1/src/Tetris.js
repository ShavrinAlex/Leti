import { PlayField } from "./PlayField.js";
import { Tetromino } from "./Tetromino.js";
import { PLAYFIELD_ROWS, PLAYFIELD_COLUMNS, TETROMINO_NAMES } from "./Utils.js";

export class Tetris {
    constructor() {
        this.playField = new PlayField(PLAYFIELD_ROWS, PLAYFIELD_COLUMNS);
        this.current_tetromino = this.generateTetromino();
        this.next_tetromino = this.generateTetromino();
    }

    generateTetromino() {
        const random_tetromino_name_index = Math.floor(Math.random() * TETROMINO_NAMES.length);
        return new Tetromino(TETROMINO_NAMES[random_tetromino_name_index]);
    }
}
