import { Injectable } from '@nestjs/common';
import BROKERS from "./brokers.json";
import STOCKS from "./stocks.json";
import * as fs from 'fs';


@Injectable()
export class AppService {
  getAllBrokers(): string {
    //console.log("brokers", BROKERS)
    return JSON.stringify(BROKERS);
  }

  getBroker(params: any): string {
    const broker = BROKERS.filter((broker)=>{
      if(broker.name === params.name)
        return true;
    })[0];

    return JSON.stringify(broker);
  }

  getStocks(): string {
    return JSON.stringify(STOCKS);
  }

  addBroker(body: any): string {
    let last_index = BROKERS.length - 1;
    let id = BROKERS[last_index].id + 1;
    body.id = id;

    BROKERS.push(body);

    fs.writeFile('src/brokers.json', JSON.stringify(BROKERS), (err) => {
      if (err) throw err;
      console.log('The file has been saved!');
    });

    return JSON.stringify({ "mes": "success" });
  }

  changeBroker(id: any, body: any): string {
    const index = BROKERS.map((broker: any) => {
      return broker.id;
    }).indexOf(Number(id));

    if (index === -1) {
      return JSON.stringify({ "mes": "fail" });
    } else {
      BROKERS[index].account = parseInt(body.account);

      fs.writeFile('./brokers.json', JSON.stringify(BROKERS), (err) => {
        if (err) throw err;
        console.log('The file has been saved!');
      });

      return JSON.stringify({ "mes": "success" });
    }
  }

  deleteBroker(id: any): string {
    const index = BROKERS.map((broker: any) => {
      return broker.id;
    }).indexOf(Number(id));

    if (index === -1) {
      return JSON.stringify({ "mes": "fail" });
    } else {
      BROKERS.splice(index, 1);

      fs.writeFile('src/brokers.json', JSON.stringify(BROKERS), (err) => {
        if (err) throw err;
        console.log('The file has been saved!');
      });

      return JSON.stringify({ "mes": "success" });
    }
  }

  buyStock(body: any): string {
    const broker = BROKERS.filter((broker)=>{
      return broker.id == body.broker_id;
    })[0];

    const stock = STOCKS.filter((stock) => {
      return stock.id == body.stock_id;
    })[0];
    
    const stock_price = Number(stock?.data[stock?.data?.length-1-body.index]?.Open.slice(1));

    if (broker && stock) {
      let full_price =  body.stock_count * stock_price;
      if (broker.account > full_price){
        if (!broker.stocks[stock.id]) {
          broker.stocks[stock.id] = {"count": 0, "sum": 0};
        }
        broker.stocks[stock.id].count += body.stock_count;
        broker.stocks[stock.id].sum += full_price;
        broker.account -= full_price;

        fs.writeFile('src/brokers.json', JSON.stringify(BROKERS), (err) => {
          if (err) throw err;
          console.log('The file has been saved!');
        });

        return JSON.stringify({ "mes": "success", "data": broker});
      } else {
        return JSON.stringify({ "mes": "insufficient funds" });
      }
    } else {
      return JSON.stringify({ "mes": "unknown broker" });
    }
  }

  sellStock(body: any): string {
    const broker = BROKERS.filter((broker)=>{
      return broker.id == body.broker_id;
    })[0];

    const stock = STOCKS.filter((stock) => {
      return stock.id == body.stock_id;
    })[0];
    
    const stock_price = Number(stock?.data[stock?.data?.length-1-body.index]?.Open.slice(1));

    if (broker && stock) {
      let full_price =  body.stock_count * stock_price;
      const average_sum = (broker.stocks[stock.id].sum / broker.stocks[stock.id].count) * body.stock_count;

      if (broker.stocks[stock.id]?.count >= body.stock_count){
        broker.stocks[stock.id].count -= body.stock_count;
        broker.stocks[stock.id].sum -= average_sum ;
        broker.account += full_price;

        fs.writeFile('src/brokers.json', JSON.stringify(BROKERS), (err) => {
          if (err) throw err;
          console.log('The file has been saved!');
        });

        return JSON.stringify({ "mes": "success", "data": broker});
      } else {
        return JSON.stringify({ "mes": "not enough shares" });
      }
    } else {
      return JSON.stringify({ "mes": "unknown broker" });
    }
  }
}