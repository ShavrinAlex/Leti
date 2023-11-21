import { useEffect, useState } from 'react';
import { useDispatch, useSelector } from "react-redux";
import Graphic from './Chart.component';
import './Stocks.css';

const ENDPOINT = 'http://localhost:8081/getStocks'

export const StocksComponent = () => {
    const [stocks, setStocks] = useState([]);
    const [isLoad, setLoad] = useState(false);
    const dispatch = useDispatch();

    useEffect(() => {
        if (!isLoad){
            (async () => {
                const data = await fetch(ENDPOINT).then(res => res.json());
                setStocks(data);
                setLoad(true);
                dispatch({ type: "SAVE", tradingList: [] });
            })();
        }
    }, [])

    if (stocks?.length) {
        //console.log(stocks);
        return (
            <div className='stocks_container'>
                <div className='scrollable'>
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
    const [open, setOpenChart] = useState(false);
    const dispatch = useDispatch();
    const listTradings = useSelector(state => state.tradingList);

    const toggleChart = () => {
        setOpenChart(!open);
    }

    const [chartData, setChartData] = useState({
        labels: props.value.data.map((data) => data.Date).reverse(),
        datasets: [
            {
                label: "Users Gained ",
                data: props.value.data.map((data) => data.Open.match(/(\d+)/)[0]).reverse(),
                borderColor: "black",
                borderWidth: 2
            }
        ]
    });

    const changeListTrading = (e) =>{
        if(e.target.checked){
            listTradings.push(e.target.value)
        } else {
            let index = listTradings.indexOf(e.target.value);
            listTradings.splice(index, 1);
        }
        //console.log(listTradings)
        dispatch({ type: "SAVE", tradingList: listTradings });
    }
    
    return (
        <div>
            <div className='stock'>
                <p className='stock_info' onClick={toggleChart}> {props.value.id}</p>
                <p className='stock_info' onClick={toggleChart}> {props.value.name}</p>
                <input className='trading_target_button' type="checkbox" value={props.value.id} onChange={changeListTrading}/>
            </div>
            { open ? <div><Graphic key={props.value.id} value={chartData}/></div> : null }
        </div>
    )
}

export default StocksComponent;