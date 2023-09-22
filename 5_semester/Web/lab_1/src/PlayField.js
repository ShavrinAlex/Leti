export class PlayField {
    constructor (count_rows, count_columns) {
        this.rows = count_rows;
        this.columns = count_columns;
        this.play_field = generateEmptyPlayField();
    }

    generateEmptyPlayField() {
        return new Array(this.rows).fill(0)
        .map(() => new Array(this.columns).fill(0));
    }
}
