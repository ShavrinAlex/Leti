import { Component } from '@angular/core';
import { ActivatedRoute } from '@angular/router';


@Component({
  selector: 'child-root',
  templateUrl: './dialog.component.html',
  styleUrls: ['./dialog.component.less']
})
export class DialogComponent { 
  user_id: number = -1;

  constructor (private route: ActivatedRoute){
    this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    console.log('dialog', this.user_id)
  }
}