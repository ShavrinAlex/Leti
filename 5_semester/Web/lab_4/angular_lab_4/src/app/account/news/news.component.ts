import { Component } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { HttpClient, HttpHeaders, HttpParams } from "@angular/common/http";
import { SocketIoService } from 'src/app/socket-io.service';


@Component({
  selector: 'child-root',
  templateUrl: './news.component.html',
  styleUrls: ['./news.component.less']
})
export class NewsComponent { 
  user_id: number = -1;
  news: any; 
  news_owners: any; 


  constructor (private route: ActivatedRoute, private http: HttpClient, private socket_service: SocketIoService){
    this.socket_service.listenToServer('news').subscribe((news) => {
      this.updateNews(news)
    })

    this.route.queryParams.subscribe(param => {this.user_id = param["user_id"]})
    console.log('news', this.user_id)

    const headers = new HttpHeaders();

    const params = new HttpParams()
      .set('id', this.user_id);

    this.http.get<any>("http://localhost:8080/account/news", { headers: headers, params: params })
      .subscribe(value => {
        switch (value.state){
          case "success": 
            this.news = value.news;
            this.news_owners = value.news_owners
            console.log(value.state, this.news, this.news_owners)
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

  getNewsOwnerParam(user_id: number, param: string): string {
    let answer: string = ''
    this.news_owners.forEach((owner: any) => {
      if (owner.id == user_id) {
        answer = owner[param];
      } 
    })
    return answer
  }

  updateNews(news: any): void {
    console.log('get ', news)
    this.news_owners.forEach((owner: any) => {
      if (owner.id == news.user_id) {
        this.news.unshift(news);
        console.log('push ',  news)
      }
    })
  }

  createNews(NewsInput: any) {
    let news_data = NewsInput.value;
    NewsInput.value = '';
    let news = {
      'news_id': -1,
      'user_id': Number(this.user_id),
      'data': news_data,
      'time_create': new Date()
    }
    console.log('create ', news);
    this.socket_service.emitToServer('news', news);
  }
}