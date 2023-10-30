import express from "express"
import body_parser from 'body-parser'
import users from "./public/data/users.json" assert { type: "json" }
import news from "./public/data/news.json" assert { type: "json" }
import dialogs from "./public/data/dialogs.json" assert { type: "json" }
import messages from "./public/data/messages.json" assert { type: "json" }
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
            "friends": [],
            "dialogs": []
        }
        console.log(new_user)
        users.push(new_user)
        fs.writeFile("./public/data/users.json", JSON.stringify(users), function (err) {
            if (err) console.log("Write JSON error!");
        })
        console.log(users)
        res.send({"state": "success", "user_id": new_user.id})
    } else {
        res.send({"state": "user is exists"})
    }
})

router.get("/account/user_page", JsonParser, (req, res) => {
    const user = users.filter((current_user) => {
        return current_user.id == req.query.id
    })[0]

    if (user === undefined) {
        res.send({"state" : "unknown user"}) 
    } else {  
        const user_news = news.filter((current_news) => {
            return current_news.user_id == user.id
        })
    
        user_news.sort((first_news, second_news) => {
            return new Date(second_news.time_create) - new Date(first_news.time_create)
        })
        res.send({"state" : "success", "user": user, "news": user_news})
    }
})

router.get("/account/friends", JsonParser, (req, res) => {
    const main_user = users.filter((current_user) => {
        return current_user.id == req.query.id
    })[0]

    if (main_user === undefined) {
        res.send({"state" : "unknown user"}) 
    } else {  
        const friends = users.filter((user) => {
            return main_user.friends.includes(user.id)
        })
        res.send({"state" : "success", "user_friends": friends})
    }
})

router.get("/account/news", JsonParser, (req, res) => {
    const main_user = users.filter((current_user) => {
        return current_user.id == req.query.id
    })[0]

    if (main_user === undefined) {
        res.send({"state" : "unknown user"}) 
    } else {  
        const news_owners = users.filter((user) => {
            return main_user.friends.includes(user.id)
        })
        news_owners.push(main_user)
    
        let all_news = news.filter((current_news) => {
            return main_user.friends.includes(current_news.user_id) || current_news.user_id == main_user.id
        })
    
        all_news.sort((first_news, second_news) => {
            return new Date(second_news.time_create) - new Date(first_news.time_create)
        })
        res.send({"state" : "success", "news": all_news, "news_owners": news_owners})
    }
})

router.get("/account/messages", JsonParser, (req, res) => {
    const main_user = users.filter((current_user) => {
        return current_user.id == req.query.id
    })[0]

    if (main_user === undefined) {
        res.send({"state" : "unknown user"}) 
    } else {  
        const user_dialogs = dialogs.filter((dialog) => {
            return dialog.first_user_id == main_user.id || dialog.second_user_id == main_user.id
        })

        const companions = users.filter((user) => {
            let ans = false
            user_dialogs.forEach((dialog) => {
                if (dialog.first_user_id == user.id || dialog.second_user_id == user.id)
                    ans = true
            })
            return ans
        })

        const last_messages = messages.filter((message) => {
            let ans = false
            user_dialogs.forEach((dialog) => {
                let last_index = dialog.messages.length - 1
                if (dialog.messages[last_index] == message.id)
                    ans = true
            })
            return ans
        })

        res.send({"state" : "success", "dialogs": user_dialogs, "companions": companions, "last_messages": last_messages})
    }
})

router.get("/account/dialog", JsonParser, (req, res) => {
    const dialog = dialogs.filter((dialog) => {
        return dialog.id == req.query.dialog_id
    })[0]

    if (dialog === undefined) {
        res.send({"state" : "unknown dialog"}) 
    } else {  
        const dialog_messages = messages.filter((message) => {
            return dialog.messages.includes(message.id)
        })
        const companions = users.filter((user) => {
            return user.id == dialog.first_user_id || user.id == dialog.second_user_id
        })
        res.send({"state" : "success", "companions": companions, "messages": dialog_messages})
    }
})

router.get("/account/friends/go_to_dialog", JsonParser, (req, res) => {
    const main_user = users.filter((current_user) => {
        return current_user.id == req.query.user_id
    })[0]
    const friend = users.filter((current_user) => {
        return current_user.id == req.query.friend_id
    })[0]
    
    if (main_user === undefined || friend == undefined) {
        res.send({"state" : "unknown user"}) 
    } else {  
        let user_dialogs = dialogs.filter((dialog) => {
            return main_user.dialogs.includes(dialog.id)
        })
       
        let dialog_id = -1
        user_dialogs.forEach((dialog) => {
            if (dialog.first_user_id == req.query.friend_id || dialog.second_user_id == req.query.friend_id){
                dialog_id = dialog.id
            }
        })
        console.log("find", dialog_id)
        let new_dialog
        let companions
        if (dialog_id == -1){
            dialog_id = dialogs[dialogs.length - 1].id + 1
            new_dialog = {
                "id": dialog_id,
                "first_user_id": Number(req.query.user_id),
                "second_user_id": Number(req.query.friend_id),
                "messages": []
            }
            dialogs.push(new_dialog)
            main_user.dialogs.push(dialog_id)
            friend.dialogs.push(dialog_id)
            fs.writeFile("./public/data/dialogs.json", JSON.stringify(dialogs), function (err) {
                if (err) console.log("Write JSON error!");
            })
        } else {
            new_dialog = user_dialogs.filter((dialog) => {
                return dialog.id == dialog_id
            })[0]
        }
        companions = [main_user, friend]
        res.send({"state" : "success", "dialog": new_dialog, "companions": companions})
    }
})

router.post("/account/user_page/change_image", JsonParser, (req, res) => {
    let user = users.filter((current_user) => {
        return current_user.id == req.body.user_id
    })[0]

    if (user !== undefined) {
        user.avatar = req.body.avatar
        fs.writeFile("./public/data/users.json", JSON.stringify(users), function (err) {
            if (err) console.log("Write JSON error!");
        })
        res.send({"state": "success"})
    } else {
        res.send({"state": "unknown user"})
    }
})

router.post("/account/friends/add_friend", JsonParser, (req, res) => {
    let user = users.filter((current_user) => {
        return current_user.id == req.body.user_id
    })[0]

    let friend = users.filter((current_user) => {
        return current_user.name == req.body.friend_username
    })[0]

    if (user !== undefined && friend !== undefined) {
        user.friends.push(friend.id)
        friend.friends.push(user.id)
        fs.writeFile("./public/data/users.json", JSON.stringify(users), function (err) {
            if (err) console.log("Write JSON error!");
        })
        res.send({"state": "success"})
    } else {
        res.send({"state": "unknown user"})
    }
})

router.post("/account/friends/delete_friend", JsonParser, (req, res) => {
    let user = users.filter((current_user) => {
        return current_user.id == req.body.user_id
    })[0]

    let friend = users.filter((current_user) => {
        return current_user.id == req.body.friend_id
    })[0]

    if (user !== undefined && friend !== undefined) {
        user.friends.splice(user.friends.indexOf(friend.id), 1);
        friend.friends.splice(friend.friends.indexOf(user.id), 1);

        fs.writeFile("./public/data/users.json", JSON.stringify(users), function (err) {
            if (err) console.log("Write JSON error!");
        })
        res.send({"state": "success"})
    } else {
        res.send({"state": "unknown user"})
    }
})

router.get("/account", JsonParser, (req, res) => {
    const main_user = users.filter((current_user) => {
        return current_user.id == req.query.id
    })[0]

    if (main_user === undefined) {
        res.send({"state" : "unknown user"}) 
    } else {  
        const friends = users.filter((user) => {
            return main_user.friends.includes(user.id)
        })

        const user_dialogs = dialogs.filter((dialog) => {
            return dialog.first_user_id == main_user.id || dialog.second_user_id == main_user.id
        })

        const all_news = news.filter((current_news) => {
            return main_user.friends.includes(current_news.user_id) || current_news.user_id == main_user.id
        })
    
        all_news.sort((first_news, second_news) => {
            return new Date(second_news.time_create) - new Date(first_news.time_create)
        })

        const user_messages = messages.filter((current_message) => {
            let ans = false
            user_dialogs.forEach((dialog) => {
                if (dialog.messages.includes(current_message.id)){
                    ans = true
                }
            })
            return ans
        })

        const data = {
            "user": main_user,
            "friends": friends,
            "news": all_news,
            "dialogs": user_dialogs,
            "messages": user_messages
        }
       
        res.send({"state" : "success", "data": data})
    }
})