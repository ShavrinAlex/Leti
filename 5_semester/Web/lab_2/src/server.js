import express from "express"
import fileUpload from "express-fileupload"
import cookieParser from "cookie-parser"
import {router} from "./router.js"


const server = express()

// Подключение обработчика шаблонов ejs, шаблоны – в папке views
server.set("view engine", "ejs")
server.set("views", `./views`)

//Настройка сеервера 
server.use("/public", express.static("public")) // Указание статической папки public
server.use(fileUpload())                        // Загрузка файлов на сервер
server.use(cookieParser())                      // Обработка cookies
server.use(express.json())                      // Обработка параметров в body
server.use("/", router)                         // Использование маршрутизации 

// Задание порта
server.listen(3000)
