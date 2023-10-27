import { Component } from '@angular/core';
import { ActivatedRoute } from "@angular/router";
import { Router } from '@angular/router';


@Component({
  selector: 'app-root',
  templateUrl: './account.component.html',
  styleUrls: ['./account.component.less']
})
export class AccountComponent {
  user_id: number;
  constructor (private route: ActivatedRoute, private router: Router) {
    this.user_id = route.snapshot.params["id"]
    console.log('constr account', this.user_id, typeof(this.user_id))
    this.showComponent('./user_page');
  }

  showComponent(path: string){
    this.router.navigate([path], {relativeTo: this.route, queryParams: {'user_id': this.user_id}});
  }

  quit(){
    this.router.navigate(['/authorization']);
  }
}