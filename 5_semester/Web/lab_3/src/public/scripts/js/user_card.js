$(() => {
    //$.get("{/admin_module/users")
    $(".return_button").on("click", function () {
        
        window.location = "/admin_module/users"
    })

    $(".new_page_button").on("click", function () {
        $.get(`/admin_module/users/${this.value}/${this.id}`)
        window.location = `/admin_module/users/${this.value}/${this.id}`
    })
    
    $(document).on("click", ".change_data_button", function () {
        let data = ``
        let html_text = ``
        if (this.id == "role") {
            data += "Role:"
            html_text += `<option value="admin">admin</option><option value="user">user</option>`
        } else {
            data += "Status:"
            html_text += `<option value="verified">verified</option><option value="unverified">unverified</option><option value="blocked">blocked</option>`
        }

        $(`#${this.id}`).parent().html(`${data} 
            <form>
                <select class="select" data=${this.id}>
                    ${html_text}
                </select>
            </form>

            <button class="submit_button" id="${this.id}">
                <i class="fa fa-check" aria-hidden="true"></i>
            </button>
        `)
    })

    $(document).on("click", ".submit_button",  function () {
        let user_data = $(`[class="select"][data="${this.id}"]`).val()

        $.ajax({
            type: "POST",
            url: "", 
            data: JSON.stringify({param: this.id, user_data: user_data}),
            dataType: "json",
            headers: {"Content-Type": "application/json"}
        })
        let data = (this.id == "role") ?"Role:" : "Status:"

        $(`#${this.id}`).parent().html(`
            ${data} ${user_data}
            <button class="change_data_button" id="${this.id}"><i class="fa fa-pencil" aria-hidden="true"></i></button>
        `)
    })

    $(".accordion").accordion({
        collapsible: true
    })
})