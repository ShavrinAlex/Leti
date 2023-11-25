<template>
    <div v-if="brokers && stocks" class="Brokers">
        <div class="Navigation">
            <ins class="Link" v-on:click="goBack">back</ins>
        </div>
        <div v-for="broker in brokers" v-bind:key = broker.id class="BrokerCard">
            <div class="MainInfo">{{broker.name}}:{{broker.account.toFixed(3)}}$</div>
            <div v-for="stock in stocks" v-bind:key = stock.id class="BrokerStock">
                <div v-if="broker.stocks[stock.id]?.count">
                  <div class="BrokerStockCard">
                    <div class="StockInfo">Name: {{ stock.name }}</div>
                    <div class="StockInfo">Count: {{ broker.stocks[stock.id].count }}</div>
                    <div class="StockInfo">Difference: {{ getDifference(broker, stock) }}$</div>
                  </div>
                </div>
            </div>
        </div>
    </div>
  
  </template>


<script>
import router from "@/Router"
import axios from "axios";
import {mapState} from "vuex";


const BROKERS_URL = 'http://localhost:8081/getAllBrokers'
const STOCKS_URL = 'http://localhost:8081/getStocks'


export default {
  name: "AdminComponent",

  data() {
    return {
      brokers: null,
      stocks: null
    };
  },

  created(){
    axios.get(BROKERS_URL)
        .then(response => (this.brokers = response.data))
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
    this.$socket.on("broker_buy", (data) => {
          let broker = JSON.parse(data)
            for (let i = 0; i < this.brokers.length; i++) {
              if (this.brokers[i].id == broker.id){
                this.brokers[i] = broker
              }
            }
        })
        this.$socket.on("broker_sell", (data) => {
            let broker = JSON.parse(data)
            for (let i = 0; i < this.brokers.length; i++) {
              if (this.brokers[i].id == broker.id){
                this.brokers[i] = broker
              }
            }
        })
    },

  methods: {
    goBack() {
        router.go(-1)
    },

    getDifference(broker, stock) {
            let difference = (Number(stock.data[stock.data?.length-1-this.$store.state.index]?.Open.slice(1)) * broker.stocks[stock.id]?.count
                    - broker.stocks[stock.id]?.sum).toFixed(3)
            return !isNaN(difference) ? difference : 0
        }
  },

  computed: {
        ...mapState(["tradingList"]),
        ...mapState(["index"]),
    },
}

</script>


<style>
    .Brokers {
        width: 100vw;
        min-height: 100vh;
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: top;
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
        cursor: pointer;
    }

    .BrokerCard {
        width: 90%;
        display: flex;
        flex-direction: column;
        align-items: center;
        background-color: #fff;
        margin-bottom: 30px;
        border: 3px solid #054e6b;
        border-radius: 20px;
    }

    .MainInfo {
      width: 99%;
      font-size: 24px;
      border-bottom: 3px solid #054e6b;
    }

    .BrokerStock {
      width: 100%;
    }

    .BrokerStockCard {
      width: 95%;
      display: grid;
      grid-template-columns: repeat(3, 33%);
      margin: 10px 0px 10px 0px;
      border-bottom: 1px solid #2c3e50;
    }
</style>