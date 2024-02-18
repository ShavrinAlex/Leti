#include <iostream>
#include <math.h>

class Equation{
    public:
        void set_args(int a, int b, int c){
            this->a = a;
            this->b = b;
            this->c = c;
        };

        int get_a(){
            return this->a;
        };
        
        int get_b(){
            return this->b;
        };

        int get_c(){
            return this->c;
        };

    private:
        int a, b, c;
};

class Answer{
    public:
        void set_ans(int f, double x1, double x2){
            this->f = f;
            this->x1 = x1;
            this->x2 = x2;
        };

        int get_f(){
            return this->f;
        };

        double get_x1(){
            return this->x1;
        };

        double get_x2(){
            return this->x2;
        };

    private:
        int f;
        double x1, x2;
};

class Print{
public:
    Print(){
        std::cout<<"Эта программа решает уравнения вида: a*x^2 + b*x + c = 0"<<std::endl;
    };

    void get_a(){
        std::cout<<"Введите аргумент а = ";
    };
    
    void get_b(){
        std::cout<<"Введите аргумент b = ";
    };

    void get_c(){
        std::cout<<"Введите аргумент c = ";
    };

    void ans(Equation *eq, Answer *ans){
        std::cout<<"Исходное уравнение:"<<std::endl;
        std::cout<<eq->get_a()<<"*x^2 + ("<<eq->get_b()<<")x + ("<<eq->get_c()<<") = 0"<<std::endl;
        if (ans->get_f() == -1){
            std::cout<<"Нет решения. Дискриминант отрицательный."<<std::endl; 
        } else{
            std::cout<<"x1 = "<<ans->get_x1()<<std::endl;
            std::cout<<"x2 = "<<ans->get_x2()<<std::endl;
        }
    };
};

class Getter{
    public:
        void get_args(Equation *eq, Print *pr){
            pr->get_a();
            std::cin>>a;

            pr->get_b();
            std::cin>>b;

            pr->get_c();
            std::cin>>c;

            eq->set_args(a, b, c);
        };

    private:
        int a, b, c;
};

class Solver{
    public:
        void solve(Equation *eq, Answer *ans){
            d = eq->get_b() * eq->get_b() - 4 * eq->get_a() * eq->get_c();
            if (d < 0){
                f, x1, x2 = (-1, 0, 0);
            } else{
                f = 1;
                x1 = (-eq->get_b() + sqrt(d))/(2*eq->get_a());
                x2 = (-eq->get_b() - sqrt(d))/(2*eq->get_a());
            }
            ans->set_ans(f, x1, x2);
        };

    private:
        int d, f;
        double x1, x2;
};

int main(){
    Equation eq;
    Answer ans;
    Getter gt;
    Solver sr;
    Print pr;

    char a = 'y';
    do{
        gt.get_args(&eq, &pr);
        sr.solve(&eq, &ans);
        pr.ans(&eq, &ans);
        std::cout<<"Продолжить решать уравнения?\n(Enter 'y' or 'n'): ";
        std::cin>>a;
    } while (a != 'n');
}