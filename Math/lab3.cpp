#include <iostream>
#include <cmath>

double F_derivative(double x, double c){
    return -(cos(x)/(c*pow(sin(x), 2)));
};

double truncRound(double x, double Eps){
    return trunc(x/Eps) * Eps;
};

double F(double x, double c){
    //return 1/(c*sin(x))+1;
    return truncRound(1/(c*sin(x))+1, 0.1);
};

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
        std::cout<<"X_"<<N<<" = "<<X<<' '<<F(X, c)<<'\n';
    };
    return(X);
};

double BISECT_2(double Left, double Right, double Eps, double c, int &N){
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

    while (N < 40){
        X = 0.5*(Right + Left); 
        Y = F(X, c); 

        if (Y == 0.0)
            return (X); 

        if (Y*FLeft < 0.0)
            Right = X; 
        else{
            Left = X;
            FLeft = Y;
        }
        N++;
        std::cout<<"X_"<<N<<" = "<<X<<' '<<F(X, c)<<'\n';
    };
    return(X);
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

double HORDA(double Left, double Right, double Eps, double c, int &N){
    double FLeft = F(Left, c); 
    double FRight = F(Right, c);
    double X;
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

    do{
        X = Left - (Right - Left)*FLeft/(FRight - FLeft);
        Y = F(X, c);

        if (Y == 0.0){
            return X;
        }

        if (Y * FLeft < 0.0){
            Right = X;
            FRight = Y;
        } else{
            Left = X;
            FLeft = Y;
        }
        N++;
        std::cout<<"X_"<<N<<" = "<<truncRound(X, Eps)<<' '<<F(truncRound(X, Eps), c)<<'\n';
    } while (fabs(Y) >= Eps);
    return X;
    
};

double HORDA_2(double Left, double Right, double Eps, double c, int &N){
    double FLeft = F(Left, c); 
    double FRight = F(Right, c);
    double X;
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

    do{
        X = Left - (Right - Left)*FLeft/(FRight - FLeft);
        Y = F(X, c);

        if (Y == 0.0){
            return X;
        }

        if (Y * FLeft < 0.0){
            Right = X;
            FRight = Y;
        } else{
            Left = X;
            FLeft = Y;
        }
        N++;
        std::cout<<"X_"<<N<<" = "<<X<<' '<<F(X, c)<<'\n';
    } while (N < 40);
    return X;
    
};

int main(){
    int N;
    double delta, eps, c;

    std::cout<<"c = ";
    std::cin>>c;
    std::cout<<"delta = ";
    std::cin>>delta;
    std::cout<<"eps = ";
    std::cin>>eps;
    
    double X = BISECT(-M_PI+0.15, -M_PI+0.35, eps, c, N);  
    //double X = BISECT_2(-M_PI+0.15, -M_PI+0.35, eps, c, N);
    //double X = HORDA(-M_PI+0.15, -M_PI+0.35, eps, c, N);     
    //double X = HORDA_2(-M_PI+0.15, -M_PI+0.35, eps, c, N);
    
    std::cout<<"X = "<<X<<'\n';
    std::cout<<"F(X) = "<<F(X, c)<<'\n';
    std::cout<<"N = "<<N<<'\n';
    std::cout<<"Nu_delta = "<<fabs(1/F_derivative(X, c))<<'\n';
    std::cout<<"Nu_delta_max = "<<eps/delta<<'\n';
    
    return 0;
}
