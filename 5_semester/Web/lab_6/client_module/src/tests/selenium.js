const {Builder, By, Key, until, } = require('selenium-webdriver');


async function test_1() {
    let driver = await new Builder().forBrowser('chrome').build();
    try {
        await driver.get('http://localhost:8080/#/broker/Alex');
        let price = null;
        let start_account = null;
        let end_account = null;
        
        setTimeout(async () => {
            start_account = await driver.findElement(By.xpath("//div[@id='BrokerAccount']")).getText()
            start_account = Number(start_account.slice(9, start_account.length-1))
            console.log('start')
        }, 3000)
        
        setTimeout(async () => {
            await driver.findElement(By.xpath("//button[@id='APPL_buy_btn']")).click()
            console.log("buy")
        }, 4000)

        setTimeout(async () => {
            await driver.findElement(By.xpath("//input[@id='APPL_buy_inp']")).sendKeys(1)
            console.log("inp")
        }, 5000)
        
        setTimeout(async () => {
            await driver.findElement(By.xpath("//button[@id='APPL_buy_confirm_btn']")).click()
            price = await driver.findElement(By.xpath("//div[@id='APPL_price']")).getText()
            price = Number(price.slice(0, price.length-1))
            console.log('confirm', price)
        }, 6000)

        setTimeout(async () => {
            end_account = await driver.findElement(By.xpath("//div[@id='BrokerAccount']")).getText()
            end_account = Number(end_account.slice(9, end_account.length-1))
            console.log(start_account)
            console.log(price)
            console.log(end_account)

            console.log(parseFloat(start_account - price), " vs ", parseFloat(end_account))
            if(parseFloat(end_account)===(parseFloat(start_account)-parseFloat(price))){
                console.log("balance right")
            }
        }, 10000)
    } finally {
        //await driver.quit();
    }
};

async function test_2() {
    let driver = await new Builder().forBrowser('chrome').build();
    try {
        await driver.get('http://localhost:8080/#/broker/Alex');
        let price = null;
        let start_account = null;
        let end_account = null;
        
        setTimeout(async () => {
            start_account = await driver.findElement(By.xpath("//div[@id='BrokerAccount']")).getText()
            start_account = Number(start_account.slice(9, start_account.length-1))
            console.log('start')
        }, 3000)
        
        setTimeout(async () => {
            await driver.findElement(By.xpath("//button[@id='APPL_sell_btn']")).click()
            console.log("sell")
        }, 4000)

        setTimeout(async () => {
            await driver.findElement(By.xpath("//input[@id='APPL_sell_inp']")).sendKeys(1)
            console.log("inp")
        }, 5000)
        
        setTimeout(async () => {
            await driver.findElement(By.xpath("//button[@id='APPL_sell_confirm_btn']")).click()
            price = await driver.findElement(By.xpath("//div[@id='APPL_price']")).getText()
            price = Number(price.slice(0, price.length-1))
            console.log('confirm', price)
        }, 6000)

        setTimeout(async () => {
            end_account = await driver.findElement(By.xpath("//div[@id='BrokerAccount']")).getText()
            end_account = Number(end_account.slice(9, end_account.length-1))
            console.log(start_account)
            console.log(price)
            console.log(end_account)

            console.log((start_account + price).toFixed(3), " vs ", (end_account).toFixed(3))
            if((end_account).toFixed(3)===(start_account+price).toFixed(3)){
                console.log("balance right")
            }
        }, 10000)
    } finally {
        //await driver.quit();
    }
};

test_1()
setTimeout(()=>{
    test_2()
}, 11000)
