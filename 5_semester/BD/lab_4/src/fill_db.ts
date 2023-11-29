import * as models from "./models/models.js"
import { faker } from "@faker-js/faker"
const COUNT = 10000;
const UNIQUE_VALUES = uniqueValues();


export async function fill_db() {
    // fill Rings
    let rings: any[] = createRings()

    await models.Ring.bulkCreate(
        rings.map((ring) => (ring)), 
        { returning: false }
    );

    //fill Breeds
    let breeds: any[] = createBreeds();

    await models.Breed.bulkCreate(
        breeds.map((breed) => (breed)), 
        { returning: false }
    );
    
    //fill clubs
    let clubs: any[] = faker.helpers.multiple(createClub, {count: COUNT});

    await models.Club.bulkCreate(
        clubs.map((club) => (club)), 
        { returning: false }
    );
    
    //fill experts
    let experts: any[] = faker.helpers.multiple(createExpert, {count: COUNT});

    await models.Expert.bulkCreate(
        experts.map((expert) => (expert)), 
        { returning: false }
    );
       
    //fill owners
    let owners: any[] = createOwners();

    await models.Owner.bulkCreate(
        owners.map((owner) => (owner)), 
        { returning: false }
    );

    //fill dogs
    let dogs: any[] = faker.helpers.multiple(createDog, {count: COUNT}); 

    await models.Dog.bulkCreate(
        dogs.map((dog) => (dog)), 
        { returning: false }
    );
       
    //fill club numbers
    let club_numbers: any[] = createClubNumbers();

    await models.ClubNumber.bulkCreate(
        club_numbers.map((club_number) => (club_number)), 
        { returning: false }
    );
    
    //fill dogs experts estimates
    let dogs_experts_estimates: any[] = createDogsExpertsEstimates();

    await models.DogExpertEstimate.bulkCreate(
        dogs_experts_estimates.map((dog_expert_estimate) => (dog_expert_estimate)), 
        { returning: false }
    );
    
}   

function getPassport(): string {
    return faker.finance.accountNumber({length: 4}) + ' ' + faker.finance.accountNumber({length: 6})
}

function uniqueValues(): any {
    const unique_values = {
        'breed_names': faker.helpers.uniqueArray(faker.animal.dog, COUNT),
        'passports': faker.helpers.uniqueArray(getPassport, COUNT)
    };
    return unique_values;
}

function createRings(): any[] {
    let rings = [];
    for (let i = 1; i <= COUNT; i++){
        rings.push(i)
    }
    return rings;
}

function createBreeds(): any[] {
    let breeds = [];
    for (let breed_name of UNIQUE_VALUES.breed_names){
        breeds.push({
            'breed_name': breed_name, 
            'ring_number': faker.number.int({min: 1, max: COUNT})
        })
    }
    return breeds;
}

function createClub(): any {
    return {
        'club_name': faker.company.name(), 
        'participants_number': faker.number.int({min: 0, max: Math.round(COUNT/3)})
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

function createOwners(): any[] {
    let owners = []
    for (let passport of UNIQUE_VALUES.passports){
        owners.push({
            'passport': passport,
            'surname': faker.person.lastName(), 
            'name': faker.person.firstName(), 
            'patronymic': faker.person.middleName()
        })
    }
    return owners;
}

function createDog(): any {
    return {
        'owner_passport': faker.helpers.arrayElement(UNIQUE_VALUES.passports), 
        'breed_name':  faker.helpers.arrayElement(UNIQUE_VALUES.breed_names), 
        'pedigree_document_number': faker.finance.accountNumber({length: 7}), 
        'mother_nickname': faker.person.firstName('female'), 
        'father_nickname': faker.person.firstName('male'), 
        'nickname': faker.person.firstName(), 
        'age': faker.number.int({min: 1, max: 25}), 
        'vaccination_date': faker.date.recent()
    }
}

function createClubNumbers(): any {
    let club_numbers = [];
    let dog_numbers_shuffled = [];
    for (let i = 1; i <= COUNT; i++) {
        dog_numbers_shuffled.push(i)
    }
    dog_numbers_shuffled = faker.helpers.shuffle(dog_numbers_shuffled);

    for (let i = 1; i <= COUNT; i++){
        club_numbers.push({
            'club_id': i,
            'dog_number': dog_numbers_shuffled[i-1]
        })
    }
    return club_numbers;
}

function createDogsExpertsEstimates(): any {
    let dogs_experts_estimates = [];
    let dog_numbers_shuffled = [];
    for (let i = 1; i <= COUNT; i++) {
        dog_numbers_shuffled.push(i)
    }
    dog_numbers_shuffled = faker.helpers.shuffle(dog_numbers_shuffled);

    for (let i = 1; i <= COUNT; i++){
        dogs_experts_estimates.push({
            'dog_number': dog_numbers_shuffled[i-1], 
            'expert_id': i,
            'estimate': faker.number.int({min: 0, max: 10})
        })
    }
    return dogs_experts_estimates;
}

