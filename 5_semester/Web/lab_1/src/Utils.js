export const PLAYFIELD_ROWS = 20
export const PLAYFIELD_COLUMNS = 10

export const NT_WINDOW_ROWS = 4
export const NT_WINDOW_COLUMNS= 4

export const BLOCK_SIZE = 35

export const MIN_LEVEL = 1
export const MAX_LEVEL = 20
export const LEVEL_TIME_INCREASE = 50

export const MOVEMENT_ACTIVITIES = {Rotate: 0, Down: 1, Left: 2, Right: 3, Drop: 4}

export const TETROMINO_NAMES = ['I', 'J', 'L', 'O', 'S', 'Z', 'T']
export const TETROMINO_COLORS = {
    I: ["rgba(107, 225, 236, 1)", "rgba(107, 225, 236, 0.3)"], 
    J: ["rgba(94, 176, 243, 1)", "rgba(94, 176, 243, 0.3)"], 
    L: ["rgba(242, 150, 91, 1)", "rgba(242, 150, 91, 0.3)"], 
    O: ["rgba(247, 229, 98, 1)", "rgba(247, 229, 98, 0.3)"], 
    S: ["rgba(123, 225, 123, 1)", "rgba(123, 225, 123, 0.3)"], 
    Z: ["rgba(222, 92, 107, 1)", "rgba(222, 92, 107, 0.3)"], 
    T: ["rgba(178, 118, 243, 1)", "rgba(178, 118, 243, 0.3)"]
}
export const TETROMINO_SHAPES = {
    'I': [
        [0, 0, 0, 0],
        [1, 1, 1, 1],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ],
    'J': [
        [1, 0, 0],
        [1, 1, 1],
        [0, 0, 0]
    ],
    'L': [
        [0, 0, 1],
        [1, 1, 1],
        [0, 0, 0]
    ],
    'O': [
        [1, 1],
        [1, 1]
    ],
    'S': [
        [0, 1, 1],
        [1, 1, 0],
        [0, 0, 0]
    ],
    'Z': [
        [1, 1, 0],
        [0, 1, 1],
        [0, 0, 0]
    ],
    'S': [
        [0, 1, 0],
        [1, 1, 1],
        [0, 0, 0]
    ]
}