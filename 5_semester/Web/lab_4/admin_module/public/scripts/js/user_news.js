$(() => {
    $(".return_button").on("click", function () {
        console.log("return")
        console.log(`/admin_module/users/${this.id}`)
        window.location = `/admin_module/users/${this.id}`
    })
})