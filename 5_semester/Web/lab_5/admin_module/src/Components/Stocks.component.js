import { useEffect, useState } from 'react';
import './Stocks.css';
//import axios from "axios";

const ENDPOINT = 'http://localhost:8080/getStocks'

export const StocksComponent = () => {
    const [stocks, setStocks] = useState([]);
    const [isLoad, setLoad] = useState(false);

    useEffect(() => {
        if (!isLoad){
            (async () => {
                const data = await fetch(ENDPOINT).then(res => res.json());
                setStocks(data);
                setLoad(true);
            })();
        }
    }, [])

    if (stocks?.length) {
        //console.log(stocks);
        return (
            <div className='stocks_container'>
                <div>
                    {stocks.map(stock => {
                        return <Stock key={stock.id} value={stock}></Stock>
                    })}
                </div>
            </div>
        );
    } else {
        return <h1>No stocks</h1>
    }
}

function Stock(props) {
    return (
        <div className='stock'>
            <p> {props.value.id}</p>
            <p> {props.value.name}</p>
        </div>
    )
}