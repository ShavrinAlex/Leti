import { Component } from '@angular/core';
import { AppService } from './app-service.component';


@Component({
  selector: 'app-root',
  template: `
<router-outlet></router-outlet>`,
  providers: [AppService]
})
export class AppComponent {
  constructor (private app_service: AppService) {
    console.log('constr app comp')
  }
}