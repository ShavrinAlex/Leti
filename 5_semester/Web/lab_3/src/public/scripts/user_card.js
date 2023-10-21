$(() => {
    $(".return_button").on("click", function () {
        $.get("{/admin_module/users")
        window.location = "/admin_module/users"
    })

    $(".new_page_button").on("click", function () {
        $.get(`/admin_module/users/${this.value}/${this.id}`)
        window.location = `/admin_module/users/${this.value}/${this.id}`
    })
    
    $(".change_data_button").on("click", function () {
        console.log("change")
        let data = ``
        let html_text = ``
        if (this.id == "role") {
            data += "Role:"
            html_text += `<option value="admin">Admin</option><option value="user">User</option>`
        } else {
            data += "Status:"
            html_text += `<option value="verified">Verified</option><option value="unverified">Unverified</option><option value="blocked">Blocked</option>`
        }

        $(`#${this.id}`).parent().html(`${data} 
        <form>
            <select class="select" data=${this.id}>
                ${html_text}
            </select>
        </form>

        <button class="submit_button" id="${this.id}">
            <i class="fa fa-check" aria-hidden="true"></i>
        </button>`)

        $(".submit_button").on("click", function () {
            let user_data = $(`[class="select"][data="${this.id}"]`).val()
            console.log(this.id, user_data)
            /*$.post("", {user_data: user_data, param: this.value}).done((data) => {
                console.log("get")
            })*/
            window.location = ""
        })

    })
})