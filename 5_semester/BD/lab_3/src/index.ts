import { db } from "./db.js"
import * as models from "./models/models.js"
import { fill_db } from "./fill_db.js"
import * as requests from "./requests.js"


try{
    await db.authenticate();
    console.log('authenticate: done')

    db.addModels([models.Ring, models.Breed, models.Expert, models.Club, models.ClubNumber, models.Owner, models.Dog, models.DogExpertEstimate])
    console.log('models add: done')

    await db.sync({ force: true })
    console.log('db sync: done')

    await fill_db();
    console.log('fill db: done')

    await requests.request_1();
    await requests.request_2();
    await requests.request_3();
    await requests.request_4();
    await requests.request_5();
    console.log('requests: done')
} catch(error) {
    console.log('authenticate: error', error)
}
