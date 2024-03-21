import {createStore} from 'vuex'


export default createStore({
    state() {
        return {
            tradingList: [],
            index: 0,
        }
    },
    mutations: {
        setTradingList(state, list){
            state.tradingList = list;
        },

        setIndex(state, newIndex) {
            state.index = newIndex;
        },
    }
})