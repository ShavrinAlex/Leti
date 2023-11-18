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

    handleConnection(client: any) {
        //console.log(client);
        console.log("CONNECTED");
    }

    @SubscribeMessage("start")
    handleEvent(@MessageBody() dto: any, @ConnectedSocket() client: any){
        console.log(dto)
        this.index = Number(dto.index);
        const res = {type: "send", dto}
        this.interval = setInterval(()=>{
            console.log(this.index);
            client.emit("trading", this.index);
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