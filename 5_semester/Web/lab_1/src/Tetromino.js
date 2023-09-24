import { TETROMINO_SHAPES, TETROMINO_NAMES, PLAYFIELD_COLUMNS} from "./Utils.js"

export class Tetromino {
    constructor (tetromino_name, is_clone = false) {
        this.name = tetromino_name !== undefined ? tetromino_name: TETROMINO_NAMES[0]
        this.is_clone = is_clone
        this.shape = TETROMINO_SHAPES[this.name]
        this.coordinates = {x: Math.floor(PLAYFIELD_COLUMNS / 2) - 2, y: 0}
    }

    rotate () {
        const N = this.shape.length
        const rotated_matrix = []
        for (let i = 0; i < N; i++) {
            rotated_matrix[i] = []
            for (let j = 0; j < N; j++) {
                rotated_matrix[i][j] = this.shape[N - j - 1][i]
            }
        }
        this.shape = rotated_matrix
    }
}
