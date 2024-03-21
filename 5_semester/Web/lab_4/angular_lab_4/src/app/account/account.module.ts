import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { HttpClientModule } from '@angular/common/http';

import { AccountRoutingModule } from './account-routing.module';
import { AccountComponent } from './account.component';
import { FriendsComponent } from './friends/friends.component';
import { UserPageComponent } from './user_page/user_page.component';
import { NewsComponent } from './news/news.component';
import { DialogComponent } from './dialog/dialog.component';
import { MessagesComponent } from './messages/messages.component';

@NgModule({
    imports: [CommonModule, AccountRoutingModule, HttpClientModule],
    declarations: [AccountComponent, UserPageComponent, FriendsComponent, NewsComponent, MessagesComponent, DialogComponent ],
    providers: [],
    bootstrap: [AccountComponent]
})
export class AccountModule { 

}