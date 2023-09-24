import { PLAYFIELD_COLUMNS, PLAYFIELD_ROWS, BLOCK_SIZE , TETROMINO_COLORS} from "./Utils.js"

export class Canvas {
    constructor () {
        this.canvas = document.getElementById('play_field')
        this.context = this.canvas.getContext('2d')

        // Устанавливаем размеры холста и приближение
        this.canvas.width = PLAYFIELD_COLUMNS * BLOCK_SIZE
        this.canvas.height = PLAYFIELD_ROWS * BLOCK_SIZE
       
        this.context.scale(BLOCK_SIZE, BLOCK_SIZE)
        this.drawPlayFieldGrid(this.canvas.width, this.canvas.height)

        /* For drawing tetromino */
        this.left_up_gap = 1 / BLOCK_SIZE
        this.right_down_gap = 2 * this.left_up_gap 

        this.level = document.getElementById("level")
        this.score = document.getElementById("score")
        this.lines = document.getElementById("lines")
    }

    drawPlayFieldGrid(width, height)
    {
        this.context.scale(1 / BLOCK_SIZE, 1 / BLOCK_SIZE)
        this.context.lineWidth = 1
        this.context.strokeStyle = "rgba(0, 0, 0, 0.15)"
        
        for (let y = 0; y < height; y += BLOCK_SIZE)
        {
            for (let x = 0; x < width; x += BLOCK_SIZE)
            {
                this.context.strokeRect(x, y, BLOCK_SIZE, BLOCK_SIZE)
            }   
        }

        this.context.scale(BLOCK_SIZE, BLOCK_SIZE)
    }

    removeFilledRows(filled_rows)
    {
        if (filled_rows.length != 0)
        {
            filled_rows.forEach(row => {
                this.dropRowsAbove(row)
            })
            this.drawPlayFieldGrid(this.canvas.width, filled_rows.length * BLOCK_SIZE)
        }
    }

    dropRowsAbove(row_to_delete)
    {
        this.context.scale(1/BLOCK_SIZE, 1/BLOCK_SIZE)
        for (let row = row_to_delete; row > 0; row--)
        {
            let source_x = 0, source_y = (row - 1) * BLOCK_SIZE
            let source_width = this.canvas.width, source_height = 1 * BLOCK_SIZE
            let destination_x = 0, destination_y = row * BLOCK_SIZE
            let destination_width = this.canvas.width, destination_height = 1 * BLOCK_SIZE
            
            this.context.clearRect(destination_x, destination_y, destination_width, destination_height)
            this.context.drawImage(
                this.canvas,         
                source_x,
                source_y,
                source_width,
                source_height,
                destination_x,  
                destination_y ,
                destination_width,    
                destination_height  
            )
        }
        this.context.clearRect(0, 0, this.canvas.width, BLOCK_SIZE)
        this.context.scale(BLOCK_SIZE, BLOCK_SIZE)
    }

    drawTetromino(tetromino)
    {
        if (tetromino !== undefined && tetromino.shape !== undefined)
        {
            this.context.fillStyle = TETROMINO_COLORS[tetromino.name][tetromino.is_clone ? 1 : 0]
            tetromino.shape.forEach((row, y) => 
            {
                row.forEach((value, x) => 
                {
                if (value > 0) 
                {
                    this.context.fillRect(tetromino.coordinates.x + x + this.left_up_gap, 
                                        tetromino.coordinates.y + y + this.left_up_gap, 
                                        1 - this.right_down_gap, 
                                        1 - this.right_down_gap)
                }
                })
            })
        }
    }

    clearTetromino(tetromino)
    {
        if (tetromino !== undefined && tetromino.shape !== undefined)
        {
            tetromino.shape.forEach((row, y) => 
            {
                row.forEach((value, x) => 
                {
                  if (value > 0) 
                  {
                    this.context.clearRect(tetromino.coordinates.x + x + this.left_up_gap, 
                                          tetromino.coordinates.y + y + this.left_up_gap, 
                                          1 - this.right_down_gap, 
                                          1 - this.right_down_gap)
                  }
                })
            })
        }
    }

    updateData(level, score, lines)
    {
        this.level.innerText = `${level}`
        this.score.innerText = `${score}`
        this.lines.innerText = `${lines}`
    }
}
