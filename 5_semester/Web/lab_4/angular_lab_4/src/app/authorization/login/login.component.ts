import { Component } from '@angular/core';
import { HttpClient, HttpHeaders, HttpParams } from "@angular/common/http";
import { Router } from '@angular/router';
import { AppService } from 'src/app/app-service.component';


@Component({
  selector: 'app-root',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.less']
})
export class LoginComponent {
  email: string = '';
  password: string = '';
  server_answer: string = '';

  constructor(private http: HttpClient, private router: Router, private app_servise: AppService) { }

  onLogIn(): void {
    const headers = new HttpHeaders();

    const params = new HttpParams()
      .set('email', this.email)
      .set('password', this.password);

    this.http.get<any>("http://localhost:8080/authorization/login", { headers: headers , params: params})
      .subscribe(value => {
        this.server_answer = value.state;
        switch (value.state){
          case "correct": 
            console.log(value.state, value.user_id)
            sessionStorage["social_network.user_id"] = value.user_id
            this.app_servise.registration(value.user_id)
            break
          case "wrong password":
            console.log(value.state)
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
}