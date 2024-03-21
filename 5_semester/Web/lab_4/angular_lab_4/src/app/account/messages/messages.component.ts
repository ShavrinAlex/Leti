import { Component } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { HttpClient, HttpHeaders, HttpParams } from "@angular/common/http";
import { SocketIoService } from 'src/app/socket-io.service';


@Component({
  selector: 'child-root',
  templateUrl: './messages.component.html',
  styleUrls: ['./messages.component.less']
})
export class MessagesComponent { 
  user_id: number = -1;
  dialogs: any;
  companions: any;
  last_messages: any;

  constructor (private route: ActivatedRoute, private http: HttpClient, private router: Router, private socket_service: SocketIoService){
    this.socket_service.listenToServer('message').subscribe((data) => {
      this.updateMessageCard(data)
    })
    this.socket_service.listenToServer('dialog').subscribe((data) => {
      this.updateDialogsList(data)
    })

    this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    console.log('messages', this.user_id)

    this.httpRequest()
  }

  httpRequest(): void {
    const headers = new HttpHeaders();

    const params = new HttpParams()
      .set('id', this.user_id);

    this.http.get<any>("http://localhost:8080/account/messages", { headers: headers, params: params })
      .subscribe(value => {
        switch (value.state){
          case "success": 
            this.dialogs = value.dialogs;
            this.companions = value.companions;
            this.last_messages = value.last_messages;
            break
          case "unknown user":
            console.log(value.state)
            break
        }this.http.get<any>("http://localhost:8080/account/messages", { headers: headers, params: params })
        .subscribe(value => {
          switch (value.state){
            case "success": 
              this.dialogs = value.dialogs;
              this.companions = value.companions;
              this.last_messages = value.last_messages;
              break
            case "unknown user":
              console.log(value.state)
              break
          }
          console.log(value.state, this.dialogs, this.companions, this.last_messages)
        },
        error => {
          console.log(error)
        })
        console.log(value.state, this.dialogs, this.companions, this.last_messages)
      },
      error => {
        console.log(error)
      })
  }

  getCompanionId(first_user_id: number, second_user_id: number) {
    return (first_user_id == this.user_id) ? second_user_id : first_user_id;
  }

  getDialogCompanionParam(first_user_id: number, second_user_id: number, param: string): string {
    let answer: string = '';
    let companion_id = this.getCompanionId(first_user_id, second_user_id);
    this.companions.forEach((companion: any) => {
      if (companion.id == companion_id) {
        answer = companion[param]
      } 
    })
    console.log(this.companions, companion_id)
    return answer
  }

  getLastMessageParam(last_message_id: number, param: string) {
    const last_message = this.last_messages.filter((message: any) => {
      return message.id == last_message_id
    })[0]
    let answer = '' 
    if (last_message != undefined){
      answer = last_message[param]
    }
    return answer
  }

  getLastMessageUserParam(last_message_id: number, param: string){
    const last_message = this.last_messages.filter((message: any) => {
      return message.id == last_message_id
    })[0]

    let answer = ''
    if (last_message != undefined) {
      const user = this.companions.filter((user: any) => {
        return user.id == last_message.sender_user_id
      })[0]
      answer = user[param]
    }
    
    return answer
  }
/*
  isCompanionLastMessage(last_message_id: number) {
    const last_message = this.last_messages.filter((message: any) => {
      return message.id == last_message_id
    })[0]
    console.log(this.user_id, last_message.sender_user_id, this.user_id != last_message.sender_user_id)
    return (this.user_id != last_message.sender_user_id)
  }
*/
  goToDialog(path: string, dialog_id: number) {
    console.log('go to ', path, dialog_id)
    
    this.router.navigate([path], {relativeTo: this.route.parent, queryParams: {'user_id': this.user_id, 'dialog_id': dialog_id}});
  }

  updateMessageCard(data: any): void {
    console.log('get ', data)
    let dialog = this.dialogs.filter((dialog: any) => {
      return dialog.id == data.dialog_id
    })[0]

    if (dialog !== undefined) {
      let last_message_id = dialog.messages[dialog.messages.length - 1]
      dialog.messages.push(data.message.id)

      for (let i in this.last_messages){
        if (this.last_messages[i].id == last_message_id){
          this.last_messages[i] = data.message
        }
      }
    }
  }

  updateDialogsList(data: any): void {
    if (this.user_id == data.dialog.first_user_id || this.user_id == data.dialog.second_user_id) {
      let check_dialog = this.dialogs.filter((dialog: any) => {
        return dialog.id == data.dialog.id
      })[0]
      if (check_dialog == undefined){
        this.httpRequest()
        //this.dialogs.push(data.dialog)
        //this.companions.push(data.companions)
      }
    }
  }
}