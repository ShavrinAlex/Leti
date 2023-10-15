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
    console.log(data["books"].length, last_index, id)
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
    if (req.body.what_change === "book"){
        data["books"][change_index]["name"] = new_body.name
        data["books"][change_index]["author"] = new_body.author
        data["books"][change_index]["genre"] = new_body.genre
        data["books"][change_index]["publication_date"] = new_body.publication_date
        data["books"][change_index]["description"] = new_body.description
    } else if (req.body.what_change === "user"){
        data["books"][change_index]["is_in_library"] = new_body.is_in_library
    }
    res.send("succes put")
})
