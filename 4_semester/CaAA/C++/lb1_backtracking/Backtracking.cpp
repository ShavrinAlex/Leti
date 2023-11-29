#include <iostream>
#include <vector>


// Square - вектор векторов (двумерный массив), который является столом
typedef std::vector < std::vector <int> > Square;


struct Point{
    /*
        Point - класс точки, задающий координаты
    */

    int x;  // координата х
    int y;  // координата у
};


class Table{
    /*
        Table - класс стола, который реализует хранение всех необходимых параметров и методов для решения задачи
    */

    private:
        int side;           // размер стола (минимальный делитель реального размера для ускорения)
        int factor;         // коэфициент изменения, отвечающий за то, во сколько раз изменена сторона стола

        Square square;      // площадь стола (используется как метрика)
        Square best_square; // лучшая площадь стола, хранящая наилучшее разбиение

        int count_squares;  // текущее количество квадратов, на которые разбит стол
        int record;         // минимальное количество квадратов,на которое разбит стол

        void Simplification();                                                      // метод, реализующий упрощение задачи, за счет уменьшения стороны
        void CreateSquare(Square *square);                                          // метод, реализующий начальное заполнение нулями метрик (square and best_square)
        void AddSquare(int start_x, int start_y, int width);                        // метод, реализующий добавление квадрата в метрику (square)
        void RemoveSquare(int start_x, int start_y, int width);                     // метод, реализующий удаление квадрата из метрики (square)
        int BestStart();                                                            // метод, реализующий первоначальную лучшую расстановку из 3х квадратов
        bool IsPossibleAddition(int start_x, int start_y, int width);               // метод, проверяющий возможность добавить квадрат в метрику (square)
        void Backtracking(int start_x, int start_y, int end);                       // метод реализующий перебор всех вариантов расстановки способом backtracking
        Point* FindNewAdditionPoint(int start_x, int start_y, int end, int width);  // метод, реализует нахождение новой позиции для запуска backtracking

    public:
        Table(int N);       // конструктор класса 
        void Assembly();    // метод, реализующий решение задачи
        void PrintAnswer(); // метод, реализующий вывод результата
};


void Table::Simplification(){
    /*
        В методе происходит нахождение минимального делителя для размера стола и его коэфициент изменения (для ускорения)
    */

    for (int deriv = 2; deriv <= this->side / 2; deriv++){
        if (this->side % deriv == 0){
            this->factor = this->side / deriv;
            this->side = deriv;
            break;
        }
    }
};


Table::Table(int N){
    /* 
        Конструктор класса, реализующий задание начальных параметров
        Args:
            - N (int): Размер стола
    */

    this->side = N;
    this->factor = 1;

    this->Simplification();
    this->CreateSquare(&this->square);
    this->CreateSquare(&this->best_square);
    
    this->count_squares = 0;
    this->record = this->side * this->side;
};


void Table::CreateSquare(Square *square){
    /* 
        Конструктор метрики, реализующий создание и заполнение метрики нулями
        Args:
            - square (Square *): Указатель на метрику
    */

    square->reserve(this->side);
    for (int y = 0; y < this->side; y++){
        square->emplace_back(std::vector <int>());
        square->at(y).reserve(this->side);
        for (int x = 0; x < this->side; x++){
            square->back().push_back(0);
        }
    }
};


void Table::AddSquare(int start_x, int start_y, int width){
    /* 
        Метод, реализующий добавление квадрата в метрику square и заполнение необходимой площади значением -1, 
        а левый верхний угол квадрата значением размера квадрата
        Args:
            - start_x (int): Координата x левого верхнего угла квадрата
            - start_y (int): Координата y левого верхнего угла квадрата
            - width (int): Размер добавляемого квадрата (его ширина)
    */

    this->count_squares++;
    for (int y = start_y; y < start_y + width; y++){
        for (int x = start_x; x < start_x + width; x++){
            if (this->square.at(y).at(x) == 0){
                this->square.at(y).at(x) = -1;
            }
        }
    }
    this->square.at(start_y).at(start_x) = width;
};


void Table::RemoveSquare(int start_x, int start_y, int width){
    /* 
        Метод, реализующий удаление квадрата из метрику square и заполнение необходимой площади значением 0
        Args:
            - start_x (int): Координата x левого верхнего угла квадрата
            - start_y (int): Координата y левого верхнего угла квадрата
            - width (int): Размер удаляемого квадрата (его ширина)
    */

    this->count_squares--;
    for (int y = start_y; y < start_y + width; y++){
        for (int x = start_x; x < start_x + width; x++){
            if (this->square.at(y).at(x) != 0){
                this->square.at(y).at(x) = 0;
            }
        }
    }
};


int Table::BestStart(){
    /* 
        Метод, реализующий заполнение метрики square 3мя квадратами, всегда входящими в лучшее решение
        Returns:
            - best_first_width (int): Размер самого большого вписанного квадрата
    */

    int best_first_width = (this->side / 2) + (this->side % 2);
    
    this->AddSquare(0, 0, best_first_width);
    this->AddSquare(0, best_first_width, this->side - best_first_width);
    this->AddSquare(best_first_width, 0, this->side - best_first_width);

    return best_first_width;
};


bool Table::IsPossibleAddition(int start_x, int start_y, int width){
    /* 
        Метод, проверяющий возможность добавления квадрата в метрику square с учетом выхода за границы
        и занятость вставляемой области
        Args:
            - start_x (int): Координата x левого верхнего угла квадрата
            - start_y (int): Координата y левого верхнего угла квадрата
            - width (int): Размер добавляемого квадрата (его ширина)
        Returns:
            - True/False (bool): Возможность или не возможность добавления
    */

    // проверка выхода за границы
    if ((start_x + width > this->side) || (start_y + width > this->side)){
        return false;
    }

    // проверка занятости области для добавления
    for (int y = start_y; y < start_y + width; y++){
        for (int x = start_x; x < start_x + width; x++){
            if (this->square.at(y).at(x) != 0){
                return false;
            }
        }
    }

    return true;
};


void Table::Backtracking(int start_x, int start_y, int end){
    /* 
        Метод, выполняющий рекурсивный перебор всех возможный вариантов размешения квадратов в заданой области
        Args:
            - start_x (int): Координата x левого верхнего угла области заполнения
            - start_y (int): Координата y левого верхнего угла области заполнения
            - end (int): Граница области заполнения, как по х так и по у 
    */

    
    // проверка не оптимальности решения
    if (this->count_squares >= this->record){
        return;
    }
    
    // проверка свободности начальной координаты для вставки
    if (this->square.at(start_y).at(start_x) == 0){

        // расчет максимально возможного размера вставляемого квадрата
        int max_width = std::min(end - start_x, end - start_y);

        // перебор размеров вставляемого квадрата
        for (int width = max_width; width >= 1; width--){
            // проверка возможности добавления
            if (this->IsPossibleAddition(start_x, start_y, width)){
                this->AddSquare(start_x, start_y, width);

                // поиск точки для перехода на новую координату
                Point* point = this->FindNewAdditionPoint(start_x, start_y, end, width);

                // проверка на незаполненность метрики square
                if ((point->x != -1) && (point->y != -1)){
                    this->Backtracking(point->x, point->y, end);
                } else {
                    // запись нового рекорда и лучшего разбиения
                    this->record = this->count_squares;
                    this->best_square = this->square;
                }
                delete point;
                this->RemoveSquare(start_x, start_y, width);
            }
        }
    } else {
        // поиск точки для перехода на новую координату
        Point* point = this->FindNewAdditionPoint(start_x, start_y, end, 1);

        // проверка на незаполненность метрики square
        if ((point->x != -1) && (point->y != -1)){
            this->Backtracking(point->x, point->y, end);
        } else {
            // запись нового рекорда и лучшего разбиения
            this->record = this->count_squares;
            this->best_square = this->square;
        }
        delete point;
    }
};


Point* Table::FindNewAdditionPoint(int start_x, int start_y, int end, int width){
    /* 
        Метод, выполняющий поиск новой координаты левого верхнего угла для вставки квадрата
        Args:
            - start_x (int): Координата x левого верхнего угла области заполнения
            - start_y (int): Координата y левого верхнего угла области заполнения
            - end (int): Граница области заполнения, как по х так и по у 
            - width (int): размер последнего вставленного квадрата
        Returns:
            - point (Point*): Пара координат для запуска рекурсивного backtracking
    */

    Point *point = new Point();
    point->x = -1;                 // значение х для обозначения неудачи при поиске
    point->y = -1;                 // значение у для обозначения неудачи при поиске

    // заполнение текущей строки пока это возможно
    if (start_x + width < end){
        point->x = start_x + width;
        point->y = start_y;
    } else {
        // переход к новой строке, в самое начало по координате х
        if (start_y + 1 < end){
            point->x = this->side / 2;
            point->y = start_y + 1;
        }
    }
    return point;
};


void Table::Assembly(){
    /* 
        Метод, выполняющий решение задачи разбиения стола
    */

    int best_first_width = this->BestStart();

    // проверка на четность стороны квадрата (для ускорения)
    if (this->side == 2){
        this->AddSquare(best_first_width, best_first_width, this->side - best_first_width);
        this->record = this->count_squares;
        return;
    }

    this->Backtracking(this->side / 2, this->side / 2, this->side);
    this->square = this->best_square;
};


void Table::PrintAnswer(){
    /* 
        Метод, выполняющий вывод решения задачи в необходимом формате
    */

    std::cout << this->record << std::endl; // вывод минимального количества квадратов в разбиении

    // вывод координат квадратов в разбиении
    for (int y = 0; y < this->side; y++){
        for (int x = 0; x < this->side; x++){
            if (this->square.at(y).at(x) > 0){
                std::cout << (y * this->factor + 1) << ' ' << (x * this->factor + 1) << ' ' << (this->square.at(y).at(x) * this->factor) << std::endl;
            }
        }
    }
};


int main(){
    /*
        Главная функция, выполняющая работу всей программы
    */

    int N;
    std::cin >> N;
    Table table = Table(N);
    table.Assembly();
    table.PrintAnswer();

    return 0;
}
