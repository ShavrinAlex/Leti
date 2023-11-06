import { TileSet } from "./HelperClasses/TileSet.js"
import { Tile } from "./HelperClasses/Tile.js"


export class MapManager {
    /* Класс менеджера карты */

    mapData = null;
    tLayer = null;
    xCount = 0;
    yCount = 0;
    tSize = { x: 32, y: 32 };
    mapSize = { x: 32, y: 32 };
    //view = {x: 0, y: 0, w: 32*20, h: 32*20};
    tilesets = new Array();

    imgLoadCount = 0;
    imgLoaded = false;
    jsonLoaded = false;

    getTileset(tileIndex) {
        /* Метод, возвращающий набор тайлов с заданным индексом */

        for (let i = this.tilesets.length - 1; i >= 0; i--){
            if (this.tilesets[i].firstgid <= tileIndex) {
                return this.tilesets[i];
            }
        }
        return null; 
    }

    getTile (tileIndex) {
        /* Метод, возвращающий тайл с заданным индексом  */

        let tileset = this.getTileset(tileIndex);

        let img = tileset.image;
        let id = tileIndex - tileset.firstgid;
        let x = id % tileset.xCount;
        let y = Math.floor(id / tileset.xCount);

        let tile = new Tile(img, x * this.tSize.x, y * this.tSize.y);

        return tile; 
    }

    parseMap(tilesJSON) {
        /* Метод, осуществляющий заполнение данных класса в соответствии с переданной конфигурацией карты */

        let self = this;
        //console.log(JSON.parse(tilesJSON));
        this.mapData = JSON.parse(tilesJSON);
        this.xCount = this.mapData.width;
        this.yCount = this.mapData.height;
        this.tSize.x = this.mapData.tilewidth;
        this.tSize.y = this.mapData.tileheight;
        this.mapSize.x = this.xCount * this.tSize.x;
        this.mapSize.y = this.yCount * this.tSize.y;
        //this.view.w = Math.min(this.mapSize.x, this.view.w);
        //this.view.h = Math.min(this.mapSize.y, this.view.h);
        
        for (let i = 0; i < this.mapData.tilesets.length; i++) {
            // Загрузка всех наборов тайлов

            let t = this.mapData.tilesets[i]; 
            let img = new Image();
            img.onload = function () {
                // Отметка загруженного набора тайлов

                self.imgLoadCount++;
                if (self.imgLoadCount === self.mapData.tilesets.length) {
                    //console.log("img", self.imgLoadCount)
                    self.imgLoaded = true;
                }
            }
            img.src = t.image;
            //img.onload();

            let ts = new TileSet(t.firstgid, img, t.name, t.imagewidth, t.imageheight, this.tSize.x, this.tSize.y);
            this.tilesets.push(ts);
        }
        this.jsonLoaded = true;
    }

    async loadMap(path) {
        /* Метод осуществляющий загрузку заданной карты */

        let self = this;
        let request = new XMLHttpRequest();
        request.onreadystatechange = function () {
            if (request.readyState === 4 && request.status === 200) {
                // Обработка ответа с файлом карты от сервера
            
                self.parseMap(request.responseText);
            }
        }
        request.open('GET', path, true)
        request.send()
    }
    /*
    isVisible(x, y, width, height) {
        //Метод, проверяющий заданную клетку на принадлежность видимой части поля

        if (x + width < this.view.x || y + height < this.view.y || x > this.view.x + this.view.w || y > this.view.y + this.view.h){
            return false;
        }
        return true;
    }
    */
    draw(canvas, ctx) {
        /* Метод отрисовки карты */

        let self = this;
        
        if (!this.imgLoaded || !this.jsonLoaded) {  
            // Дожидаемся загрузки файла карты и всех наборов тайлов

            setTimeout(function () {    
                self.draw(canvas, ctx); 
            }, 100);
        } else {

            //canvas.width = this.view.w;
            //canvas.height = this.view.h;
            canvas.width = this.mapSize.x;
            canvas.height = this.mapSize.y;
            //this.centerAt(this.mapSize.x/2, this.mapSize.y/2)
            ctx.fillStyle = 'black';
            ctx.fillRect(0, 0, canvas.width, canvas.height);

            if(this.tLayer === null) {
                // Загружаем матрицу карты

                for (let id = 0; id < this.mapData.layers.length; id++) {
                    let layer = this.mapData.layers[id];
                    if (layer.type === "tilelayer") {
                        this.tLayer = layer;
                        break;
                    }
                }
            }

            for (let i = 0; i < this.tLayer.data.length; i++) {
                if (this.tLayer.data[i] !== 0) {
                    // Отрисовка каждого тайла карты

                    let tile = this.getTile(this.tLayer.data[i]);
                    let pX = (i % this.xCount) * this.tSize.x;
                    let pY = Math.floor(i / this.xCount) * this.tSize.y;
                    /*
                    if(!this.isVisible(pX, pY, this.tSize.x, this.tSize.y)){
                        continue;
                    }
                    pX -= this.view.x;
                    pY -= this.view.y;
                    */
                    ctx.drawImage(tile.img, tile.px, tile.py, self.tSize.x, self.tSize.y, pX, pY, self.tSize.x, self.tSize.y);
                }
            } 
        } 
    }

    parseEntities(game_manager) {
        /* Метод, осуществляющий расстановку сущностей игры */

        let self = this
        if (!this.imgLoaded || !this.jsonLoaded) {
            // Дожидаемся загрузки карты
            
            setTimeout(function () { 
                self.parseEntities(game_manager); 
            }, 100);
        } else {
            for (let j = 0; j < this.mapData.layers.length; j++) {
                if(this.mapData.layers[j].type === 'objectgroup') {
                    let entities = this.mapData.layers[j];
                    for (let i = 0; i < entities.objects.length; i++) {
                        let entity = entities.objects[i];

                        game_manager.createGameObject(entity.type, entity.id, entity.name, entity.x, entity.y, entity.width, entity.height);
                    } 
                } 
            }
        }
    }

    parseGhost(game_manager, ghost_id){
        let self = this
        if (!this.imgLoaded || !this.jsonLoaded) {
            // Дожидаемся загрузки карты
            
            setTimeout(function () { 
                self.parseGhost(game_manager, ghost_id); 
            }, 100);
        } else {
            for (let j = 0; j < this.mapData.layers.length; j++) {
                if(this.mapData.layers[j].type === 'objectgroup') {
                    let entities = this.mapData.layers[j];
                    for (let i = 0; i < entities.objects.length; i++) {
                        if (entities.objects[i].id === ghost_id){
                            let entity = entities.objects[i];

                            game_manager.createGameObject(entity.type, entity.id, entity.name, entity.x, entity.y, entity.width, entity.height);
                        }
                       
                    } 
                } 
            }
        }
    }

    getTilesetIdx(x, y, round_func){
        /*  */
        
        let wX = x;
        let wY = y;
        let idx = round_func((wY / this.tSize.y)) * this.xCount + round_func((wX / this.tSize.x));
        //console.log(round_func((wY / this.tSize.y)), round_func((wX / this.tSize.x)))
        //console.log("idx ", idx, this.tLayer.data[idx]);
        return this.tLayer.data[idx];
    }
    /*
    centerAt(x, y) {
        //Метод, осуществляющий центровку видимой части поля

        if(x < this.view.w / 2) {
            this.view.x = 0;
        } else {
            if(x > this.mapSize.x - this.view.w / 2){
                this.view.x = this.mapSize.x - this.view.w;
            } else {
                this.view.x = x - (this.view.w / 2);
            }
        }
        if(y < this.view.h / 2) {
            this.view.y = 0;
        } else {
            if(y > this.mapSize.y - this.view.h / 2){
                this.view.y = this.mapSize.y - this.view.h;
            } else {
                this.view.y = y - (this.view.h / 2);
            }
        }
    }
    */
};


