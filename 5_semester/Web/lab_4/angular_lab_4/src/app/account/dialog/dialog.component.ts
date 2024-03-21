import { HttpClient, HttpHeaders, HttpParams } from '@angular/common/http';
import { Component } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { SocketIoService } from 'src/app/socket-io.service';


@Component({
  selector: 'child-root',
  templateUrl: './dialog.component.html',
  styleUrls: ['./dialog.component.less']
})
export class DialogComponent { 
  user_id: number = -1;
  dialog_id: number = -1;
  companions: any;
  messages: any;

  constructor (private route: ActivatedRoute, private http: HttpClient, private router: Router, private socket_service: SocketIoService){
    this.socket_service.listenToServer('message').subscribe((data) => {
      this.updateDialog(data)
    })

    this.route.queryParams.subscribe(param => {
      this.user_id = param["user_id"];
      this.dialog_id = param["dialog_id"]
    })
    console.log('dialog', this.user_id, this.dialog_id)

    const headers = new HttpHeaders();

    const params = new HttpParams()
      .set('dialog_id', this.dialog_id)

    this.http.get<any>("http://localhost:8080/account/dialog", { headers: headers, params: params })
      .subscribe(value => {
        switch (value.state){
          case "success": 
            this.messages = value.messages;
            this.companions = value.companions;
            break
          case "unknown user":
            console.log(value.state)
            break
        }
        console.log(value.state, this.messages, this.companions, this.companions)
      },
      error => {
        console.log(error)
      })
  }

  getCompanionId(first_user_id: number, second_user_id: number) {
    return (first_user_id == this.user_id) ? second_user_id : first_user_id;
  }

  getCompanionParam(param: string) {
    let answer = ''
    this.companions.forEach((companion: any) => {
      if (companion.id != this.user_id){
        answer = companion[param]
      }
    })
    return answer
  }

  goBack() {
    this.router.navigate(['./messages'], {relativeTo: this.route.parent, queryParams: {'user_id': this.user_id}})
  }

  updateDialog(data: any): void {
    console.log('get ', data)
    if (data.dialog_id ==  this.dialog_id) {
      this.messages.push(data.message)
    }
  }

  sendMessage(MessageInput: any): void {
    let message_data = MessageInput.value;
    MessageInput.value = ''
    let message = {
      "id": -1,
      "sender_user_id": Number(this.user_id),
      "time_create": new Date(),
      "data": message_data
    }
    const data = {
      "message": message,
      "dialog_id": this.dialog_id
    }

    this.socket_service.emitToServer('message', data);
  }
}