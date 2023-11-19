import { 
    Table,
    Column,
    Model,
    PrimaryKey,
    AllowNull,
    DataType,
    AutoIncrement,
    Default,
} from 'sequelize-typescript';
import { BelongsTo, ForeignKey, HasMany} from 'sequelize-typescript'


@Table({ timestamps: false })
export class Owner extends Model {
    @HasMany(() => Dog)
    declare dogs: Dog[];

    @PrimaryKey
    @AllowNull(false)
    @Column(DataType.STRING(11))
    declare passport: string;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare surname: string;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare name: string;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare patronymic: string;
}

@Table({ timestamps: false })
export class Ring extends Model {
    @HasMany(() => Breed)
    declare breeds: Breed[];

    @HasMany(() => Expert)
    declare experts: Expert[];
    
    @PrimaryKey
    @AutoIncrement
    @Column(DataType.INTEGER)
    declare ring_number: number;
}

@Table({ timestamps: false })
export class Breed extends Model {
    @BelongsTo(() => Ring)
    declare ring: Ring;

    @HasMany(() => Dog)
    declare dogs: Dog[];

    @PrimaryKey
    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare breed_name: string;

    @ForeignKey(() => Ring)
    @Column(DataType.INTEGER)
    declare ring_number: number;
}

@Table({ timestamps: false })
export class Dog extends Model {
    @BelongsTo(() => Owner)
    declare owner: Owner;

    @BelongsTo(() => Breed)
    declare breed: Breed;

    @HasMany(() => DogExpertEstimate)
    declare dog_expert_estimates: DogExpertEstimate[];

    @PrimaryKey
    @AutoIncrement
    @Column(DataType.INTEGER)
    declare dog_number: number;

    @ForeignKey(() => Owner)
    @Column(DataType.STRING(11))
    declare owner_passport: string;

    @ForeignKey(() => Breed)
    @Column(DataType.STRING(255))
    declare breed_name: string;

    @AllowNull(false)
    @Column(DataType.INTEGER)
    declare pedigree_document_number: number;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare mother_nickname: string;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare father_nickname: string;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare nickname: string;

    @AllowNull(false)
    @Column(DataType.INTEGER)
    declare age: number;

    @AllowNull(false)
    @Column(DataType.DATE)
    declare vaccination_date: Date;
}

@Table({ timestamps: false })
export class Club extends Model {
    @HasMany(() => Expert)
    declare experts: Expert[];

    @HasMany(() => ClubNumber)
    declare club_numbers: ClubNumber[];

    @PrimaryKey
    @AutoIncrement
    @Column(DataType.INTEGER)
    declare club_id: number;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare club_name: string;

    @AllowNull(false)
    @Column(DataType.INTEGER)
    declare participants_number: number;
}

@Table({ timestamps: false })
export class Expert extends Model {
    @BelongsTo(() => Ring)
    declare ring: Ring;

    @BelongsTo(() => Club)
    declare club: Club;

    @HasMany(() => DogExpertEstimate)
    declare dogs_expert_estimate: DogExpertEstimate[];

    @PrimaryKey
    @AutoIncrement
    @Column(DataType.INTEGER)
    declare expert_id: number;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare surname: string;

    @AllowNull(false)
    @Column(DataType.STRING(255))
    declare name: string;

    @ForeignKey(() => Ring)
    @Column(DataType.INTEGER)
    declare ring_number: number;

    @ForeignKey(() => Club)
    @Column(DataType.INTEGER)
    declare club_id: number;
}

@Table({ timestamps: false })
export class ClubNumber extends Model {
    @BelongsTo(() => Club)
    declare club: Club;

    @BelongsTo(() => Dog)
    declare dog: Dog;

    @PrimaryKey
    @ForeignKey(() => Club)
    @Column(DataType.INTEGER)
    declare club_id: number;

    @PrimaryKey
    @ForeignKey(() => Dog)
    @Column(DataType.INTEGER)
    declare dog_number: number;
}

@Table({ timestamps: false })
export class DogExpertEstimate extends Model {
    @BelongsTo(() => Dog)
    declare dog: Dog;

    @BelongsTo(() => Expert)
    declare expert: Expert;

    @PrimaryKey
    @ForeignKey(() => Dog)
    @Column(DataType.INTEGER)
    declare dog_number: number;

    @PrimaryKey
    @ForeignKey(() => Expert)
    @Column(DataType.INTEGER)
    declare expert_id: number;

    @AllowNull(false)
    @Column(DataType.INTEGER)
    declare estimate: number;
}
