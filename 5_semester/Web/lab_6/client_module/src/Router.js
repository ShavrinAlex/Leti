import { createRouter, createWebHashHistory } from 'vue-router'
import LoginComponent from './components/LoginComponent.vue'
import AdminComponent from './components/AdminComponent.vue'


const routes = [
    { path: '/', redirect: '/login'},
    { path: '/login', name: 'LoginComponent', component: LoginComponent },
    { path: '/broker/:name', name: 'BrokerComponent', component: () => import('../src/components/BrokerComponent.vue') },
    { path: '/admin', name: 'AdminComponent', component: AdminComponent }
]

const router = createRouter({
    history: createWebHashHistory(),
    routes
})

export default router