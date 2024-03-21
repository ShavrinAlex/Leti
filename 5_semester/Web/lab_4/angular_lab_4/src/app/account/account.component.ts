import { Component } from '@angular/core';
import { ActivatedRoute } from "@angular/router";
import { Router } from '@angular/router';
import { AppService } from '../app-service.component';


@Component({
  selector: 'app-root',
  templateUrl: './account.component.html',
  styleUrls: ['./account.component.less'],
})
export class AccountComponent {
  user_id: number = -1;

  constructor (private route: ActivatedRoute, private router: Router, private app_service: AppService) {
    this.user_id = this.app_service.user_id
    //this.user_id = route.snapshot.params["id"]
    console.log('init account', this.user_id)
    //this.showComponent('./user_page');
  }

  showComponent(path: string){
    this.router.navigate([path], {relativeTo: this.route, queryParams: {'user_id': this.user_id}});
  }

  quit(){
    this.router.navigate(['/authorization']);
    sessionStorage["social_network.user_id"] = 0;
  }
}