$(() => {
    $(".user_container").on("click", function () {
        $.get(`/admin_module/users/${this.id}`)
        window.location = `/admin_module/users/${this.id}`
    })
})