export async function go_to_book_card(button){
    let book_id = button.id
    try {
        let response = await fetch(`/library/${book_id}`, {method: "GET"})
        window.location = `/library/${book_id}`
    } catch (error){
        console.error("Ошибка:", error)
    }
}

export function book_dialog(){
    const book_dialog = document.getElementById("add_book_dialog")
    book_dialog.show()
}

export async function add_book(){
    const book_dialog = document.getElementById("add_book_dialog")
    book_dialog.close()

    let name = document.getElementById("add_name").value
    let author = document.getElementById("add_author").value
    let publication_date = document.getElementById("add_date").value
    let genre = document.getElementById("add_genre").value
    let description = document.getElementById("add_description").value
    if (name && author && publication_date.match(/^\d{4}-\d{2}-\d{2}$/) && description && genre) {
        const book = {
            "id":  0,
            "name": name,
            "author": author,
            "publication_date": publication_date,
            "genre": genre,
            "description": description,
            "state": {
                "is_in_library": true,
                "is_overdue": false,
                "reader_username": "",
                "back_date": ""
            }
        }
        try {
            let response = await fetch("/library", {method: "POST", body: JSON.stringify(book), headers: {'Content-Type': 'application/json'}})
            let text_response = await response.text()
            console.log(text_response)
            await init_book_list(enabled_settings)
        } catch (error){
            console.error("Ошибка:", error)
        }
    }
}

export async function delete_book(book_id){
    let agree = confirm("Вы уверены?")

    if (agree){
        try {
            let response = await fetch("/library", {method: "DELETE", body: JSON.stringify({"id": book_id}), headers: {'Content-Type': 'application/json'}})
            let text_response = await response.text()
            console.log(text_response)
            await init_book_list(enabled_settings)
        } catch (error){
            console.error("Ошибка:", error)
        }
    }
}

export async function init_book_list(state) {
    document.getElementById("book_list_container").innerHTML = ``
    try {
        let response = await fetch("http://localhost:3000/filter?state="+state, {method: "GET"})
        let text_response = await response.text()
        JSON.parse(text_response).forEach((el) => {
            if (el !== null) {
                document.getElementById("book_list_container").innerHTML += `
                    <div class="book_info_container">
                        <div id=${el.id} class="card_link" onclick="go_to_book_card(this)">
                            <div class="book_data">${el.name}</div>
                            <div class="book_data">${el.author}</div>
                            <div class="book_data">${(el.state.is_in_library) ? "есть в наличии" : "отсутствует"}</div>
                            <div class="book_data">${(el.state.is_overdue) ? "возврат просрочен" : "не просрочен"}</div>
                        </div>
                        <div class="dell_button_container">
                            <button id="del_book_button" onclick="delete_book(${el.id})">Удалить книгу</button>
                        </div>
                    </div>
                `
            }
        })
    } catch (error){
        console.error("Ошибка:", error)
    }
}

init_book_list("all")
var radio_buttons = document.querySelectorAll("input[type=radio]")
var enabled_settings = []
radio_buttons.forEach((radio) => {
    radio.addEventListener("change", async () => {
        enabled_settings = Array.from(radio_buttons).filter(i => i.checked).map(i => i.value)[0] 
        await init_book_list(enabled_settings)
    })
})