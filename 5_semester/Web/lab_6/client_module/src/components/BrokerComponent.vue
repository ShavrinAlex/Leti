<template>
    <div class="ComponentContainer">
        <div class="Navigation">
            <router-link class="Link" to="/admin">admin</router-link>
            <router-link class="Link" to="/login">exit</router-link>
        </div>
        <div v-if="broker" class="BrokerInfo">
            <div class="BrokerName">Broker: {{ broker.name }}</div>
            <div class="BrokerAccount">Account: {{ broker.account }}$</div>
            <div class="Date">Date: {{ date }}</div>
        </div>
        <div v-if="broker && stocks" class="Stocks">
            <div v-for="stock in stocks" v-bind:key="stock.id">
                <div v-if="tradingList.includes(stock.id)">
                    <div class="StockName">{{ stock.name }}</div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import axios from 'axios'
import {mapState} from "vuex";

const BROKER_URL = 'http://localhost:8081/getBroker/?name='
const STOCKS_URL = 'http://localhost:8081/getStocks'

export default {
    name: 'BrokerComponent',

    data() {
        return {
            stocks: null,
            broker: null,
            date: '01/01/2023'
        };
    },

    created() {
        axios.get(BROKER_URL + this.$route.params.name)
            .then(response => (
                this.broker = response.data
                //this.$store.commit("setBalance", this.broker.balance),
                //this.$store.commit("setUserStocks", this.broker.stocks)
                //console.log(response.data)
            ))
            .catch(error => {
                this.errorMessage = error.message;
                console.error("There was an error!", error);
            });

        axios.get(STOCKS_URL)
            .then(response => (
                this.stocks = response.data
            ))
            .catch(error => {
                this.errorMessage = error.message;
                console.error("There was an error!", error);
            });
    },

    mounted() {
        
        this.$socket.on("trading", (data) => {
            console.log(data);
        })
            //if (this.stocks) {
                //this.$store.commit("change", this.stocks[0].data[data].Date)
           //}
            // /this.$store.commit("changeIndex", data)
       // })
        this.$socket.on("trading_list", (data) => {
            console.log('get emmit voue')
            //console.log(JSON.parse(data).listTradings)
            this.$store.commit("setTradingList", JSON.parse(data).listTradings)
            //this.$store.commit("setStartDate", data.data)
            //this.startIndex = data.startIndex;
            //console.log(this.startIndex)
        })
    },

    computed: {
        ...mapState(["tradingList"]),
    }
}
</script>



<style>
    .ComponentContainer {
        width: 100vw;
        height: 100vh;
        display: flex;
        flex-direction: column;
        align-items: center;
    }

    .Navigation {
        background-color: #023A50;
        border-radius: 0px 0px 10px 10px;
        padding-top: 10px;
        font-size: 24px;
        width: 400px;
        height: 50px;
        margin-bottom: 70px;
    }

    .Link {
        color: white;
        margin: 0px 50px 0px 50px;
    }

    .BrokerInfo {
        display: flex;
        flex-direction: row;
        align-items: center;
        justify-content: space-around;
        font-size: 24px;
        width: 90%;
        height: 100px;
        background-color: #fff;
        border-radius: 30px;
        margin-bottom: 70px;
    }

    .Stocks {
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: space-around;
        background-color: #fff;
        border-radius: 30px;
        width: 90%;
        height: 50vh
    }

</style>