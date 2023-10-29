import { Injectable } from "@angular/core";
import { HttpClient, HttpHeaders, HttpParams } from "@angular/common/http";
import { Router } from "@angular/router";

@Injectable()
export class AppService {
    user_id: number = sessionStorage["social_network.user_id"];
    user: any;
    friends: any;
    news: any;
    dialogs: any;
    messages: any;

    constructor (private http: HttpClient, private router: Router) {
        console.log("counstructor app service")
        this.getAccountData()
    }

    getAccountData(): void {
        const headers = new HttpHeaders();
        const params = new HttpParams()
            .set("id", this.user_id)

        this.http.get<any>("http://localhost:8080/account", { headers: headers, params: params })
        .subscribe(value => {
          switch (value.state){
            case "success": 
              this.user = value.data.user;
              this.friends = value.data.friends;
              this.news = value.data.news;
              this.dialogs = value.data.dialogs;
              this.messages = value.data.messages;
              console.log(this.user, this.friends, this.news, this.dialogs, this.messages)
              console.log("get account data app service")
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

    registration(user_id: number): void {
      this.user_id = user_id;
      this.getAccountData();
      console.log("registration", this.user_id, this.user, this.friends, this.news, this.dialogs, this.messages)
      this.router.navigate(['/account']);
    }

    getUserPageData() {
      
      console.log("get page", this.user, this.news)
      return {
        "user": this.user,
        "news": this.news?.filter((news: any) => {return news.user_id == this.user_id})
      }
    }
}