import { db } from "./db.js"
import * as models from "./models/models.js"
import { fill_db } from "./fill_db.js"
import { request_1 } from "./requests.js"

try{
    await db.authenticate();
    console.log('aunt: done')
    db.addModels([models.Ring, models.Breed, models.Expert, models.Club, models.ClubNumber, models.Owner, models.Dog, models.DogExpertEstimate])
    console.log('models add: done')
    await db.sync({ force: true })
    console.log('db sync: done')
    await fill_db();
    console.log('fill db: done')
    //console.log(await models.Breed.findAll());
    console.log(await request_1());
    //await models.Breed.findAll();

} catch(error) {
    console.log('aunt: error', error)
}
