
<template>
    <div v-if="brokers && stocks" class="Brokers">
        <div class="Navigation">
            <ins class="Link" v-on:click="goBack">back</ins>
        </div>
        <div v-for="broker in brokers" v-bind:key = broker.id class="BrokerCard">
            <div class="MainInfo">{{broker.name}}:{{broker.account}}$</div>
            <div v-for="stock in broker.stocks" v-bind:key = stock.id class="BrokerStock">
                <div class="StockInfo">Name: {{stock.name}}</div>
                <div class="StockInfo">Amount: {{stock.amount}}</div>
                <div class="StockInfo">Разница: {{ (stock.sum - getPriceByStockId(stock.id, currentIndex) * stock.amount)*-1 }}</div>
            </div>
        </div>
    </div>
  
  </template>


<script>
import router from "@/Router"
import axios from "axios";


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
        .then(response => (this.brokers = response.data/*, this.$store.commit("setBrokers", response.data)*/))
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
  methods: {
    goBack() {
        router.go(-1)
    }
  }
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
    }

    .MainInfo {
        font-size: 24px;
    }
</style>