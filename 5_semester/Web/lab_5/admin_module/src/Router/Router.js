import React from "react";
import { BrowserRouter, Routes, Route, Link } from "react-router-dom";
import './Router.css'
import { BrokersComponent } from "../Components/Brokers.component";
import { StocksComponent } from "../Components/Stocks.component";
import { TradingComponent } from "../Components/Trading.component"


function Router() {
    return (
        <BrowserRouter>
            <NavigationBar/>
            <Routes>
                <Route exact path="/brokers" element={<Brokers/>}></Route>
                <Route path="/stocks" element={<Stocks/>}></Route>
                <Route path="/trading" element={<Trading/>}></Route>
                <Route path="*" element={<NoMatch/>}></Route>
            </Routes>
        </BrowserRouter>
    );
}

function NavigationBar() {
    return (<div className="navigation_bar">
            <Link to="/brokers" className="navigation_elem">Brokers</Link>
            <Link to="/stocks" className="navigation_elem">Stocks</Link>
            <Link to="/trading" className="navigation_elem">Trading</Link>
        </div>);
}

function Brokers() { 
    return <BrokersComponent/>
} 

function Stocks() { 
    return  <StocksComponent/>
} 

function Trading() { 
    return <TradingComponent/>
} 

function NoMatch() { 
    return <div><h3>Page no match!</h3></div> 
}

export default Router;