import { Component } from '@angular/core';
import { ActivatedRoute } from '@angular/router';


@Component({
  selector: 'child-root',
  templateUrl: './friends.component.html',
  styleUrls: ['./friends.component.less']
})
export class FriendsComponent { 
  user_id: number = -1;

  constructor (private route: ActivatedRoute){
    this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    console.log('friends', this.user_id)
  }
}