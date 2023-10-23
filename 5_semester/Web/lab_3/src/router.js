import express from "express"
import body_parser from 'body-parser'
import users from "./public/data/users.json" assert { type: "json" }
import news from "./public/data/news.json" assert { type: "json" }
import fs from "fs"

export const router = express.Router()

router.get("/", (req, res) => {
    res.redirect("/admin_module/users")
})

router.get("/admin_module/", (req, res) => {
    res.redirect("/admin_module/users")
})

router.get("/admin_module/users", (req, res) => {
    res.render("users.ejs", {users: users})
})

router.get("/admin_module/users/:id([0-9]{1,})", (req, res) => {
    const user = users.filter((user) => { 
        return user.id == req.params.id
    })[0]

    const user_news = news.filter((current_news) => {
        return user.id == current_news.user_id
    })

    user_news.sort((first_news, second_news) => {
        return new Date(second_news.time_create) -new Date(first_news.time_create)
    })

    res.render("user_card.ejs", {user: user, news: user_news})
})

router.post("/admin_module/users/:id([0-9]{1,})", body_parser.json(), (req, res) => {
    let user = users.filter((user) => { 
        return user.id == req.params.id
    })[0]

    switch (req.body.param){
        case "role": 
            user.role = req.body.user_data 
            break
        case "status": 
            user.status = req.body.user_data
            break
    }

    fs.writeFile("./public/data/users.json", JSON.stringify(users), function (err) {
        if (err) console.log("Write JSON error!");
    })
})

router.get("/admin_module/users/:id([0-9]{1,})/friends", (req, res) => {
    const main_user = users.filter((user) => { 
        return user.id == req.params.id
    })[0]

    const friends = users.filter((user) => {
        return main_user.friends.includes(user.id)
    })

    res.render("user_friends.ejs", {friends: friends})
})

router.get("/admin_module/users/:id([0-9]{1,})/news", (req, res) => {
    const main_user = users.filter((user) => { 
        return user.id == req.params.id
    })[0]

    const friends = users.filter((user) => {
        return main_user.friends.includes(user.id)
    })

    let friend_news = news.filter((current_news) => {
        return main_user.friends.includes(current_news.user_id)
    })

    friend_news.sort((first_news, second_news) => {
        return new Date(second_news.time_create) - new Date(first_news.time_create)
    })
    res.render("user_news.ejs", {friends: friends, news: friend_news})
})
