var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
import { Table, Column, Model, PrimaryKey, AllowNull, DataType, AutoIncrement, Index, } from 'sequelize-typescript';
import { BelongsTo, ForeignKey, HasMany } from 'sequelize-typescript';
let Owner = class Owner extends Model {
};
__decorate([
    HasMany(() => Dog),
    __metadata("design:type", Array)
], Owner.prototype, "dogs", void 0);
__decorate([
    PrimaryKey,
    Index,
    AllowNull(false),
    Column(DataType.STRING(11)),
    __metadata("design:type", String)
], Owner.prototype, "passport", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Owner.prototype, "surname", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Owner.prototype, "name", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Owner.prototype, "patronymic", void 0);
Owner = __decorate([
    Table({ timestamps: false })
], Owner);
export { Owner };
let Ring = class Ring extends Model {
};
__decorate([
    HasMany(() => Breed),
    __metadata("design:type", Array)
], Ring.prototype, "breeds", void 0);
__decorate([
    HasMany(() => Expert),
    __metadata("design:type", Array)
], Ring.prototype, "experts", void 0);
__decorate([
    PrimaryKey,
    Index,
    AutoIncrement,
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Ring.prototype, "ring_number", void 0);
Ring = __decorate([
    Table({ timestamps: false })
], Ring);
export { Ring };
let Breed = class Breed extends Model {
};
__decorate([
    BelongsTo(() => Ring),
    __metadata("design:type", Ring)
], Breed.prototype, "ring", void 0);
__decorate([
    HasMany(() => Dog),
    __metadata("design:type", Array)
], Breed.prototype, "dogs", void 0);
__decorate([
    PrimaryKey,
    Index,
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Breed.prototype, "breed_name", void 0);
__decorate([
    ForeignKey(() => Ring),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Breed.prototype, "ring_number", void 0);
Breed = __decorate([
    Table({ timestamps: false })
], Breed);
export { Breed };
let Dog = class Dog extends Model {
};
__decorate([
    BelongsTo(() => Owner),
    __metadata("design:type", Owner)
], Dog.prototype, "owner", void 0);
__decorate([
    BelongsTo(() => Breed),
    __metadata("design:type", Breed)
], Dog.prototype, "breed", void 0);
__decorate([
    HasMany(() => DogExpertEstimate),
    __metadata("design:type", Array)
], Dog.prototype, "dog_expert_estimates", void 0);
__decorate([
    PrimaryKey,
    Index,
    AutoIncrement,
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Dog.prototype, "dog_number", void 0);
__decorate([
    ForeignKey(() => Owner),
    Column(DataType.STRING(11)),
    __metadata("design:type", String)
], Dog.prototype, "owner_passport", void 0);
__decorate([
    Index,
    ForeignKey(() => Breed),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Dog.prototype, "breed_name", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Dog.prototype, "pedigree_document_number", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Dog.prototype, "mother_nickname", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Dog.prototype, "father_nickname", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Dog.prototype, "nickname", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Dog.prototype, "age", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.DATE),
    __metadata("design:type", Date)
], Dog.prototype, "vaccination_date", void 0);
Dog = __decorate([
    Table({ timestamps: false })
], Dog);
export { Dog };
let Club = class Club extends Model {
};
__decorate([
    HasMany(() => Expert),
    __metadata("design:type", Array)
], Club.prototype, "experts", void 0);
__decorate([
    HasMany(() => ClubNumber),
    __metadata("design:type", Array)
], Club.prototype, "club_numbers", void 0);
__decorate([
    PrimaryKey,
    Index,
    AutoIncrement,
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Club.prototype, "club_id", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Club.prototype, "club_name", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Club.prototype, "participants_number", void 0);
Club = __decorate([
    Table({ timestamps: false })
], Club);
export { Club };
let Expert = class Expert extends Model {
};
__decorate([
    BelongsTo(() => Ring),
    __metadata("design:type", Ring)
], Expert.prototype, "ring", void 0);
__decorate([
    BelongsTo(() => Club),
    __metadata("design:type", Club)
], Expert.prototype, "club", void 0);
__decorate([
    HasMany(() => DogExpertEstimate),
    __metadata("design:type", Array)
], Expert.prototype, "dogs_expert_estimate", void 0);
__decorate([
    PrimaryKey,
    Index,
    AutoIncrement,
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Expert.prototype, "expert_id", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Expert.prototype, "surname", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.STRING(255)),
    __metadata("design:type", String)
], Expert.prototype, "name", void 0);
__decorate([
    ForeignKey(() => Ring),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Expert.prototype, "ring_number", void 0);
__decorate([
    ForeignKey(() => Club),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], Expert.prototype, "club_id", void 0);
Expert = __decorate([
    Table({ timestamps: false })
], Expert);
export { Expert };
let ClubNumber = class ClubNumber extends Model {
};
__decorate([
    BelongsTo(() => Club),
    __metadata("design:type", Club)
], ClubNumber.prototype, "club", void 0);
__decorate([
    BelongsTo(() => Dog),
    __metadata("design:type", Dog)
], ClubNumber.prototype, "dog", void 0);
__decorate([
    PrimaryKey,
    Index,
    ForeignKey(() => Club),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], ClubNumber.prototype, "club_id", void 0);
__decorate([
    PrimaryKey,
    Index,
    ForeignKey(() => Dog),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], ClubNumber.prototype, "dog_number", void 0);
ClubNumber = __decorate([
    Table({ timestamps: false })
], ClubNumber);
export { ClubNumber };
let DogExpertEstimate = class DogExpertEstimate extends Model {
};
__decorate([
    BelongsTo(() => Dog),
    __metadata("design:type", Dog)
], DogExpertEstimate.prototype, "dog", void 0);
__decorate([
    BelongsTo(() => Expert),
    __metadata("design:type", Expert)
], DogExpertEstimate.prototype, "expert", void 0);
__decorate([
    PrimaryKey,
    Index,
    ForeignKey(() => Dog),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], DogExpertEstimate.prototype, "dog_number", void 0);
__decorate([
    PrimaryKey,
    Index,
    ForeignKey(() => Expert),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], DogExpertEstimate.prototype, "expert_id", void 0);
__decorate([
    AllowNull(false),
    Column(DataType.INTEGER),
    __metadata("design:type", Number)
], DogExpertEstimate.prototype, "estimate", void 0);
DogExpertEstimate = __decorate([
    Table({ timestamps: false })
], DogExpertEstimate);
export { DogExpertEstimate };
