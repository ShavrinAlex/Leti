% Вариант 4 - сватья (мать зятя или невестки), теща.

parent(tom, bob). %  Том отец Боба
parent(ann, bob). %  Анна мать Боба
parent(tom, liza). % Том отец Лизы
parent(bob, mary). %  Боб отец Мери
parent(bob, luk). % Боб отец Люка
parent(luk, kate). % Люк отец Кейт
parent(alice, ann). % Алиса мать Анны 
parent(judy, tom). % Джуди мать Тома
parent(john, tom). % Джон отец Тома
female(alice). % Алиса является женщиной
female(judy). % Джуди является женщиной
female(ann). % Анна является женщиной
female(kate). % Кейт является женщиной
female(liza). % Лиза является женщиной
female(mary). % Мери является женщиной
male(john). % Джон является мужчиной
male(tom). % Том является мужчиной
male(bob). % Боб является мужчиной
male(luk). % Люк является мужчиной

% Для всех H и W, если H родитель C, W родитель C, и H и W не один человек то H и W - партнеры
partner(H, W) :- parent(H, C), parent(W, C), H \= W.
% Для всех X и M, если X и P - партнеры, M родитель P и M - женщина, то M - мать партнера X 
partnermother(X,M) :- partner(X, P), parent(M, P), female(M).
% Для всех X и M, если X и P - партнеры, M родитель P, M - женщина, P - женщина и X - мужчина, то M - теща X
wifesmother(X,M) :- partner(X, P), parent(M, P), female(M), female(P), male(X).
% Для всех X и M, если X родетель C и M - теща С, то M - сватья X
matchmaker(X, M) :- parent(X, C), partnermother(C, M).

% Для всех X, parent, Y, если X родитель Y, то parent - отношение "родитель" X к Y
relationship(X, parent, Y) :- parent(X, Y).
% Для всех X, partner, Y, если X партнер Y, то partner - отношение "партнер" X к Y
relationship(X, partner, Y) :- partner(X, Y).
% Для всех X, partnermother, Y, если X мать партнера Y, то partnermother - отношение "мать партнера" X к Y
relationship(X, partnermother, Y) :- partnermother(Y, X).
% Для всех X, wifesmother, Y, если X теща Y, то wifesmother - отношение "теща" X к Y
relationship(X, wifesmother, Y) :- wifesmother(Y, X).
% Для всех X, matchmaker, Y, если X сватья Y, то matchmaker - отношение "сватья" X к Y
relationship(X, matchmaker, Y) :- matchmaker(Y, X).