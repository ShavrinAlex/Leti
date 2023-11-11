import * as models from "./models/models.js"


export async function fill_db(){
    // fill Rings
    for (let i = 1; i <= 5; i++){
       await models.Ring.create({});
    }
    //console.log(models.Ring.findAll())

    //fill Breeds
    let breeds = [
        ['Немецкая овчарка', 1],
        ['Доберман', 1],
        ['Померанский шпиц', 2],
        ['Йоркширский терьер', 3],
        ['Бультерьер', 4],
        ['Пудель', 5]
    ];
    await models.Breed.bulkCreate(
        breeds.map((row) => ({ breed_name: row[0], ring_number: row[1] })), 
        { returning: false }
    );
    //console.log(await models.Breed.findAll());

    //fill clubs
    let clubs = [
        ['Фаворит', 4],
        ['Оскар', 4],
        ['Статус', 4],
        ['Звезда', 3],
        ['Победа', 2]
    ];
    await models.Club.bulkCreate(
        clubs.map((row) => ({ club_name: row[0], participants_number: row[1] })), 
        { returning: false }
    );
    //console.log(await models.Club.findAll());

    //fill experts
    let experts = [
        [1, 1, 'Кардаш', 'Ярослав'],
        [2, 1, 'Шаврин', 'Алексей'],
        [2, 1, 'Дешура', 'Дмитрий'],
        [3, 3, 'Ефремов', 'Артем'],
        [4, 4, 'Есенина', 'Анастасия'],
        [5, 5, 'Насекина', 'Алена'],
        [5, 2, 'Лепс', 'Григорий'],
    ];
    await models.Expert.bulkCreate(
        experts.map((row) => ({ club_id: row[0], ring_number: row[1], surname: row[2], name: row[3] })), 
        { returning: false }
    );
    //console.log(await models.Expert.findAll());

    //fill owners
    let owners = [
        ['1111 222222', 'Потолов', 'Олег', 'Алексеевич'],
        ['2222 333333', 'Зубов', 'Александр', 'Андреевич'],
        ['3333 444444', 'Башкирев', 'Алексей', 'Владимирович'],
        ['4444 555555', 'Иванов', 'Иван', 'Иванович'],
        ['5555 666666', 'Добрицкий', 'Ярослав', 'Валерьевич'],
        ['6666 777777', 'Игнатьев', 'Владимир', 'Владимирович'],
        ['7777 888888', 'Бочаров', 'Никита', 'Игоревич'],
        ['8888 999999', 'Данилов', 'Дмитрий', 'Семенович']
    ];
    await models.Owner.bulkCreate(
        owners.map((row) => ({ passport: row[0], surname: row[1], name: row[2], patronymic: row[3] })), 
        { returning: false }
    );
    //console.log(await models.Owner.findAll());

    //fill dogs
    let dogs = [
        ['1111 222222', 'Немецкая овчарка', 1111111, 'Элис', 'Арчи', 'Рекс', 5, '2023-10-01'],
        ['1111 222222', 'Доберман', 1111112, 'Меган', 'Дизель', 'Рокс', 7, '2023-09-27'],
        ['2222 333333', 'Немецкая овчарка', 2222221, 'Меган', 'Дизель', 'Рокс', 8, '2023-09-06'],
        ['2222 333333', 'Доберман', 2222222, 'Элис', 'Арчи', 'Рекс', 6, '2023-09-06'],
        ['3333 444444', 'Немецкая овчарка', 3333331, 'Элли', 'Оливер', 'Раймонд', 7, '2023-09-12'],
        ['3333 444444', 'Доберман', 3333332, 'Эмма', 'Руди', 'Алекс', 9, '2023-09-23'],
        ['4444 555555', 'Немецкая овчарка', 4444441, 'Герда', 'Пит', 'Балу', 5, '2023-09-29'],
        ['4444 555555', 'Пудель', 4444442, 'Витта', 'Мэверик', 'Гектор', 5, '2023-09-22'],
        ['5555 666666', 'Бультерьер', 5555551, 'Грейт', 'Веня', 'Барон', 8, '2023-09-15'],
        ['5555 666666', 'Пудель', 5555552, 'Инга', 'Ефим', 'Герой', 4, '2023-09-16'],
        ['6666 777777', 'Бультерьер', 6666661, 'Лейла', 'Джанго', 'Кекс', 4, '2023-09-03'],
        ['6666 777777', 'Пудель', 6666662, 'Скай', 'Зевс', 'Моджо', 7, '2023-09-08'],
        ['7777 888888', 'Померанский шпиц', 7777771, 'Руни', 'Мич', 'Зефирка', 4, '2023-10-01'],
        ['7777 888888', 'Йоркширский терьер', 7777772, 'Барби', 'Ник', 'Пряник', 4, '2023-09-28'],
        ['8888 999999', 'Померанский шпиц', 8888881, 'Джесси', 'Зик', 'Ерошка', 6, '2023-09-20'],
        ['8888 999999', 'Йоркширский терьер', 8888882, 'Кристи', 'Сириус', 'Цезарь', 6, '2023-09-17'],
        ['8888 999999', 'Йоркширский терьер', 8888883, 'Фокс', 'Арчи', 'Тимка', 7, '2023-09-17']
    ];
    await models.Dog.bulkCreate(
        dogs.map((row) => ({ owner_passport: row[0], breed_name: row[1], pedigree_document_number: row[2], 
                            mother_nickname: row[3], father_nickname: row[4], nickname: row[5], 
                            age: row[6], vaccination_date: row[7] })), 
        { returning: false }
    );
    //console.log(await models.Dog.findAll());

    //fill club numbers
    let club_numbers = [
        [1, 1], [2, 1],
        [3, 1], [4, 1],
        [5, 2], [6, 2],
        [7, 2], [8, 2],
        [9, 3], [10, 3],
        [11, 3], [12, 3],
        [13, 5], [14, 5],
        [15, 4], [16, 4],
        [17, 4]
    ];
    await models.ClubNumber.bulkCreate(
        club_numbers.map((row) => ({ dog_number: row[0], club_id: row[1] })), 
        { returning: false }
    );
    //console.log(await models.ClubNumber.findAll());

    //fill dogs experts estimates
    let dogs_experts_estimates = [
        [1, 1, 9], [3, 1, 6], [5, 1, 8], [7, 1, 7],
        [1, 2, 10], [3, 2, 7], [5, 2, 9], [7, 2, 8],
        [2, 3, 7], [4, 3, 10], [6, 3, 8],
        [8, 6, 10], [10, 6, 10], [12, 6, 8],
        [9, 5, 8], [11, 5, 9],
        [14, 4, 5], [16, 4, 7], [17, 4, 8],
        [13, 7, 10], [15, 7, 10]
    ];
    await models.DogExpertEstimate.bulkCreate(
        dogs_experts_estimates.map((row) => ({ dog_number: row[0], expert_id: row[1], estimate: row[2] })), 
        { returning: false }
    );
    //console.log(await models.DogExpertEstimate.findAll());
}