import * as models from "./models/models.js";
import { db } from "./db.js";
import { QueryTypes } from 'sequelize';
export async function request_1() {
    /*
    На каком ринге выступает заданный хозяин со своей собакой?
    */
    let label = 'Request 1';
    console.time(label);
    await models.Dog.findAll({
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
        order: [['dog_number', 'ASC']],
        limit: 10
    }).then((result) => {
        console.timeEnd(label);
        console.log(label, ': На каком ринге выступает заданный хозяин со своей собакой?');
        for (let dog of result) {
            console.log('ring: ', dog.breed.dataValues.ring_number, 'dog: ', dog.dataValues.dog_number, dog.owner.dataValues.surname, dog.owner.dataValues.name);
        }
    });
}
export async function request_2() {
    /*
    Какими породами представлен заданный клуб?
    */
    let label = 'Request 2';
    console.time(label);
    await db.query(`SELECT club.club_id, dog.breed_name
            FROM "Clubs" AS club
                 INNER JOIN "ClubNumbers" AS club_numbers USING(club_id)
                 INNER JOIN "Dogs" AS dog USING(dog_number)
        GROUP BY club.club_id, dog.breed_name
        ORDER BY club.club_id, dog.breed_name
        LIMIT 10;`, { type: QueryTypes.SELECT }).then((result) => {
        console.timeEnd(label);
        console.log(label, ': Какими породами представлен заданный клуб?');
        console.log(result);
    });
}
export async function request_3() {
    /*
    Какие медали и сколько заслужены клубом?
    */
    let label = 'Request 3';
    console.time(label);
    await db.query(`WITH dog_places AS (
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
            ORDER BY club.club_id
            LIMIT 10;`, { type: QueryTypes.SELECT }).then((result) => {
        console.timeEnd(label);
        console.log(label, ': Какие медали и сколько заслужены клубом?');
        console.log(result);
    });
}
export async function request_4() {
    /*
    Какие эксперты обслуживают породу?
    ORDER BY dog.breed_name
    */
    let label = 'Request 4';
    console.time(label);
    await db.query(`SELECT dog.breed_name, expert.expert_id, expert.name, expert.surname
           FROM "Dogs" AS dog
                INNER JOIN "DogExpertEstimates" AS dog_expert_estimate USING(dog_number)
                INNER JOIN "Experts" AS expert USING(expert_id)
       GROUP BY dog.breed_name, expert.expert_id
       
       LIMIT 10;`, { type: QueryTypes.SELECT }).then((result) => {
        console.timeEnd(label);
        console.log(label, ': Какие эксперты обслуживают породу?');
        console.log(result);
    });
}
export async function request_5() {
    /*
    Количество участников по каждой породе?
    */
    let label = 'Request 5';
    console.time(label);
    await models.Dog.findAll({
        attributes: ['breed_name', [db.fn('COUNT', db.col('dog_number')), 'count']],
        group: ['breed_name'],
        order: [['breed_name', 'ASC']],
        limit: 10
    }).then((result) => {
        console.timeEnd(label);
        console.log(label, ': Количество участников по каждой породе?');
        for (let dog of result) {
            console.log(dog.dataValues.breed_name, dog.dataValues.count);
        }
    });
}
