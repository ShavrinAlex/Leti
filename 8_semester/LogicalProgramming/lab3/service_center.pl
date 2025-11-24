% Вариант 4
% 
% Сервисный центр
% Имеется набор признаков неисправности компьютера 
% (например, "нет картинки на мониторе" и 
% "при загрузке издаются звуки: 1 длинный и 2 коротких" => "неисправна видеокарта"). 
% Требуется, задавая пользователю вопросы о признаках неисправности, 
% вынести решение о том, что неисправно в компьютере 
% (возможно, в виде предположений нескольких вариантов).

% Работа со статической переменной
% Инициализация переменной
static_init(V, X) :- assertz(vars(V, X)).
% Сохранение в переменную нового значения
static_set(V, X)  :- retract(vars(V, _)), assertz(vars(V, X)).
% Получение значения из переменной
static_get(V, X)  :- vars(V, X).
% Очистка переменной
static_release(V) :- retract(vars(V, _)).

% Работа со списками
% Нахождение пересечения списков
list_intersection([], _, []).
list_intersection([H | T], L, [H | R]) :- member(H, L), !, list_intersection(T, L, R).
list_intersection([_ | T], L, R) :- list_intersection(T, L, R).
% Объединение списков
list_merge([], L, L).
list_merge([H | T], L, [H | R]) :- \+ member(H, L), !, list_merge(T, L, R).
list_merge([_ | T], L, R) :- list_merge(T, L, R).
% Разница списков
list_substract([], _, []).
list_substract([H | T], L, [H | R]) :- \+ member(H, L), !, list_substract(T, L, R).
list_substract([_ | T], L, R) :- list_substract(T, L, R).
% Вывод списка
write_list([H]) :- write(H), nl.
write_list([H | T]) :- write(H), write(', '), write_list(T).

:- dynamic(malfunction_feature/2).
% Работа с базой знаний
% Загрузка базы знаний
load_db(Filename) :- see(Filename), read_entry, seen.
% Чтение записи базы знаний
read_entry :- read(Entry), load_entry(Entry).
% Загрузка записи базы знаний
load_entry(end_of_file).
load_entry(Entry) :- assertz(Entry), read_entry.

% Проверка, что признак не соответствует неисправности
malfunction_no_feature(Malfunction, Feature) :- malfunction_feature(Malfunction, _),
                                                \+ malfunction_feature(Malfunction, Feature).

% Вывод окончательного ответа пользователю
write_answer_for_user([]) :- write('Takoj neispravnosti net.').
write_answer_for_user(Malfunctions) :- write('U vas neispravno: '), write_list(Malfunctions).

% Сохранение ответа пользователя
save_answer(Feature, 'no') :-
	static_get(asked, Asked),
	static_get(matches, Matches),
	(setof(X, malfunction_no_feature(X, Feature), FeatureMalfunctions); FeatureMalfunctions = []),
	list_intersection(FeatureMalfunctions, Matches, PossibleMalfunctions),
	write('Vozmozhno u vas: '), write(PossibleMalfunctions), nl,
	static_set(matches, PossibleMalfunctions),
	static_set(asked, [Feature | Asked]),
	!.
save_answer(Feature, 'yes') :-
	static_get(asked, Asked),
	static_get(matches, Matches),
	(setof(X, malfunction_feature(X, Feature), FeatureMalfunctions); FeatureMalfunctions = []),
	list_intersection(FeatureMalfunctions, Matches, PossibleMalfunctions),
	write('Vozmozhno u vas: '), write(PossibleMalfunctions), nl,
	static_set(matches, PossibleMalfunctions),
	static_set(asked, [Feature | Asked]),
	!.
save_answer(Feature, _) :- write('Nekorrektnyj otvet. Pozhalujsta vvodite no ili yes. '), nl, ask_question([Feature]).

% Получение списка возможных неисправностей на основании отвеченных вопросов
possible_features_list([], []).
possible_features_list([Match | Tail], Features) :-
    setof(X, malfunction_feature(Match, X), MatchFeatures), !,
    possible_features_list(Tail, RestFeatures),
    list_merge(MatchFeatures, RestFeatures, Features).
possible_features_list([_ | Tail], Features) :-
    possible_features_list(Tail, Features).

% Нахождение списка признаков, по которым ещё не задавались вопросы 
% и которые есть хотя бы у одной возможной неисправности.
prepare_questions(Questions) :-
    static_get(matches, Matches),
    static_get(asked, Asked),
    possible_features_list(Matches, Features),
    list_substract(Features, Asked, Questions).

% Вопросы о наличии признаков 
ask_question([])    :- !.
ask_question([QuestionFeature])   :-
    write('U vas '), write(QuestionFeature), write('? - '),
    read_atom(Answer), save_answer(QuestionFeature, Answer).
ask_question([QuestionFeature|_]) :-
    write('U vas '), write(QuestionFeature), write('? - '),
    read_atom(Answer), !, save_answer(QuestionFeature, Answer),
    prepare_questions(NewQuesions), ask_question(NewQuesions), !.

% Начало работы
start(Filename) :-
    abolish(malfunction_feature/2),
    load_db(Filename),
    setof(M, malfunction_no_feature(M, none), Malfunctions),
    static_init(matches, Malfunctions), % Список неисправностей
    static_init(asked, []),             % Список признаков
    write('Vi dolzni otvechat` yes ili no.'), nl,
    setof(F, M^malfunction_feature(M, F), Features),
    ask_question(Features),
    static_get(matches, PossibleMalfunctions),
    static_release(asked),
    static_release(matches),
    write_answer_for_user(PossibleMalfunctions).
