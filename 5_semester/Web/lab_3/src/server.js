import express from "express"
import https from "https"
import fs from "fs"
import {router} from "./router.js"


const app = express()

// Подключение обработчика шаблонов ejs, шаблоны – в папке views
app.set("view engine", "ejs")
app.set("views", `./views`)

//Настройка приложения
app.use("/public", express.static("public")) // Указание статической папки public
app.use(express.json())                      // Обработка параметров в body
app.use("/", router)                         // Использование маршрутизации 

//Настройка https сервера
const https_server = https.createServer({
  cert: fs.readFileSync('public/ssl_certs/open_key.csr', 'utf8'),
  key: fs.readFileSync('public/ssl_certs/private_key.key', 'utf8')
}, app)

// Задание порта
https_server.listen(7443)
