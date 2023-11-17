import React from "react";
import { BrowserRouter, Routes, Route, Link } from "react-router-dom";
import './Router.css'
import { BrokersComponent } from "../Components/Brokers.component";
import { StocksComponent } from "../Components/Stocks.component";
/*
import SignIn from "../pages/signin/SignIn";
import SignUp from "../pages/createuser/CreateUser";
import ListUser from "../pages/listuser/ListUser";
import ListStock from '../pages/stock/ListStock'
import Settings from '../pages/setting/Settings'
import Graph from "../pages/graph/Graph";
<Route exact path="/signin" element={<SignIn/>}></Route>
<Route exact path="/signup" element={<SignUp/>}></Route>
<Route path="/dashboard" element={<ListUser/>}></Route>
<Route path="/stocks" element={<ListStock/>}></Route>
<Route path="/settings" element={<Settings/>}></Route>
<Route path="/graph/:id" element={<Graph/>}></Route>
*/

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
    return <div><h3>Trading</h3></div> 
} 

function NoMatch() { 
    return <div><h3>No match!</h3></div> 
}

export default Router;