import {Body, Controller, Delete, Get, Param, Post, Put, Query} from '@nestjs/common';
import { AppService } from './app.service';


@Controller()
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get("/getAllBrokers")
  getAllBrokers(): string {
    //console.log(this.appService.getAllBrokers())
    return this.appService.getAllBrokers();
  }

  @Get("/getBroker")
  getBrokers(@Query() params: any): string {
    return this.appService.getBroker(params);
  }

  @Get("/getStocks")
  getStocks(): string {
    //console.log(this.appService.getStocks())
    return this.appService.getStocks();
  }

  @Post("/addBroker")
  addBroker(@Body() body: any): string {
    //console.log('ADD ')
    return this.appService.addBroker(body);
  }

  @Put("/changeBroker/:id")
  changeBroker(@Param() { id }: any, @Body() body: any): string {
    return this.appService.changeBroker(id, body);
  }

  @Delete("/deleteBroker/:id")
  deleteBroker(@Param() { id }: any): string {
    return this.appService.deleteBroker(id);
  }

  @Post("/buyStock")
  buyStock(@Body() body: any): string {
    return this.appService.buyStock(body);
  }
  
  @Post("/sellStock")
  sellStock(@Body() body: any): string {
    return this.appService.sellStock(body);
  }
}