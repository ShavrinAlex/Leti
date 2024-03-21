let username_element = document.getElementById("username_input")
let log_in_button_element = document.getElementById("log_in_button")
let form_element = document.getElementById("authorization_form")

username_element.addEventListener("input", checkUsernameInput)
form_element.addEventListener("submit", saveUsername)

function checkUsernameInput(event)
{
    /* This function activates and disables the button depending on the user's name input */
    
    if (username_element.value.length === 0)
    {
        log_in_button_element.setAttribute("disabled", "disable")
    } else
    {
        log_in_button_element.removeAttribute("disabled")
    }
}

function saveUsername(event)
{
    /* 
    This function saves the username to local memory 
    and creates an entry for the high score table as needed 
    */

    localStorage["tetris.username"] = username_element.value
    if (localStorage["tetris.score_table"] === undefined)
    {
        localStorage["tetris.score_table"] = JSON.stringify([])
    }
}