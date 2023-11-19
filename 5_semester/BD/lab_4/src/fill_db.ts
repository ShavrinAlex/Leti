import * as models from "./models/models.js"
import { Sex, faker } from "@faker-js/faker"
var COUNT = 10;


export async function fill_db() {
    // fill Rings
    let rings = [];
    for (let i = 1; i <= COUNT; i++){
        rings.push(i)
    }
    //console.log(rings)
    await models.Ring.bulkCreate(
        rings.map((ring) => (ring)), 
        { returning: false }
    );

    //fill Breeds
    let breeds: any[] = faker.helpers.multiple(createBreed, {count: COUNT});
    //console.log(breeds)
    await models.Breed.bulkCreate(
        breeds.map((breed) => (breed)), 
        { returning: false }
    );
    
    //fill clubs
    let clubs: any[] = faker.helpers.multiple(createClub, {count: COUNT});
    //console.log(clubs) 
    await models.Club.bulkCreate(
        clubs.map((club) => (club)), 
        { returning: false }
    );

    //fill experts
    let experts: any[] = faker.helpers.multiple(createExpert, {count: COUNT});
    //console.log(experts)
    await models.Expert.bulkCreate(
        experts.map((expert) => (expert)), 
        { returning: false }
    );

    //fill owners
    let owners: any[] = faker.helpers.multiple(createOwner, {count: COUNT});
    //console.log(owners)
    await models.Owner.bulkCreate(
        owners.map((owner) => (owner)), 
        { returning: false }
    );

    //fill dogs
    let dogs: any[] = faker.helpers.multiple(createDog, {count: COUNT}); 
    //console.log(dogs)
    await models.Dog.bulkCreate(
        dogs.map((dog) => (dog)), 
        { returning: false }
    );

    //fill club numbers
    let club_numbers: any[] = faker.helpers.multiple(createClubNumber, {count: COUNT}); 
    //console.log(club_numbers)
    await models.ClubNumber.bulkCreate(
        club_numbers.map((club_number) => (club_number)), 
        { returning: false }
    );

    //fill dogs experts estimates
    let dogs_experts_estimates: any[] = faker.helpers.multiple(createDogExpertEstimate, {count: COUNT});
    //console.log(dogs_experts_estimates)
    await models.DogExpertEstimate.bulkCreate(
        dogs_experts_estimates.map((dog_expert_estimate) => (dog_expert_estimate)), 
        { returning: false }
    );
}   

function createBreed(): any {
    return {
        'breed_name': faker.animal.dog(),
        'ring_number': faker.number.int({min: 1, max: COUNT})
    };
}

function createClub(): any {
    return {
        'club_name': faker.company.name(), 
        'participants_number': faker.number.int({min: 0, max: 100})
    };
}

function createExpert(): any {
    return {
        'club_id': faker.number.int({min: 1, max: COUNT}), 
        'ring_number': faker.number.int({min: 1, max: COUNT}), 
        'surname': faker.person.lastName(), 
        'name': faker.person.firstName()
    }
}

function createOwner(): any {
    return {
        'passport': faker.finance.accountNumber({length: 4}) + ' ' + faker.finance.accountNumber({length: 6}),
        'surname': faker.person.lastName(), 
        'name': faker.person.firstName(), 
        'patronymic': faker.person.middleName()
    }
}

function createDog(): any {
    //choise owner passport
    return {
        'owner_passport': faker.finance.accountNumber({length: 4}) + ' ' + faker.finance.accountNumber({length: 6}), 
        'breed_name': faker.animal.dog(), 
        'pedigree_document_number': faker.finance.accountNumber({length: 7}), 
        'mother_nickname': faker.person.firstName('female'), 
        'father_nickname': faker.person.firstName('male'), 
        'nickname': faker.person.firstName(), 
        'age': faker.number.int({min: 1, max: 25}), 
        'vaccination_date': faker.date.recent()
    }
}

function createClubNumber(): any {
    return {
        'dog_number': faker.number.int({min: 1, max: COUNT}), 
        'club_id': faker.number.int({min: 1, max: COUNT})
    }
}

function createDogExpertEstimate(): any {
    return {
        'dog_number': faker.number.int({min: 1, max: COUNT}), 
        'expert_id': faker.number.int({min: 1, max: COUNT}), 
        'estimate': faker.number.int({min: 0, max: 10})
    }
}

