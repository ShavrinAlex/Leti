export class PlayField {
    constructor (count_rows, count_columns) {
        this.rows = count_rows
        this.columns = count_columns
        this.play_field = this.generateEmptyPlayField()
         // наглядное представление матрицы игрового поля
    }

    generateEmptyPlayField() 
    {
        return new Array(this.rows).fill(0)
        .map(() => new Array(this.columns).fill(0))
    }

    isFreeCell(x, y)
    {
        return this.play_field[y][x] === 0
    }

    isBelongingFieldCoordinates(x, y)
    {
        let isBelonging = true
        if (y < 0 || x < 0 || y >= this.rows || x >= this.columns)
        {
            isBelonging = false
        }
        return isBelonging
    }

    placeTetromino(tetromino)
    {
        if (tetromino !== undefined && tetromino.shape !== undefined)
        {
            let start_x = tetromino.coordinates.x
            let start_y = tetromino.coordinates.y

            tetromino.shape.forEach((row, y) => 
            {
                row.forEach((value, x) => 
                {
                if (value > 0){
                    let current_x = start_x + x
                    let current_y = start_y + y
                    
                    this.play_field[current_y][current_x] = 1
                }
                })
            })
        }
    }

    findFilledRows()
    {
        const filled_rows = new Array()
        for (let row = 0; row < this.rows; row++)
        {
            if (this.play_field[row].every(cell => Boolean(cell)))
            {
                filled_rows.push(row)
            }
        }
        return filled_rows
    }

    removeFilledRows(filled_rows)
    {
        if (filled_rows !== undefined)
        {
            filled_rows.forEach(row => {
                this.dropRowsAbove(row)
            })
        }
    }

    dropRowsAbove(row_to_delete){
        for (let row = row_to_delete; row > 0; row--)
        {
            this.play_field[row] = this.play_field[row - 1]
        }
        this.play_field[0] = new Array(this.columns).fill(0)
    }

}
