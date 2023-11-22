<template>
    <div class="ComponentContainer">
        <div class="Navigation">
            <router-link class="Link" to="/admin">admin</router-link>
            <router-link class="Link" to="/login">exit</router-link>
        </div>
        <div v-if="broker" class="BrokerInfo">
            <div class="BrokerName">Broker: {{ broker.name }}</div>
            <div class="BrokerAccount">Account: {{ broker.account }}$</div>
            <div v-if="stocks" class="Date">Date: {{ stocks[0].data[stocks[0]?.data.length-1-this.$store.state.index]?.Date }}</div>
            <div v-else class="Date">Date: {{ new Date().toLocaleDateString("en-US") }}</div>
        </div>
        <div v-if="broker && stocks" class="Stocks">
            <div v-for="stock in stocks" v-bind:key="stock.id" class="Stock">
                <div class="StockCard">
                    <div v-if="this.$store.state.tradingList.includes(stock.id)">
                        <div class="FirstColumn" @click="toggleGraphic(stock.id)">
                            <div class="StockName">{{ stock.name }}</div>
                            <div class="MainStockInfo">
                                <div class="Count">0</div>
                                <div class="Price">{{stock.data[stock.data.length-1-this.$store.state.index]?.Open}}$</div>
                            </div>
                        </div>
                    </div>
                    <div v-if="tradingList.includes(stock.id)">
                        <button class="BuyButton">buy</button>
                    </div>
                    <div v-if="tradingList.includes(stock.id)">
                        <button class="SellButton">sell</button>
                    </div>
                    <div v-if="tradingList.includes(stock.id)">
                        <div class="LastColumn">
                            <div class="TotalCost">0</div>
                            <div class="Difference">+0.0$</div>
                        </div>
                    </div>
                </div>
                <div v-if="graphichs[stock.id]" class="Graphic">
                    <Line
                        id="chart"
                        :options="{
                            responsive: true,
                            height:1000,
                            plugins: {
                                title: {
                                    display: true,
                                    text: stock.id,
                                },
                            },
                        }"
                        :data="{
                            title: stock.id,
                            labels: stock.data.map((data) => data.Date).slice(stock.data.length-1-this.$store.state.index, stock.data.length-1).reverse(),
                            datasets: [{
                                data: stock.data.map((data) =>data.Open.match(/(\d+)/)[0]).slice(stock.data.length-1-this.$store.state.index, stock.data.length-1).reverse(),
                                borderColor: 'rgb(75, 192, 192)',
                                label: 'price',
                            }]
                        }"
                    />
                    </div>
            </div>
        </div>
    </div>
</template>

<script>
import axios from 'axios'
import {mapState} from "vuex";
import {Line} from 'vue-chartjs'
import {
    Chart as ChartJS,
    CategoryScale,
    LinearScale,
    PointElement,
    LineElement,
    Title,
    Tooltip,
    Legend
} from 'chart.js'
ChartJS.register(Title, Tooltip, Legend, LineElement, CategoryScale, LinearScale, PointElement)

const BROKER_URL = 'http://localhost:8081/getBroker/?name='
const STOCKS_URL = 'http://localhost:8081/getStocks'

export default {
    name: 'BrokerComponent',
    components: {Line},

    data() {
        return {
            stocks: null,
            broker: null,
            graphichs: {}
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
            .then(response => {
                this.stocks = response.data;
                this.stocks.forEach((stock)=>{
                    this.graphichs[stock.id] = false;
                })
                console.log(this.graphichs)
            })
            .catch(error => {
                this.errorMessage = error.message;
                console.error("There was an error!", error);
            });
    },

    mounted() {
        this.$socket.on("trading", (data) => {
            this.$store.commit("setIndex", JSON.parse(data))
        })
        this.$socket.on("trading_list", (data) => {
            this.$store.commit("setTradingList", JSON.parse(data).listTradings)
            /*
            let new_stocks = []
            JSON.parse(data).listTradings.forEach((stock_id)=>{
                new_stocks.push(this.stocks.filter((st)=>{return st.id === stock_id})[0])
            })
            this.stocks = new_stocks;
            */
        })
    },

    computed: {
        ...mapState(["tradingList"]),
    },

    methods: {
        toggleGraphic(stock_id) {
            //console.log('toggle', stock_id)
            this.graphichs[stock_id] = !this.graphichs[stock_id]
            //console.log(this.graphichs)
        }
       
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
        background-color: #fff;
        border-radius: 30px;
        margin-bottom: 70px;
        padding: 10px 0px 10px 0px;
    }

    .Stocks {
        width: 100%;
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: space-around;
    }

    .Stock {
        width: 90%;
    }

    .StockCard {
        width: 100%;
        display: grid;
        grid-template-columns: repeat(4, 25%);
        background-color: #fdfcfc;
        border-radius: 30px;
        margin-bottom: 30px;
    }

    .FirstColumn {
        min-height: 70px;
        width: 100%;
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: space-around;
        cursor: pointer;
    }

    .Graphic {
        margin-bottom: 30px;
    }

    .StockName {
        font-size: 30px;
        font-weight: bold;
    }

    .MainStockInfo {
        width: 100%;
        display: flex;
        flex-direction: row;
        align-items: center;
        justify-content: space-around;
    }

    .BuyButton {
        
    }

    .LastColumn {
        height: 100%;
        width: 100%;
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: space-around;
    }

    .TotalCost {
        font-size: 24px;
        font-weight: bolder;
    }

</style>