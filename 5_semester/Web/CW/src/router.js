import express from "express"
import fs from 'fs'
import body_parser from "body-parser"

let level_1;
let level_2;

fs.readFile("./public/levels/level_1.json", (err, data) => {
    if (err) throw err;
    level_1 = JSON.parse(data);
});

fs.readFile("./public/levels/level_2.json", (err, data) => {
    if (err) throw err;
    level_2 = JSON.parse(data);
});

export const router = express.Router();

router.get("/", (req, res) => {
   res.render("index.ejs");
})

router.get("/level_1", (req, res) => {
    res.send(level_1);
})

router.get("/level_2", (req, res) => {
    res.send(level_2);
})
