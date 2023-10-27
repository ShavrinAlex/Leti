import { Component } from '@angular/core';
import { ActivatedRoute } from '@angular/router';


@Component({
  selector: 'child-root',
  templateUrl: './news.component.html',
  styleUrls: ['./news.component.less']
})
export class NewsComponent { 
  user_id: number = -1;

  constructor (private route: ActivatedRoute){
    this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    console.log('news', this.user_id)
  }
}