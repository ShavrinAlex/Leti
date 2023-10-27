import express from "express"
import body_parser from 'body-parser'
import users from "./public/data/users.json" assert { type: "json" }
import news from "./public/data/news.json" assert { type: "json" }
import fs from "fs"
const JsonParser = express.json()

export const router = express.Router()

router.use((req, res, next) => {
    res.header("Access-Control-Allow-Origin", "*")
    res.header("Access-Control-Allow-Headers", "Content-Type")
    res.header('Access-Control-Allow-Methods', 'GET, POST')
    next()
})

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
    res.render("user_news.ejs", {friends: friends, news: friend_news, user: main_user})
})

router.get("/authorization/login", (req, res) => {
    const user = users.filter((current_user)=>{
        return current_user.email === req.query.email
    })[0]

    if (user === undefined) {
        res.send({"state" : "unknown user"}) 
    } else {
        if (user.password != req.query.password) {
            res.send({"state" : "wrong password"}) 
        } else {
            res.send({"state" : "correct", "user_id": user.id})
        }
    }
})

router.post("/authorization/signup", JsonParser, (req, res) => {
    const user = users.filter((current_user) => {
        return current_user.email == req.body.email
    })[0]

    if (user === undefined) {
        let last_index = users.length - 1
        let id = users[last_index].id + 1
        let new_user = {
            "id": id,
            "name": req.body.username,
            "birth_date": req.body.birth,
            "email": req.body.email,
            "password": req.body.password,
            "avatar": "",
            "role": "user",
            "status": "unverified",
            "friends": []
        }
        users.push(new_user)
        fs.writeFile("./public/data/users.json", JSON.stringify(users), function (err) {
            if (err) console.log("Write JSON error!");
        })
        res.send({"state": "success", "user_id": new_user.id})
    } else {
        res.send({"state": "user is exists"})
    }
})

router.get("/account/user_page", (req, res) => {
    const user = users.filter((current_user)=>{
        return current_user.email === req.query.user_id
    })[0]

    if (user === undefined) {
        res.send({"state" : "unknown user"}) 
    } else {
        if (user.password != req.query.password) {
            res.send({"state" : "wrong password"}) 
        } else {
            res.send({"state" : "correct", "user_id": user.id})
        }
    }
})