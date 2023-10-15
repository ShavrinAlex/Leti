import express from "express"
import data from "./data.json" assert { type: "json" }

export const router = express.Router()

router.get("/", (req, res) => {
    res.render("index.ejs")
})

router.get("/book_card/", (req, res) => {
    res.render("book_card.ejs")
})

router.get("/filter", (req, res) => {
    if (req.query.state === "in_library") {
        let new_book_list = data["books"].filter((el) => {
            if (el.state.is_in_library === true){
                return true
            }
        })
        res.send(JSON.stringify(new_book_list))
    } else if (req.query.state === "overdue"){
        let new_book_list = data["books"].filter((el)=>{
            if(el.state.is_overdue === true){
                return true
            }
        })
        res.send(JSON.stringify(new_book_list))
    }else{
        res.send(JSON.stringify(data["books"]))
    }
})

router.post("/", (req, res) => {
    
    let last_index = data["books"].length - 1
    let id = data["books"][last_index].id + 1
    req.body.id = id
    data["books"].push(req.body)
    res.send("succes post")
})

router.delete("/", (req, res) => {
    const remove_index = data["books"].map((b) => {
        return parseInt(b.id)
    }).indexOf(parseInt(req.body.id))
    data["books"].splice(remove_index, 1)
    res.send("succes delete")
})

router.get("/:id([0-9]{1,})", (req, res) => {
    const book = data["books"].filter((el) => { 
        if (el.id == req.params.id) {
            return true
        }
    })
    res.render("book_card.ejs", {book: book[0]})
})

router.put("/:id([0-9]{1,})", (req, res) => {
    const change_index = data["books"].map((b) => {
        return parseInt(b.id);
    }).indexOf(parseInt(req.params.id))

    let new_body = req.body
    let response = "not put"
    if (new_body.change === "book"){
        data["books"][change_index]["name"] = new_body.name
        data["books"][change_index]["author"] = new_body.author
        data["books"][change_index]["genre"] = new_body.genre
        data["books"][change_index]["publication_date"] = new_body.publication_date
        data["books"][change_index]["description"] = new_body.description
        response = "succes put"
    } else if (new_body.change === "reader"){
        data["books"][change_index]["state"]["is_in_library"] = new_body.state.is_in_library
        data["books"][change_index]["state"]["is_overdue"] = new_body.state.is_overdue
        data["books"][change_index]["state"]["reader_username"] = new_body.state.reader_username
        data["books"][change_index]["state"]["back_date"] = new_body.state.back_date
        response = "succes put"
    }
    res.send(response)
})
