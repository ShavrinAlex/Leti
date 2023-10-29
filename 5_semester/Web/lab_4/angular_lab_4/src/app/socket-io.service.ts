import { Injectable } from '@angular/core';
import * as socketIo from 'socket.io-client';
import { Observable, Subscriber } from 'rxjs';
const server_url = "http://localhost:8080/"


@Injectable({
  providedIn: 'root'
})
export class SocketIoService {
  private socket_client: socketIo.Socket;
  constructor() {
    this.socket_client = socketIo.connect(server_url);
  }

  listenToServer(connection: string): Observable <any> {
    return new Observable((subscribe) => {
      this.socket_client.on(connection, (data) => {
        subscribe.next(data);
      })
    })
  }

  emitToServer(connection: string, data: any): void {
    this.socket_client.emit(connection, data);
  }

}
