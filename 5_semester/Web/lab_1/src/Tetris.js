import { PlayField } from "./PlayField.js"
import { Tetromino } from "./Tetromino.js"
import { PLAYFIELD_ROWS, PLAYFIELD_COLUMNS, TETROMINO_NAMES, MOVEMENT_ACTIVITIES, MIN_LEVEL, LEVEL_TIME_INCREASE} from "./Utils.js"


export class Tetris {
    constructor(canvas) {
        this.current_level = MIN_LEVEL
        this.score = 0
        this.lines = 0

        this.play_field = new PlayField(PLAYFIELD_ROWS, PLAYFIELD_COLUMNS)

        this.current_tetromino = this.generateTetromino()
        this.shadow_current_tetromino = this.generateShadowCurrentTetromino()
        this.calculateShadowTetraminoPosition()
        this.next_tetromino = this.generateTetromino()

        this.canvas = canvas
        
        this.canvas.drawTetromino(this.current_tetromino)
        this.canvas.drawTetromino(this.shadow_current_tetromino)

        this.timeout_id = null
        this.restartFallTetrominoTimeout()

        this.next_tetromino_cells = document.querySelectorAll('.next_tetromino_grid>div')
        this.drawNextTetromino()
    }

    restartFallTetrominoTimeout(timeout = 1000 - LEVEL_TIME_INCREASE * this.current_level)
    {
        clearTimeout(this.timeout_id)
        this.timeout_id = setTimeout(() => this.moveTetromino(MOVEMENT_ACTIVITIES.Down), timeout)
    }
    
    generateTetromino() 
    {
        let random_tetromino_name_index = Math.floor(Math.random() * TETROMINO_NAMES.length)
        return new Tetromino(TETROMINO_NAMES[random_tetromino_name_index])
    }

    generateShadowCurrentTetromino()
    {
        return new Tetromino(this.current_tetromino.name, true)
    }

    isOccupiedCurrentTetrominoPosition()
    {
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
        this.canvas.drawTetromino(this.current_tetromino)
        this.calculateShadowTetraminoPosition()
        this.canvas.drawTetromino(this.shadow_current_tetromino)
        /* Check update need*/
        if ((movement_activity === MOVEMENT_ACTIVITIES.Down || movement_activity === MOVEMENT_ACTIVITIES.Drop) && (!isAbilityMove))
        {
            this.updatePlayField()
        }
    }

    calculateShadowTetraminoPosition()
    {
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
        this.play_field.placeTetromino(this.current_tetromino)
        this.processFilledRows()
        this.current_tetromino = this.next_tetromino
        if (this.isOccupiedCurrentTetrominoPosition())
        {
            this.gameOver()
        } else {
            this.shadow_current_tetromino = this.generateShadowCurrentTetromino()
            this.calculateShadowTetraminoPosition()
            this.next_tetromino = this.generateTetromino()
            this.canvas.drawTetromino(this.current_tetromino)
            this.canvas.drawTetromino(this.shadow_current_tetromino)
            this.drawNextTetromino()
        }
        
    }

    gameOver(){
        window.location = "./game_over.html"
    }

    drawNextTetromino() 
    {
        if (this.next_tetromino.shape !== undefined)
        {
            this.next_tetromino_cells.forEach(cell => cell.removeAttribute("class"))

            const size = this.next_tetromino.shape.length
            for (let y = 0; y < size; y++)
            {
                for (let x = 0; x < size; x++) 
                {
                    if (!this.next_tetromino.shape[y][x]) continue
                    const cell_index = y * 4 + x
                    this.next_tetromino_cells[cell_index].classList.add(this.next_tetromino.name)
                }
            }
        }
    }

    processFilledRows()
    {
        const filled_lines = this.play_field.findFilledRows()
        this.play_field.removeFilledRows(filled_lines)
        this.canvas.removeFilledRows(filled_lines)
    }
}
