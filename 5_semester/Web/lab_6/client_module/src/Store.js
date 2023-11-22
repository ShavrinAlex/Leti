import {createStore} from 'vuex'


export default createStore({
    state() {
        return {
            tradingList: [],
            start_index: 0,
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