import {createStore} from 'vuex'


export default createStore({
    state() {
        return {
            tradingList: [],
        }
    },
    mutations: {
        setTradingList(state, list){
            state.tradingList = list
        }
    }
})