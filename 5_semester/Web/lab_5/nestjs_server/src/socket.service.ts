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
    private list: any[] = [];

    handleConnection(client: any) {
        if (!this.wsClients.includes(client)){
            console.log("CONNECTED");
            this.wsClients.push(client);
        }
    }
    
    handleDisconnect(client: any) {
        for (let i = 0; i < this.wsClients.length; i++) {
            if (this.wsClients[i] === client) {
                console.log("DISCONNECTED");
                this.wsClients.splice(i, 1);
                break;
            }
        }
    }
    
    private broadcast(event: string, message: any) {
        const broadCastMessage = JSON.stringify(message);
        for (let client of this.wsClients) {
            client.emit(event, broadCastMessage);
        }
    }
    
    @SubscribeMessage("trading_list_done")
    handleTradingListEvent(@MessageBody() dto: any, @ConnectedSocket() client: any){
        this.list = dto
        this.broadcast('trading_list', dto);
    }
    
    @SubscribeMessage("start")
    handleStartEvent(@MessageBody() dto: any, @ConnectedSocket() client: any){
        console.log(dto)
        this.index = Number(dto.index);
        const res = {type: "send", dto}
        this.interval = setInterval(()=>{
            console.log(this.index);
            this.broadcast('trading_list', this.list);
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

    @SubscribeMessage("buy")
    handleBuyEvent(@MessageBody() dto: any, @ConnectedSocket() client: any){
        console.log(dto)
        fetch("http://localhost:8081/buyStock", {
            method: "POST",
            body: dto,
            headers: {
                'Content-Type': 'application/json'
            }
        }).then((res)=> {
            res.json().then((answer) => {
                
                if (answer.mes === "success") {
                    //console.log(answer.message.data)
                    this.broadcast("broker_buy", answer.data)
                }
            });
        });
    }

    @SubscribeMessage("sell")
    handleSellEvent(@MessageBody() dto: any, @ConnectedSocket() client: any){
        console.log(dto)
        fetch("http://localhost:8081/sellStock", {
            method: "POST",
            body: dto,
            headers: {
                'Content-Type': 'application/json'
            }
        }).then((res)=> {
            res.json().then((answer) => {
                if (answer.mes === "success") {
                    //console.log(answer.message.data)
                    this.broadcast("broker_sell", answer.data)
                }
            });
        });
    }
}