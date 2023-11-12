import * as models from "./models/models.js"
import { db } from "./db.js"
import { QueryTypes } from 'sequelize'


export async function request_1() {
    /*
    SELECT breed.ring_number, dog.dog_number, owner.surname, owner.name, owner.patronymic
    FROM owner
        INNER JOIN dog ON owner.passport = dog.owner_passport
        INNER JOIN breed USING(breed_name)
    ORDER BY breed.ring_number, dog.dog_number, owner.surname, owner.name, owner.patronymic;
    */
    await models.Dog.findAll(
        {
            attributes: ['dog_number'],
           
            include: [
                {
                    model: models.Owner,
                    required: true,
                    attributes: ['surname', 'name']
                },
                {
                    model: models.Breed,
                    required: true,
                    attributes: ['ring_number'],
                }
            ],
            order: [
                ['dog_number', 'ASC'],
            ]
        }
    ).then((result) => {
        console.log('Request 1:');
        //console.log(result)
        for (let dog of result) {
            //console.log(dog)
            console.log(dog.breed.dataValues.ring_number, dog.dataValues.dog_number, dog.owner.dataValues.surname, dog.owner.dataValues.name)
        }
    });
}


export async function request_2(){
    /*
    SELECT club.club_id, dog.breed_name
        FROM club
            INNER JOIN club_numbers USING(club_id)
            INNER JOIN dog USING(dog_number)
    GROUP BY club.club_id, dog.breed_name
    ORDER BY club.club_id, dog.breed_name;
    */

    await db.query(
         `SELECT club.club_id, dog.breed_name
            FROM "Clubs" AS club
                 INNER JOIN "ClubNumbers" AS club_numbers USING(club_id)
                 INNER JOIN "Dogs" AS dog USING(dog_number)
        GROUP BY club.club_id, dog.breed_name
        ORDER BY club.club_id, dog.breed_name;`,
        { type: QueryTypes.SELECT }
    ).then((result) => {
        console.log('Request 2:');
        console.log(result);
    })
    /*
    models.ClubNumber.findAll(
        {
            attributes: [],
            include: [
                {
                    model: models.Club,
                    required: true,
                    attributes: ['club_id'],
                    
                },
                {
                    model: models.Dog,
                    required: true,
                    attributes: ['breed_name']
                }
            ],
            group: ['club.club_id'],
        }
    ).then((result) => {
        console.log('Request 2:');
        for (let club_number of result) {
            console.log(club_number)
            console.log(club_number.club.dataValues.club_id, club_number.dog.dataValues.breed_name)
        }
    });*/
}


export async function request_3() {
    /*
    WITH dog_places AS (
	SELECT dog.breed_name, dog.dog_number, ROUND(AVG(dog_expert_estimate.estimate), 2) AS Estimate,
            DENSE_RANK() OVER (PARTITION BY dog.breed_name ORDER BY ROUND(AVG(dog_expert_estimate.estimate), 2) DESC) AS place
        FROM dog
            INNER JOIN dog_expert_estimate USING(dog_number)
        GROUP BY dog.breed_name, dog.dog_number
        ORDER BY dog.breed_name, Estimate DESC
    )
    SELECT club.club_id, club.club_name, dog_places.place, COUNT(dog_places.place)
        FROM club
            INNER JOIN club_numbers USING(club_id)
            INNER JOIN dog_places USING(dog_number)
    GROUP BY club.club_id, club.club_name, dog_places.place
    ORDER BY club.club_id, dog_places.place;
    */

    await db.query(
        `WITH dog_places AS (
            SELECT dog.breed_name, dog.dog_number, ROUND(AVG(dog_expert_estimate.estimate), 2) AS Estimate,
                    DENSE_RANK() OVER (PARTITION BY dog.breed_name ORDER BY ROUND(AVG(dog_expert_estimate.estimate), 2) DESC) AS place
                FROM "Dogs" AS dog
                    INNER JOIN "DogExpertEstimates" AS dog_expert_estimate USING(dog_number)
                GROUP BY dog.breed_name, dog.dog_number
                ORDER BY dog.breed_name, Estimate DESC
            )
            SELECT club.club_id, club.club_name, dog_places.place, COUNT(dog_places.place)
                FROM "Clubs" AS club
                    INNER JOIN "ClubNumbers" AS club_numbers USING(club_id)
                    INNER JOIN dog_places USING(dog_number)
            GROUP BY club.club_id, club.club_name, dog_places.place
            ORDER BY club.club_id, dog_places.place;`, 
        { type: QueryTypes.SELECT }
    ).then((result) => {
        console.log('Request 3:');
        console.log(result);
    });
}


export async function request_4() {
    /*
    SELECT dog.breed_name, expert.expert_id, expert.name, expert.surname
        FROM dog
            INNER JOIN dog_expert_estimate USING(dog_number)
            INNER JOIN expert USING(expert_id)
    GROUP BY dog.breed_name, expert.expert_id
    ORDER BY dog.breed_name;
    */

    await db.query(
        `SELECT dog.breed_name, expert.expert_id, expert.name, expert.surname
           FROM "Dogs" AS dog
                INNER JOIN "DogExpertEstimates" AS dog_expert_estimate USING(dog_number)
                INNER JOIN "Experts" AS expert USING(expert_id)
       GROUP BY dog.breed_name, expert.expert_id
       ORDER BY dog.breed_name;`,
        { type: QueryTypes.SELECT }
    ).then((result) => {
        console.log('Request 4:');
        console.log(result);
    });
    /*  
    models.Dog.findAll(
        {
            attributes: ['breed_name'],
            include: [
                {
                    model: models.DogExpertEstimate,
                    required: true,
                    include: [
                        {
                            model: models.Expert,
                            required: true,
                            //attributes: []
                        }
                    ]
                }
            ],
            //group: ['dog->dog_expert_estimates.expert.expert_id'],
            order: ['breed_name']
        }
    ).then((result) => {
        console.log('Request 4:');
        for (let dog of result) {
            for (let dog_expert_estimate of dog.dog_expert_estimates){
                //console.log(dog_expert_estimate)
                let expert = dog_expert_estimate.expert
                //console.log(expert)
                console.log(dog.dataValues.breed_name, expert.dataValues.expert_id, expert.dataValues.name)
            }
        }
    })
    */
}


export async function request_5(){
    /*
      SELECT dog.breed_name, COUNT(*)
        FROM dog
    GROUP BY dog.breed_name
    ORDER BY dog.breed_name;
    */

    await models.Dog.findAll(
        {
            attributes: ['breed_name', [db.fn('COUNT', db.col('dog_number')), 'count']],
            group: ['breed_name'],
            order: [['breed_name', 'ASC']]
        }
    ).then((result) => {
        console.log('Request 5:');
        for (let dog of result) {
            console.log(dog.dataValues.breed_name, dog.dataValues.count)
        }
    })
}
