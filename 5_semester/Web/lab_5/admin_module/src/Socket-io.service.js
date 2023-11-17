import * as socketIo from 'socket.io-client';
const SERVER_ERL = "http://localhost:8080/";


export class SocketIoService {
    #socket_client = null;
    
    constructor() {
        this.#socket_client = socketIo.connect(SERVER_ERL);

        this.#socket_client.on('connect',()=>{
            console.log("connected");
        })
        this.#socket_client.on('disconnect',()=>{
            console.log("disconnect");
        })
    }
    
    listenToServer(connection) {
        return new Observable((subscribe) => {
            this.#socket_client.on(connection, (data) => {
                subscribe.next(data);
            })
        })
    }

    emitToServer(connection, data) {
        this.#socket_client.emit(connection, data);
    }
}