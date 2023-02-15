#include <iostream>
#include <cmath>

double F(double x, double c){
    return 1/(c*sin(x))+1;
}

double BISECT(double Left, double Right, double Eps, double c, int &N){
    double E = fabs(Eps)*2.0; 
    double FLeft = F(Left, c); 
    double FRight = F(Right, c);
    double X = (Left + Right) / 2.0;
    double Y;

    if (FLeft*FRight>0.0){
        puts("Неверно задан интервал\n");
        exit(1);
    }

    if (Eps <= 0.0){
        puts("Неверно задана точность\n");
        exit(1);
    }

    N = 0;
    if (FLeft == 0.0)
        return Left; 

    if (FRight == 0.0)
        return Right; 

    while ((Right - Left) >= E){
        X = 0.5*(Right + Left); 
        Y = F(X, c); 

        if (Y == 0.0)
            return (X); 

        if (Y*FLeft < 0.0)
            Right = X; 
        else{
            Left = X; FLeft = Y;
        }
        N++;
    };
    return(X);
} 

double Round(double X, double Delta){
    if (Delta <= 1E-9){
        puts("Неверно задана точность округления\n");
        exit(1);
    }

    if (X>0.0)
        return (Delta*(long((X / Delta) + 0.5))); 
    else
        return (Delta*(long((X / Delta) - 0.5)));
}

int main(){
    int N = 0;
    double delta, eps, c;

    std::cout<<"c = ";
    std::cin>>c;
    std::cout<<"delta = ";
    std::cin>>delta;
    std::cout<<"eps = ";
    std::cin>>eps;

    double root = BISECT(-M_PI, -M_PI/2, eps, c, N);
    double value = Round(F(root, c), delta);

    double obusl = 1/fabs(-cos(root)/(c*pow(sin(root), 2)));
    double obusl_max = eps/delta;
    bool est = obusl < obusl_max;

    std::cout<<"\nroot = "<<root<<"\nvalue = "<<value<<"\nN = "<<N<<"\n\nobusl = "<<obusl<<"\nobusl_max = "<<obusl_max<<"\nest = "<<est<<'\n';
    return 0;
}