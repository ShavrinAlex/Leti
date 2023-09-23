import { PLAYFIELD_COLUMNS, PLAYFIELD_ROWS, BLOCK_SIZE , TETROMINO_COLORS} from "./Utils.js"

export class Canvas {
    constructor () {
        this.canvas = document.getElementById('play_field')
        this.context = this.canvas.getContext('2d')

        // Устанавливаем размеры холста и приближение
        this.canvas.width = PLAYFIELD_COLUMNS * BLOCK_SIZE
        this.canvas.height = PLAYFIELD_ROWS * BLOCK_SIZE
       
        this.drawPlayFieldGrid()
        this.context.scale(BLOCK_SIZE, BLOCK_SIZE)

        /* For drawing tetromino */
        this.left_up_gap = 1 / BLOCK_SIZE
        this.right_down_gap = 2 * this.left_up_gap 
    }

    drawPlayFieldGrid()
    {
        this.context.lineWidth = 1
        this.context.strokeStyle = "rgba(0, 0, 0, 0.3)"
        
        /* Drawing rows */
        for (let y = 0; y <= this.canvas.height; y += BLOCK_SIZE)
        {
            this.context.moveTo(0, y)
            this.context.lineTo(this.canvas.width, y)
        }

        /* Drawing columns */
        for (let x = 0; x <= this.canvas.width; x += BLOCK_SIZE)
        {
            this.context.moveTo(x, 0)
            this.context.lineTo(x, this.canvas.height)
        }   
        this.context.stroke()
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
}
