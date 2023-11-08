let username_element = document.getElementById("username_input")
let level_1_button_element = document.getElementById("level_1")
let level_2_button_element = document.getElementById("level_2")


username_element.addEventListener("input", checkUsernameInput)
level_1_button_element.addEventListener("click", saveUsername)
level_2_button_element.addEventListener("click", saveUsername)

function checkUsernameInput(event)
{
    /* Эта функция активирует и отключает кнопку в зависимости от ввода имени пользователя. */
    
    if (username_element.value.length === 0){
        level_1_button_element.setAttribute("disabled", "disable")
        level_2_button_element.setAttribute("disabled", "disable")
    } else {
        level_1_button_element.removeAttribute("disabled")
        level_2_button_element.removeAttribute("disabled")
    }
}

function saveUsername(event)
{
    /* 
    Эта функция сохраняет имя пользователя и выбранный уровень в локальной памяти
    и при необходимости создает запись для таблицы рекордов
    */

    localStorage["pac_man.username"] = username_element.value
    localStorage["pac_man.level"] = this.value
    if (localStorage["pac_man.score_table"] === undefined){
        localStorage["pac_man.score_table"] = JSON.stringify([])
    }
    window.location = './game';
}