let username_element = document.getElementById("username_input")
let log_in_button_element = document.getElementById("log_in_button")
let form_element = document.getElementById("authorization_form")

username_element.addEventListener("input", checkUsernameInput)
form_element.addEventListener("submit", saveUsername)

function checkUsernameInput(event)
{
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
    localStorage["tetris.username"] = username_element.value
    if (localStorage["tetris.score_table"] === undefined)
    {
        localStorage["tetris.score_table"] = JSON.stringify([])
    }
}