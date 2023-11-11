import * as models from "./models/models.js";
export async function request_1() {
    return await models.Owner.findAll({
        attributes: ['dog_number'],
        include: [
            {
                model: models.Dog,
                required: true,
                //attributes: ['dog_number'],
            }
        ],
        /*
        order: [
            ['ring_number', 'ASC'],
            ['dog_number', 'ASC'],
            ['surname', 'ASC'],
            ['name', 'ASC'],
            ['patronymic', 'ASC'],
        ],*/
    });
}
/*
SELECT breed.ring_number, dog.dog_number, owner.surname, owner.name, owner.patronymic
FROM owner
     INNER JOIN dog ON owner.passport = dog.owner_passport
     INNER JOIN breed USING(breed_name)
ORDER BY breed.ring_number, dog.dog_number, owner.surname, owner.name, owner.patronymic;
*/ 
