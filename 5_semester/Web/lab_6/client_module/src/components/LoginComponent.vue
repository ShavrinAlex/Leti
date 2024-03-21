<template>
  <div class="LoginComponent">
    <p class="LoginText">Log in</p>
    <img src="login_img.png" alt="image" width="180" height="200">
    <div>
      <input type="text" list="brokers" v-model="selected_broker">
      <datalist id="brokers">
        <option v-for="broker in brokers" v-bind:key = "broker.id" :value="broker.name"></option>
      </datalist>
      <button v-bind:disabled="!selected_broker" v-on:click="login">Login</button>
    </div>
  </div>
</template>




<script>
import router from '@/Router'
import axios from 'axios'

const BROKERS_URL = 'http://localhost:8081/getAllBrokers'

export default {
  name: 'LoginComponent',

  data() {
    return {
      brokers: null,
      selected_broker: undefined
    };
  },

  created(){
    axios.get(BROKERS_URL)
      .then(response => (this.brokers = response.data))
      .catch(error => {
        this.errorMessage = error.message;
        console.error("There was an error!", error);
      });
  },

  methods: {
    login() {
      if(this.selected_broker){
        // check instance
        router.push({ path: `/broker/${this.selected_broker}`})
      }
    }
  }
}
</script>


<style>
  .LoginComponent {
    width: 50vw;
    height: 50vh;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: space-around;
    border: 30px;
    background-color: #023A50;
    border-radius: 50px;
    border: 3px solid #ffffff;
  }

  .LoginText {
    color: #fff;
    font-size: 50px;
    font-weight: bold;
    text-shadow: 0px 0px 10px #000;
  }

  input {
    font-size: 24px;
    border-radius: 10px;
    margin: 10px;
  }

  button {
    font-size: 24px;
    border-radius: 10px;
    margin: 10px;
    padding: 0px 10px 0px 10px;
    background-color: #fff;
    cursor: pointer;
  }

</style>