import { useEffect, useState } from "react";
import { useDispatch, useSelector } from "react-redux";
import { SocketIoService, useConnectSocket } from "../Socket-io.service";
import "./Trading.css";

const ENDPOINT = 'http://localhost:8081/getStocks';


export const TradingComponent = () => {
    const listTradings = useSelector(state => state.tradingList)

    const [stocks, setStocks] = useState([])
    const [trading, setTrading] = useState([])
    const [speed, setSpeed] = useState(0)
    const [date, setDate] = useState('')
    const [change, setChange] = useState(0)

    const setSpeedChange = (e) => {
        setSpeed(e.target.value)
    }

    const setDateChange = (e) => {
        setDate(e.target.value)
    }

    useConnectSocket();

    useEffect(() => {
        SocketIoService.socket.on("trading", (data) => {
            console.log("trading" + data, trading);
            setChange(JSON.parse(data));
        })
    }, []);

    useEffect(() => {
        clickStop();
        (async () => {
            const data = await fetch(ENDPOINT).then(res => res.json())
            setStocks(data);

            let tr = []
            listTradings.forEach((el) => {
                const index = data.map((g) => {
                    return g.id;
                }).indexOf(el);
                if (index > -1) {
                    tr.push({id: data[index].id, name: data[index].name, prices: data[index].data.reverse()})
                }
            })
            setTrading(tr);
        })()
    }, [])

    const clickStart = () => {
        if (speed > 0 && date && trading){
            console.log(listTradings)
            SocketIoService.socket.emit("trading_list_done", {listTradings})

            let index = -1;
            for (let i = 0; i < trading[0].prices.length; i++){
                if (new Date(trading[0].prices[i].Date).toDateString() === new Date(date).toDateString()){
                    console.log(new Date(trading[0].prices[i].Date).toDateString(), new Date(date).toDateString())
                    index = i;
                    break;
                }
            }
            SocketIoService.socket.emit("start", {index, speed})
        }
        console.log("start");
        console.log(trading);
    }

    const clickStop = () => {
        console.log('stop')
        SocketIoService.socket.emit("stop")
    }

    if (stocks?.length) {
        if (!trading[0]?.prices[change]){
            clickStop();
            window.location = 'http://localhost:3000/stocks'
        }
        return (
            <div className="trading_container">
                <div className="trading_settings">
                    <div className="form">
                        <label className="form_elem">Дата начала</label>
                        <input className="form_elem" type="date" onChange={setDateChange} value={date}/>
                    </div>
                    <div className="form">
                        <label className="form_elem">Скорость</label>
                        <input className="form_elem" type="number" onChange={setSpeedChange} value={speed}/>
                    </div>
                    <div className="form">
                        <button className="form_elem" id="start_button" onClick={clickStart}>START</button>
                        <button className="form_elem" id="stop_button" onClick={clickStop}>STOP</button>
                    </div>
                </div>

                <div className="scrollable_trading">
                    {
                        (change > 0 && date && speed) ? (
                            trading.map(trad => (
                                <div key={trad.id}>
                                    <div className="trading_elem">
                                        <div className="trading_info">{trad.name}</div>
                                        <div className="trading_info">{trad.prices[change]?.Open}</div>
                                        <div className="trading_info">{trad.prices[change]?.Date}</div>
                                    </div>
                                </div>
                            ))
                        ) : (<div></div>)
                    }
                </div>
            </div>
        )
    }

    return <h1> Wait</h1>
}

export default TradingComponent;