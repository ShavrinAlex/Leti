import { PLAYFIELD_COLUMNS, PLAYFIELD_ROWS, BLOCK_SIZE } from "./Utils.js";

export class Canvas {
    constructor () {
        this.canvas = document.getElementById('board');
        this.context = canvas.getContext('2d');

        // Устанавливаем размеры холста
        this.context.canvas.width = PLAYFIELD_COLUMNS * BLOCK_SIZE;
        this.context.height = PLAYFIELD_ROWS * BLOCK_SIZE;

        // Устанавливаем масштаб
        this.context.scale(BLOCK_SIZE, BLOCK_SIZE);
    }

    
}
