import {Tetris} from "./Tetris.js"
import { Canvas } from "./Canvas.js"
import { MOVEMENT_ACTIVITIES } from "./Utils.js"


let play_button_element = document.getElementById("play_button")
play_button_element.addEventListener("click", play)

let username_element = document.getElementById("username")
username_element.innerText = `${localStorage["tetris.username"]}`


const canvas = new Canvas()

function play() {  
    /* This function launches the game */

    /* Disable the button */
    play_button_element.setAttribute("disabled", "disable")
    play_button_element.blur()

    const tetris = new Tetris(canvas)

    document.addEventListener("keydown", onKeydown)

    function onKeydown(event)
    {
        /* This function handles key presses */
        switch (event.key){
            case 'ArrowDown':
            case 's':
                tetris.moveTetromino(MOVEMENT_ACTIVITIES.Down)
                break
            case 'ArrowLeft':
            case 'a':
                tetris.moveTetromino(MOVEMENT_ACTIVITIES.Left)
                break
            case 'ArrowRight':
            case 'd':
                tetris.moveTetromino(MOVEMENT_ACTIVITIES.Right)
                break
            case 'ArrowUp':
            case 'w':
                tetris.moveTetromino(MOVEMENT_ACTIVITIES.Rotate)
                break
            case ' ':
                tetris.moveTetromino(MOVEMENT_ACTIVITIES.Drop)
                break
            default:
                break
        }
    }
}

