export class PlayField {
    constructor (count_rows, count_columns) {
        this.rows = count_rows
        this.columns = count_columns
        this.play_field = this.generateEmptyPlayField()
         // наглядное представление матрицы игрового поля
        //console.table(this.play_field)
    }

    generateEmptyPlayField() 
    {
        return new Array(this.rows).fill(0)
        .map(() => new Array(this.columns).fill(0))
    }

    ifFreeCell(x, y)
    {
        return this.play_field[y][x] == false
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
}
