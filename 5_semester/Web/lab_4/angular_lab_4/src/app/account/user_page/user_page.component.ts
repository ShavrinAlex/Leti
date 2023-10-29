import { Component} from '@angular/core';
import { HttpClient, HttpHeaders, HttpParams } from "@angular/common/http";
import { ActivatedRoute } from '@angular/router';
import { AppService } from 'src/app/app-service.component';


@Component({
  selector: 'child-root',
  templateUrl: './user_page.component.html',
  styleUrls: ['./user_page.component.less']
})
export class UserPageComponent {
  user_id: number = -1;
  user: any;
  user_news: any;
  

  constructor (private route: ActivatedRoute, private http: HttpClient, private app_service: AppService){
    //this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    this.user_id = this.app_service.user_id;
    console.log('user_page', this.user_id);

    const headers = new HttpHeaders();

    const params = new HttpParams()
      .set('id', this.user_id);
    /*
    const data = this.app_service.getUserPageData();
    this.user = data.user;
    this.user_news = data.news;*/

    this.http.get<any>("http://localhost:8080/account/user_page", { headers: headers, params: params })
      .subscribe(value => {
        switch (value.state){
          case "success": 
            this.user = value.user;
            this.user_news = value.news;
            console.log(value.state, this.user, this.user_news)
            break
          case "unknown user":
            console.log(value.state)
            break
        }
      },
      error => {
        console.log(error)
      })
  }

  goToAdminModule() {
    window.location.href = "http://localhost:8080/admin_module/users"
  }
}