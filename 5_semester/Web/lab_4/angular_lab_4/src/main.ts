import { platformBrowserDynamic } from '@angular/platform-browser-dynamic';

import { AppModule } from './app/app.module';
import { AuthorizationModule } from './app/authorization/authorization.module';


platformBrowserDynamic().bootstrapModule(AppModule)
  .catch(err => console.error(err));
