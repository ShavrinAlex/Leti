import { Component} from '@angular/core';
import { HttpClient, HttpHeaders, HttpParams } from "@angular/common/http";
import { ActivatedRoute } from '@angular/router';


@Component({
  selector: 'child-root',
  templateUrl: './user_page.component.html',
  styleUrls: ['./user_page.component.less']
})
export class UserPageComponent {
  user_id: number = -1;

  constructor (private route: ActivatedRoute, private http: HttpClient){
    this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    console.log('user_page', this.user_id)

    const headers = new HttpHeaders();

    this.http.get<any>("http://localhost:8080/account/:id/user_page", { headers: headers })
      .subscribe(value => {
        switch (value.state){
          case "success": 
            console.log(value.state, value.user_id)
            break
          case "error":
            console.log(value.state)
            break
        }
      },
      error => {
        console.log(error)
      })
  }
}