import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { AccountComponent } from './account.component';
import { NewsComponent } from './news/news.component';
import { FriendsComponent } from './friends/friends.component';
import { MessagesComponent } from './messages/messages.component';
import { UserPageComponent } from './user_page/user_page.component';
import { DialogComponent } from './dialog/dialog.component';


const authorizationRoutes: Routes = [
    {
        path: '',
        component: AccountComponent,
        children: [
            { path: 'user_page', component: UserPageComponent},
            { path: 'news', component: NewsComponent },
            { path: 'friends', component: FriendsComponent },
            { path: 'messages', component: MessagesComponent },
            { path: 'dialog', component: DialogComponent }
        ]
    }

];

@NgModule({
    imports: [RouterModule.forChild(authorizationRoutes)],
    exports: [RouterModule],
})
export class AccountRoutingModule { }
