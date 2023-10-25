import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { AuthorizationComponent } from './authorization.component';
import { LoginComponent } from './login/login.component';
import { SignupComponent } from './signup/signup.component';


const authorizationRoutes: Routes = [
    {
        path: '', redirectTo: 'login', pathMatch: 'full'
    },
    {
        path: '',
        component: AuthorizationComponent,
        children: [
            { path: 'login', component: LoginComponent },
            { path: 'signup', component: SignupComponent }
        ]
    }
];

@NgModule({
    imports: [RouterModule.forChild(authorizationRoutes)],
    exports: [RouterModule],
})
export class AuthorizationRoutingModule { }
