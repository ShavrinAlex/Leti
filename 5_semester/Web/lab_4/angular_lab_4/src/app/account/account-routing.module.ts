import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { AccountComponent } from './account.component';


const authorizationRoutes: Routes = [
    {
        path: '',
        component: AccountComponent,
        children: [

        ]
    }

];

@NgModule({
    imports: [RouterModule.forChild(authorizationRoutes)],
    exports: [RouterModule],
})
export class AccountRoutingModule { }
