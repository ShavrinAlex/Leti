import * as models from "./models/models.js";
export async function request_1() {
    /*
    SELECT breed.ring_number, dog.dog_number, owner.surname, owner.name, owner.patronymic
    FROM owner
        INNER JOIN dog ON owner.passport = dog.owner_passport
        INNER JOIN breed USING(breed_name)
    ORDER BY breed.ring_number, dog.dog_number, owner.surname, owner.name, owner.patronymic;
    */
    models.Owner.findAll({
        attributes: ['surname', 'name'],
        include: [
            {
                model: models.Dog,
                required: true,
                attributes: ['dog_number'],
                //order: [ ['dog_number', 'ASC'] ],
                include: [
                    {
                        model: models.Breed,
                        required: true,
                        attributes: ['ring_number'],
                        //order: [ ['ring_number', 'ASC'] ] 
                    }
                ],
            }
        ],
        order: [
            ['surname', 'ASC'],
            ['name', 'ASC']
        ]
    }).then((result) => {
        console.log('Request 1:');
        for (let owner of result) {
            for (let dog of owner.dataValues.dogs) {
                console.log(dog.breed.dataValues.ring_number, dog.dataValues.dog_number, owner.dataValues.surname, owner.dataValues.name);
            }
        }
    });
}
export async function request_2() {
    /*
    SELECT club.club_id, dog.breed_name
        FROM club
            INNER JOIN club_numbers USING(club_id)
            INNER JOIN dog USING(dog_number)
    GROUP BY club.club_id, dog.breed_name
    ORDER BY club.club_id, dog.breed_name;
    */
    models.Club.findAll({
        attributes: ['club_id'],
        include: [
            {
                model: models.ClubNumber,
                required: true,
                include: [
                    {
                        model: models.Dog,
                        required: true,
                        attributes: ['breed_name']
                    }
                ]
            }
        ],
        //group: ['club_id', 'breed_name'],
        order: [
            ['club_id', 'ASC']
        ]
    }).then((result) => {
        console.log('Request 2:');
        for (let club of result) {
            //console.log(club)
            for (let club_number of club.dataValues.club_numbers) {
                //console.log(club_number)
                console.log(club.dataValues.club_id, club_number.dog.breed_name);
            }
        }
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
    models.Dog.findAll({
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
    }).then((result) => {
        console.log('Request 4:');
        for (let dog of result) {
            for (let dog_expert_estimate of dog.dog_expert_estimates) {
                //console.log(dog_expert_estimate)
                let expert = dog_expert_estimate.expert;
                //console.log(expert)
                console.log(dog.dataValues.breed_name, expert.dataValues.expert_id, expert.dataValues.name);
            }
        }
    });
}
export async function request_5() {
    /*
      SELECT dog.breed_name, COUNT(*)
        FROM dog
    GROUP BY dog.breed_name
    ORDER BY dog.breed_name;
    */
    models.Dog.findAll({
        attributes: ['breed_name'],
        group: ['breed_name'],
        order: ['breed_name']
    }).then((result) => {
        console.log('Request 5:');
        for (let dog of result) {
            console.log(dog.dataValues.breed_name);
        }
    });
}
