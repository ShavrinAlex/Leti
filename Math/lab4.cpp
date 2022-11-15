#include <iostream>
#include <cmath>

using namespace std;

double F_derivative(double x, double c){
    return -(cos(x)/(c*pow(sin(x), 2)));
};

double F_double_derivative(double x, double c){
    return (pow(sin(x), 2) + 2 * pow(cos(x), 2))/(c * pow(sin(x), 3));
};

double truncRound(double x, double Eps){
    return trunc(x/Eps) * Eps;
};

double F(double x, double c){
    return 1/(c*sin(x))+1;
    //return truncRound(1/(c*sin(x))+1, 0.00001);
};

double Round(double X, double Delta){
    if (Delta <= 1E-9){
        puts("Неверно задана точность округления\n");
        exit(1);
    }

    if (X>0.0)
        return (Delta*(long((X / Delta) + 0.5))); 
    else
        return (Delta*(long((X / Delta) - 0.5)));
};

double searchx0(double a, double b, double c){
    double x0 = a;
    for (double i = a; i <= b; i += 0.01){
        if (F(i, c)*F_double_derivative(i, c) > 0){
            //std::cout<<i<<endl;
            x0 = i;
        }
    }
    return x0;
}

double m_min(double a, double b, double delta, double c){
    double min_ = fabs(F_derivative(a, c));
    for (double i = a; i <= b; i += delta){
        double elem = fabs(F_derivative(i, c));
        if (elem < min_){
            min_ = elem;
        }
    }
    return min_;
}

double M_maxNEWTON(double a, double b, double delta, double c){
    double max_ = fabs(F_double_derivative(a, c));
    for (double i = a; i <= b; i += delta){
        double elem = fabs(F_double_derivative(i, c));
        if(elem > max_ && elem != INFINITY ){
            max_ = elem;
        }
    }
    return max_;
}

double NEWTON(double X, double Eps, double delta, double c, int& N) {
    // extern double F1(double);
    double Y, Y1, DX, Eps0;
    N = 0;
    double m1 = m_min(3.5, 4, delta, c); // наименьшее значение модуля 1-ой производной
    double M2 = M_maxNEWTON(3.5, 4, delta, c); // наибольшее значение модуля 2-ой производной
    Eps0 = sqrt(2 * m1 * Eps / M2);
    do {
        Y = F(X, c);
        std::cout<<X<<' '<<Y<<'\n';
        if (Y == 0.0) {
           return X;
        }
        Y1 = F_derivative(X, c);
        if (Y1 == 0.0) {
            puts("Производная обратилась в ноль\n");
            exit(1);
        }
        DX = Y / Y1;
        X -= DX;
        N++;
    } //while (N<80);
    while (fabs(DX) >= Eps0);
    return X;
}

double M_maxITER(double a, double b, double delta, double c){
    double max_ = fabs(F_derivative(a, c));
    for (double i = a; i <= b; i += delta){
        double elem = fabs(F_derivative(i, c));
        if(elem > max_ && elem != INFINITY ){
            max_ = elem;
        }
    }
    return max_;
}

double fi(double a, double b, double x, double delta, double c){
    return x-(2/(m_min(a, b, delta, c)+ M_maxITER(a, b, delta, c)))* F(x, c);
}

double fi_derivative(double a, double b, double x, double delta, double c){
    return 1-(2/(m_min(a, b, delta, c)+ M_maxITER(a, b, delta, c)))* F_derivative(x, c);
}

double PHI(double x, double a, double b, double delta, double c){
    if (x == 0) {
        printf("деление на 0!");
        exit(1);
    }
    double min = m_min(a, b, delta, c);
    double max = M_maxITER(a, b, delta, c);
    double s = x - 2 / (min + max) * (F(x, c));
    s = Round(s, delta);
    return(s);
}

double ITER(double X0, double Eps, int& N, double a, double b, double delta, double c) {
    if (Eps <= 0.0) {
        puts("Неверное задание точности\n");
        exit(1);
    }
    double X1 = PHI(X0, a, b, delta, c);
    double X2 = PHI(X1, a, b, delta, c);
    for (N = 2; (X1 - X2) * (X1 - X2) > fabs((2 * X1 - X0 - X2) * Eps); N++) {
        X0 = X1;
        X1 = X2;
        X2 = PHI(X1, a, b, delta, c);
    }
    //std::cout<<N<<endl;
    return X2;
}

int main(){
    int N;
    double delta, eps, c;
    double A = -M_PI+0.3;
    double B = -M_PI+0.35;

    std::cout<<"c = ";
    std::cin>>c;
    std::cout<<"delta = ";
    std::cin>>delta;
    std::cout<<"eps = ";
    std::cin>>eps;

    //searchx0(a, b, c);
    //std::cout<<"m_min = "<<m_min(A, B, delta, c)<<'\n'<<"m_max = "<<M_maxNEWTON(A, B, delta, c)<<'\n';
    /*
    double m1 = m_min(3.5, 4, delta, c); // наименьшее значение модуля 1-ой производной
    double M2 = M_maxNEWTON(3.5, 4, delta, c); // наибольшее значение модуля 2-ой производной
    std::cout<<"Eps0 = "<<sqrt(2 * m1 * eps / M2)<<'\n';
    */
    //double X = NEWTON(searchx0(A, B, c), eps, delta, c, N);
    
    //std::cout<<"m_min = "<<m_min(A, B, delta, c)<<'\n'<<"m_max = "<<M_maxITER(A, B, delta, c)<<'\n';
    double X = ITER(searchx0(A, B, c), eps, N, A, B, delta, c);
    
    std::cout<<"X = "<<X<<'\n';
    std::cout<<"F(X) = "<<F(X, c)<<'\n';
    std::cout<<"N = "<<N<<'\n';
    //std::cout<<"Nu_delta = "<<fabs(1/F_derivative(X, c))<<'\n';
    std::cout<<"Nu_delta = "<<1/fabs(1 - fi_derivative(A, B, X, delta, c))<<'\n';
    std::cout<<"Nu_delta_max = "<<eps/delta<<'\n';
    
    return 0;
}
