import { Component } from '@angular/core';
import { HttpClient } from "@angular/common/http";
import { Router } from '@angular/router';

@Component({
  selector: 'app-root',
  templateUrl: './signup.component.html',
  styleUrls: ['./signup.component.less']
})
export class SignupComponent {
  username: string = '';
  email: string = '';
  birth: string = '';
  password: string = '';
  constructor(private http: HttpClient, private router: Router) { }

  onSignUp(): void {
    const body = {
      'username': this.username,
      'email': this.email,
      'birth': this.birth,
      'password': this.password
    };

    this.http.post<any>("http://localhost:8080/authorization/signup", body)
      .subscribe(value => {
        switch (value.state){
          case "success": 
            console.log(value.state, value.user_id);
            this.router.navigate(['/account', `${value.user_id}`]);
            break
          case "user is exists":
            console.log(value.state);
            break
        }
      },
      error => {
        console.log(error)
      })
  }
}