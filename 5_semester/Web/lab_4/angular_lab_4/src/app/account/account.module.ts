import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { HttpClientModule } from '@angular/common/http';

import { AccountRoutingModule } from './account-routing.module';
import { AccountComponent } from './account.component';


@NgModule({
    imports: [CommonModule, AccountRoutingModule, HttpClientModule],
    declarations: [AccountComponent],
    providers: [],
    bootstrap: [AccountComponent]
})
export class AccountModule { 

}