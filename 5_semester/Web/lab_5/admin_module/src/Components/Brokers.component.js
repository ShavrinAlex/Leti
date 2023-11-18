import { useEffect, useState } from 'react';
import './Brokers.css';
//import axios from "axios";

const GET_BROKERS_URL = 'http://localhost:8080/getAllBrokers';
const ADD_BROKER_URL = 'http://localhost:8080/addBroker';
const CHANGE_BROKER_URL = 'http://localhost:8080/changeBroker/';
const DELETE_BROKER_URL = 'http://localhost:8080/deleteBroker/';


export const BrokersComponent = () => {
    const [brokers, setBrokers] = useState([]);
    const [isLoad, setLoad] = useState(false);

    useEffect(() => {
        if (!isLoad){
            (async () => {
                const data = await fetch(GET_BROKERS_URL).then(res => res.json());
                setBrokers(data);
                setLoad(true);
            })();
        }
    }, [])

    if (brokers?.length) {
        //console.log(brokers);
        return (
            <div className='brokers_container'>
                <AddBroker/>
                <div className='scrollable'>
                    {brokers.map(broker => {
                        return <Broker key={broker.id} value={broker}></Broker>
                    })}
                </div>
            </div>
        );
    } else {
        return <h1>No brokers</h1>
    }
}

function Broker(props) {
    const [openDialog, setOpenChangeDialog] = useState(false);
    const [inputAccount, setInputAccount] = useState(0);


    const openChangeDialog = () => {
        setOpenChangeDialog(true);
    };

    const changeAccount = (e) => {
        setInputAccount(Number(e.target.value))
    }

    const confirmChange = async (e) => {
        console.log("new value" + inputAccount);

        try {
            const response = await fetch(CHANGE_BROKER_URL + e.target.value, {
                method: "PUT",
                body: JSON.stringify({"account": inputAccount}),
                headers: {
                    'Content-Type': 'application/json'
                }
            });

            if (!response.ok) {
                throw new Error(`Error! status: ${response.status}`);
            }

            const result = await response.json();

            if (result.mes === "success"){
                console.log(result);
            }
        } catch (err) {
            console.log(err.message);
        }

        setOpenChangeDialog(false);
        window.location = "http://localhost:3000/brokers"
    };

    const deleteBroker = async (e) => {
        console.log('delete', DELETE_BROKER_URL + e.target.value)
        try {
            const response = await fetch(DELETE_BROKER_URL + e.target.value, {
                method: "DELETE"
            });

            if (!response.ok) {
                throw new Error(`Error! status: ${response.status}`);
            }

            const result = await response.json();

            if (result.mes === "success"){
                
                console.log(result);
            }    
        } catch (err) {
            console.log(err.message);
        }
        window.location = "http://localhost:3000/brokers"
    };

    return (
        <div className='broker'>
            <p className='broker_info'>{props.value.name}</p>
            <p className='broker_info'>{props.value.account}</p>
            <button className='change_broker_button' onClick={openChangeDialog}>Change</button>
            <button className='delete_broker_button' onClick={deleteBroker} value={props.value.id}>Delete</button>
            <dialog open={openDialog} style={{borderColor: "gray", borderRadius: 10}}>
                <p> Change Account: {props.value.name}</p>
                <form>
                    <input className='dialog_input' type="number" placeholder="Введите баланс" onChange={changeAccount}/>
                    <button className='confirm_button' value={props.value.id} onClick={confirmChange} autoFocus>Изменить</button>
                </form>
            </dialog>
        </div>
    )
}

function AddBroker(){
    const [openAdd, setOpenAddDialog] = useState(false);
    const [inputName, setInputName] = useState("");
    const [inputAccount, setInputAccount] = useState(0);

    const openAddDialog = () => {
        setOpenAddDialog(true);
    };

    const changeAccount = (e) => {
        setInputAccount(Number(e.target.value))
    }

    const changeName = (e) => {
        setInputName(e.target.value)
    }  

    const confirmAdd = async () => {
        console.log("new value ")
        if (inputName){
            try {
                let body = {
                    "id": -1,
                    "name": inputName,
                    "account": inputAccount
                }
                const response = await fetch(ADD_BROKER_URL, {
                    method: "POST",
                    body: JSON.stringify(body),
                    headers: {
                        'Content-Type': 'application/json'
                    }
                });
                
                if (!response.ok) {
                    console.log('myh err')
                    throw new Error(`Error! status: ${response.status}`);
                }

                const result = await response.json();

                if (result.mes === "success"){
                    console.log(result);
                }
                
            } catch (err) {
                console.log(err);
            }
        }
        setOpenAddDialog(false);
        window.location = 'http://localhost:3000/brokers';
    }

    return (
        <div>
            <button className='add_broker_button' onClick={openAddDialog}>Add broker</button>
            <dialog open={openAdd} className='add_broker_dialog'>
                <p>Add Broker</p>
                <form>
                    <input className='dialog_input' type="text" placeholder="Введите имя" onChange={changeName}/>
                    <input className='dialog_input' type="number" placeholder="Введите баланс" onChange={changeAccount}/>
                    <button className='confirm_button' type="submit" onClick={confirmAdd} autoFocus>Добавить</button>
                </form>
            </dialog>
        </div>
    )
}

export default BrokersComponent;