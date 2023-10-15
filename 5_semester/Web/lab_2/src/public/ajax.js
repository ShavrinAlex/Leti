init_book_list()

export async function init_book_list() {
    document.getElementById("book_list_container").innerHTML = ``
    let response = await fetch("http://localhost:3000/filter?state=none", {method: "GET"})
    let json_response = await response.json()
    JSON.parse(json_response).forEach((el) => {
        if (el !== null) {
            document.getElementById("book_list_container").innerHTML += `
                <div class="book_info_container">
                    <div id=${el.id}>
                        ${el.name}
                        ${el.author}
                    </div>
                    <button id="del_book_button">Удалить книгу</button>
                </div>
            `
        }
    })
}