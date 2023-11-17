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

  getStocks(): string {
    return JSON.stringify(STOCKS);
  }
  /*
  getBrokers(params: any): string {
    let elems = JSON.parse(JSON.stringify(BROKERS));
    let broker = "bad"

    const el = elems.filter((el: any)=>{
      if(el.id === params.id)
        return true;
    });

    console.log(el)
    return "not ok"
  }
  */
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
}