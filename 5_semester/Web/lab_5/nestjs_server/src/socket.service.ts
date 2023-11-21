import {
    ConnectedSocket,
    MessageBody,
    OnGatewayConnection,
    SubscribeMessage,
    WebSocketGateway
} from "@nestjs/websockets";


@WebSocketGateway(
    {
        cors: {
            origin:"*"
        }
    }
)
export class SocketService implements OnGatewayConnection{
    private index: number = 0;
    private interval: any;
    private wsClients: any[] = [];

    handleConnection(client: any) {
        console.log("CONNECTED");
        this.wsClients.push(client)
    }
    
    handleDisconnect(client: any) {
        console.log("DISCONNECTED");
        for (let i = 0; i < this.wsClients.length; i++) {
            if (this.wsClients[i] === client) {
              this.wsClients.splice(i, 1);
              break;
            }
        }
    }
    
    private broadcast(event: string, message: any) {
        const broadCastMessage = JSON.stringify(message);
        for (let client of this.wsClients) {
        //console.log(event, broadCastMessage)
          client.send(event, broadCastMessage);
        }
    }
    
    @SubscribeMessage("trading_list_done")
    handleTradingListEvent(@MessageBody() dto: any, @ConnectedSocket() client: any){
        this.broadcast('trading_list', dto.listTradings);
    }
    
    @SubscribeMessage("start")
    handleStartEvent(@MessageBody() dto: any, @ConnectedSocket() client: any){
        console.log(dto)
        this.index = Number(dto.index);
        const res = {type: "send", dto}
        this.interval = setInterval(()=>{
            console.log(this.index);
            this.broadcast('trading', this.index);
            //client.emit("trading", this.index);
            this.index += 1;
        }, 1000*dto.speed);
    }

    @SubscribeMessage("stop")
    handleStopEvent(@MessageBody() dto: any, @ConnectedSocket() client: any){
        clearInterval(this.interval)
        console.log("stop")
        this.index = 0
    }
}