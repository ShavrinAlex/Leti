import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { AuthorizationModule } from './authorization/authorization.module';
import { AccountModule } from './account/account.module';


const appRoutes: Routes = [
    {
        path: '', redirectTo: 'authorization', pathMatch: 'full'
    },
    {
        path: 'authorization',
        loadChildren: () => AuthorizationModule
    },
    {
        path: 'account',
        loadChildren: () => AccountModule
    }
];

@NgModule({
    imports: [RouterModule.forRoot(appRoutes)],
    exports: [RouterModule],
})
export class AppRoutingModule { }