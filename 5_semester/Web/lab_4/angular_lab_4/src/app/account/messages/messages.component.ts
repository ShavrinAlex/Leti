import { Component } from '@angular/core';
import { ActivatedRoute } from '@angular/router';


@Component({
  selector: 'child-root',
  templateUrl: './messages.component.html',
  styleUrls: ['./messages.component.less']
})
export class MessagesComponent { 
  user_id: number = -1;

  constructor (private route: ActivatedRoute){
    this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    console.log('messages', this.user_id)
  }
}