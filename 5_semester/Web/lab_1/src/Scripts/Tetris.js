import { PlayField } from "./PlayField.js"
import { Tetromino } from "./Tetromino.js"
import { PLAYFIELD_ROWS, PLAYFIELD_COLUMNS, TETROMINO_NAMES, MOVEMENT_ACTIVITIES, LEVEL_TIME_INCREASE, MAX_LEVEL} from "./Utils.js"


export class Tetris {
    /* This is the Tetris class that controls the entire game */

    constructor(canvas) {
        this.level = 0
        this.score = 0
        this.lines = 0

        this.play_field = new PlayField(PLAYFIELD_ROWS, PLAYFIELD_COLUMNS)

        this.canvas = canvas
        this.current_tetromino = this.generateTetromino()
        this.shadow_current_tetromino = this.generateShadowCurrentTetromino()
        this.calculateShadowTetraminoPosition()
        this.next_tetromino = this.generateTetromino()

        this.canvas.drawTetromino(this.current_tetromino)
        this.canvas.drawTetromino(this.shadow_current_tetromino)
        this.canvas.drawNextTetromino(this.next_tetromino)

        this.timeout_id = null
        this.restartFallTetrominoTimeout()
    }

    restartFallTetrominoTimeout(timeout = (MAX_LEVEL * LEVEL_TIME_INCREASE) - (LEVEL_TIME_INCREASE * this.level))
    {
        /* This method moves the figure according to timeout */

        clearTimeout(this.timeout_id)
        this.timeout_id = setTimeout(() => this.moveTetromino(MOVEMENT_ACTIVITIES.Down), timeout)
    }
    
    generateTetromino() 
    {
        /* This method creates tetrominoes */

        let random_tetromino_name_index = Math.floor(Math.random() * TETROMINO_NAMES.length)
        return new Tetromino(TETROMINO_NAMES[random_tetromino_name_index])
    }

    generateShadowCurrentTetromino()
    {
        /* This method creates shadow current tetromino*/

        return new Tetromino(this.current_tetromino.name, true)
    }

    isOccupiedCurrentTetrominoPosition()
    {
        /* This method checks whether the position of the current tetrominoe is occupied */

        let isOccupied = false
        if (this.current_tetromino !== undefined && this.current_tetromino.shape !== undefined)
        {
            let start_x = this.current_tetromino.coordinates.x
            let start_y = this.current_tetromino.coordinates.y
            const size = this.current_tetromino.shape.length

            labelCancelLoops:
            for (let y = 0; y < size; y++)
            {
                for (let x = 0; x < size; x++)
                {
                    let current_x = start_x + x
                    let current_y = start_y + y
                    if (this.current_tetromino.shape[y][x] > 0 && !this.play_field.isFreeCell(current_x, current_y))
                    {
                        isOccupied = true
                        break labelCancelLoops
                    }
                }  
            }
            return isOccupied
        }
        return isOccupied
    }

    isBelongingFieldCurrentTetrominoPosition()
    {
        /* This method checks whether the position of the current tetromino belongs to the field */

        let isBelonging = true
        let start_x = this.current_tetromino.coordinates.x
        let start_y = this.current_tetromino.coordinates.y
        const size = this.current_tetromino.shape.length
    
        labelCancelLoops:
        for (let y = 0; y < size; y++)
        {
            for (let x = 0; x < size; x++)
            {
                let current_x = start_x + x
                let current_y = start_y + y
                if (this.current_tetromino.shape[y][x] > 0 && !this.play_field.isBelongingFieldCoordinates(current_x, current_y))
                {
                    isBelonging = false
                    break labelCancelLoops
                }  
            }
        }
        return isBelonging
    }


    isAbilityCurrentTetrominoPosition()
    {
        /* This method checks the possibility of placing tetrominoes with the current position */

        let isAbility = true
        if (this.current_tetromino !== undefined && this.current_tetromino.shape !== undefined)
        {
            if (this.isBelongingFieldCurrentTetrominoPosition() && !this.isOccupiedCurrentTetrominoPosition())
            {
                return isAbility
            }
        }
        return false
    }

    moveTetromino(movement_activity)
    {
        /* This method implements the movement of tetrominoes */
        this.canvas.clearTetromino(this.current_tetromino)
        this.canvas.clearTetromino(this.shadow_current_tetromino)

        let old_coordinates = {x: this.current_tetromino.coordinates.x, y: this.current_tetromino.coordinates.y}
        let old_shape = this.current_tetromino.shape

        switch (movement_activity)
        {
            case MOVEMENT_ACTIVITIES.Down:
                this.current_tetromino.coordinates.y += 1
                this.restartFallTetrominoTimeout()
                break
            case MOVEMENT_ACTIVITIES.Left:
                this.current_tetromino.coordinates.x -= 1
                break
            case MOVEMENT_ACTIVITIES.Right:
                this.current_tetromino.coordinates.x += 1
                break
            case MOVEMENT_ACTIVITIES.Rotate:
                this.current_tetromino.rotate()
                this.shadow_current_tetromino.rotate()
                break
            case MOVEMENT_ACTIVITIES.Drop:
                this.current_tetromino.coordinates = this.shadow_current_tetromino.coordinates
                this.restartFallTetrominoTimeout()
                break
        }

        /* Check changes ability */
        let isAbilityMove = this.isAbilityCurrentTetrominoPosition()
        if (!isAbilityMove)
        {
            this.current_tetromino.coordinates = old_coordinates
            this.current_tetromino.shape = old_shape
            this.shadow_current_tetromino.shape = old_shape
        }
        /* Draw tetrominoes */
        this.canvas.drawTetromino(this.current_tetromino)
        this.calculateShadowTetraminoPosition()
        this.canvas.drawTetromino(this.shadow_current_tetromino)

        /* Check update needed*/
        if ((movement_activity === MOVEMENT_ACTIVITIES.Down || movement_activity === MOVEMENT_ACTIVITIES.Drop) && (!isAbilityMove))
        {
            this.updatePlayField()
        }
    }

    calculateShadowTetraminoPosition()
    {
        /* This method calculates the position for the shadow tetromino */

        let current_tetromino_coordinates = {x: this.current_tetromino.coordinates.x, y: this.current_tetromino.coordinates.y}
        while (this.isAbilityCurrentTetrominoPosition())
        {
            this.current_tetromino.coordinates.y += 1
        }
        this.current_tetromino.coordinates.y -= 1
        this.shadow_current_tetromino.coordinates = this.current_tetromino.coordinates
        this.current_tetromino.coordinates = current_tetromino_coordinates
    }


    updatePlayField()
    {
        /* This method places a tetromino on the field and moves on to the next tetromino */

        this.play_field.placeTetromino(this.current_tetromino)
        this.processFilledRows()
        this.current_tetromino = this.next_tetromino

        /* Game over check */
        if (this.isOccupiedCurrentTetrominoPosition())
        {
            this.gameOver()
        } else {
            this.shadow_current_tetromino = this.generateShadowCurrentTetromino()
            this.calculateShadowTetraminoPosition()
            this.next_tetromino = this.generateTetromino()
            this.canvas.drawTetromino(this.current_tetromino)
            this.canvas.drawTetromino(this.shadow_current_tetromino)
            this.canvas.drawNextTetromino(this.next_tetromino)
        }
    }

    gameOver(){
        /* This method saves data at the end of the game to local memory and moves to a new page */

        let score_table = JSON.parse(localStorage["tetris.score_table"])
        let isExistsUsername = false

        /* Updating a user's result or creating a new entry */
        for (let i = 0; i < score_table.length; i++)
        {
            if (score_table[i].name == localStorage["tetris.username"])
            {
                score_table[i].score = this.score
                isExistsUsername = true
                break
            }
        }
        if (!isExistsUsername)
        {
            score_table.push({
                name: localStorage["tetris.username"],
                score: this.score
            })
        }
        
        localStorage["tetris.score_table"] = JSON.stringify(score_table)
        window.location = "../game_over.html"
    }

    processFilledRows()
    {
        /* This method removes filled lines */

        const filled_lines = this.play_field.findFilledRows()
        this.play_field.removeFilledRows(filled_lines)
        this.canvas.removeFilledRows(filled_lines)
        this.updateData(filled_lines.length)
    }

    calculateScore(count_removed_rows)
    {
        /* This method calculates the score */

        if (count_removed_rows == 1)
        {
            return 100
        }
        return 2 * this.calculateScore(count_removed_rows - 1) + 100
    }

    updateData(count_removed_rows)
    {
        /* This method updates the game data */

        if (count_removed_rows > 0){
            this.score += this.calculateScore(count_removed_rows)
            this.lines += count_removed_rows
            this.level = Math.min(MAX_LEVEL, Math.floor(this.score / 100))
            this.canvas.updateData(this.level, this.score, this.lines)
        }
    }
}
