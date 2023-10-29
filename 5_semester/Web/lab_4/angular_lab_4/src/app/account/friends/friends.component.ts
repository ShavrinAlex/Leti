import { Component } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { HttpClient, HttpHeaders, HttpParams } from "@angular/common/http";
import { SocketIoService } from 'src/app/socket-io.service';


@Component({
  selector: 'child-root',
  templateUrl: './friends.component.html',
  styleUrls: ['./friends.component.less']
})
export class FriendsComponent { 
  user_id: number = -1;
  user_friends: any;
  // = [{'id': this.user_id, 'name': '', 'avatar': '', 'birth_date': '', 'email': '', 'role': '', 'status': ''}];

  constructor (private route: ActivatedRoute, private http: HttpClient, private router: Router, private socket_service: SocketIoService){
    this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    console.log('friends', this.user_id)

    const headers = new HttpHeaders();

    const params = new HttpParams()
      .set('id', this.user_id);

    this.http.get<any>("http://localhost:8080/account/friends", { headers: headers, params: params })
      .subscribe(value => {
        switch (value.state){
          case "success": 
            this.user_friends = value.user_friends;
            console.log(value.state, value.user_friends)
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

  goToDialog(friend_id: string): void {
    let dialog_id: number = -1;
    const headers = new HttpHeaders();

    const params = new HttpParams()
      .set('user_id', this.user_id)
      .set('friend_id', Number(friend_id));

    this.http.get<any>("http://localhost:8080/account/friends/go_to_dialog", { headers: headers, params: params })
      .subscribe(value => {
        switch (value.state){
          case "success": 
            this.socket_service.emitToServer('dialog', {'dialog': value.dialog, 'companions': value.companions})
            this.router.navigate(['./dialog'], {relativeTo: this.route.parent, queryParams: {'user_id': this.user_id, 'dialog_id': value.dialog.id}});
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