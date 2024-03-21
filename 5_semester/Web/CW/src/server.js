import express from "express"
import http from "http"

import { router } from "./router.js"

const app = express()

// Подключение обработчика шаблонов ejs, шаблоны – в папке views

app.set("view engine", "ejs")
app.set("views", `./views`)


//Настройка приложения
app.use("/public", express.static("public")) // Указание статической папки public
app.use(express.json())                      // Обработка параметров в body
app.use("/", router)                         // Использование маршрутизации 

//Настройка http сервера
const http_server = http.createServer(app)

// Задание порта
http_server.listen(8080)