% Вариант 4
%
% Цвета машин  
% У Ивана машина красная, у Петра — не черная, не синяя, не голубая, 
% у Максима — черная и синяя, у Александра есть машины любого цвета (из перечисленных), у Бориса машины белого и синего цветов. 
% У кого какого цвета машины, если все водители ехали на машинах разных цветов?


% Условия задачи в виде фактов
owns(ivan, red).
owns(peter, red).
owns(peter, white).
owns(maxim, black).
owns(maxim, blue).
owns(alexandr, red).
owns(alexandr, black).
owns(alexandr, blue).
owns(alexandr, lightblue).
owns(alexandr, white).
owns(boris, white).
owns(boris, blue).

% Инициализация списков уникальных водителей и цветов
init(Owners, Colors) :- 
    setof(Owner, Color^owns(Owner, Color), Owners),
    setof(Color, Owner^owns(Owner, Color), Colors).

% Правило перебора - рекурсивное сопоставление списка водителей со списоком цветов с соответствующими проверками
try([Owner], [Color]) :- owns(Owner, Color).
try([Owner | OtherOwners], [Color | OtherColors]) :- 
    owns(Owner, Color),
    try(OtherOwners, OtherColors).

% Вывод решения на экран
write_solution([Owner], [Color]) :- write(Owner), write(' rides '), write(Color), write(' car'), nl, !.
write_solution([Owner | OtherOwners], [Color | OtherColors]) :- 
    write(Owner), write(' rides '), write(Color), write(' car'), nl,
    write_solution(OtherOwners, OtherColors).

% Точка входа
solve :-
    init(Owners, Colors),
    permutation(Colors, PossibleColors),
    try(Owners, PossibleColors),
    write_solution(Owners, PossibleColors).
