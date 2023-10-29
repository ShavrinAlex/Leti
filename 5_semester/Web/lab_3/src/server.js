import express from "express"
import https from "https"
import http from "http"
import cors from "cors"
import fs from "fs"
import { Server } from "socket.io";
import { router } from "./router.js"

import users from "./public/data/users.json" assert { type: "json" }
import news_js from "./public/data/news.json" assert { type: "json" }
import dialogs_js from "./public/data/dialogs.json" assert { type: "json" }
import messages_js from "./public/data/messages.json" assert { type: "json" }


const corsOptions = {
  "credentials": true,
  'origin': true,
  'methods': 'GET,HEAD,PUT,PATCH,POST,DELETE',
  'allowedHeaders': 'Authorization,X-Requested-With,X-HTTP-Method-Override,Content-Type,Cache-Control,Accept'
}

const app = express()

// Подключение обработчика шаблонов ejs, шаблоны – в папке views
app.set("view engine", "ejs")
app.set("views", `./views`)

//Настройка приложения
app.use("/public", express.static("public")) // Указание статической папки public
app.use(express.json())                      // Обработка параметров в body
app.use("/", router)                         // Использование маршрутизации 
app.use(cors(corsOptions))

//Настройка https сервера
const https_server = https.createServer({
  cert: fs.readFileSync('public/ssl_certs/open_key.csr', 'utf8'),
  key: fs.readFileSync('public/ssl_certs/private_key.key', 'utf8')
}, app)

const http_server = http.createServer(app)

// Задание порта
https_server.listen(7443)
http_server.listen(8080)

// Создание сокета
let socket_io = new Server(http_server, { cors: corsOptions })
socket_io.on('connection', (socket) => {
  console.log("connect soket " + socket.id)

  socket.on('news', (news) => {
    let news_id = news_js[news_js.length - 1].news_id + 1
    news.news_id = news_id 
    news_js.push(news)
    fs.writeFile("./public/data/news.json", JSON.stringify(news_js), function (err) {
      if (err) console.log("Write JSON error!");
    })
    console.log('news', news)
    socket_io.sockets.emit('news', news)
  })

  socket.on('message', (data) => {
    let message_id = messages_js[messages_js.length - 1].id + 1
    data.message.id = message_id
    messages_js.push(data.message)
    let dialog = dialogs_js.filter((cur_dialog) => {
      return cur_dialog.id == data.dialog_id
    })[0]
    dialog.messages.push(message_id)
    fs.writeFile("./public/data/messages.json", JSON.stringify(messages_js), function (err) {
      if (err) console.log("Write JSON error!");
    })
    fs.writeFile("./public/data/dialogs.json", JSON.stringify(dialogs_js), function (err) {
      if (err) console.log("Write JSON error!");
    })
    console.log('message', data)
    socket_io.sockets.emit('message', data)
  })

  socket.on('dialog', (data) => {
    socket_io.sockets.emit('dialog', data)
  })
})
