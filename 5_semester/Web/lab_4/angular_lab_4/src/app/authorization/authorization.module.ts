import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';

import { AuthorizationRoutingModule } from './authorization-routing.module'
import { AuthorizationComponent } from './authorization.component';
import { LoginComponent } from './login/login.component';
import { SignupComponent } from './signup/signup.component';


@NgModule({
    imports: [CommonModule, AuthorizationRoutingModule],
    declarations: [AuthorizationComponent, LoginComponent, SignupComponent],
    providers: [],
    bootstrap: [AuthorizationComponent],
})
export class AuthorizationModule { 

}