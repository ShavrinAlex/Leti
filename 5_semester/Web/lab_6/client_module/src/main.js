import { createApp } from 'vue'
import io from "socket.io-client";
import VueSocketIO from 'vue-socket.io';
//import Echarts from 'vue-echarts';
import App from './App.vue'
import router from './Router'
import store from './Store'


export const SocketInstance = io('http://localhost:8081/');

const app = createApp(App)
    .use(store)
    .use(router, VueSocketIO, SocketInstance)
    //.component('chart', Echarts)

app.config.globalProperties.$socket = SocketInstance;
app.mount('#app')