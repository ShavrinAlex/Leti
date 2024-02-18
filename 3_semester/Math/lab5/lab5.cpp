#include <iostream>
#include <cmath>
using namespace std;

double F(double x){
	return exp(cos(x));
}

int factorial(int i){
	if(i > 1){
    	return i * factorial(i - 1);
    }else{
        return i;
    }
}

double Lagrange(double arr_x[], double arr_y[], int n, double x){
	double L = 1;
	double P = 0;
	for(int i = 0; i < n; i++){
    	L = 1;
    	for (int k= 0; k < n; k++){
        	double el = 1;
        	if(k != i){
            	el = (x - arr_x[k])/(arr_x[i] - arr_x[k]);
        	}
        	L *= el;
    	}
    	P += (arr_y[i] * L);
	}
	return P;
}

double Newton1(double arr_x[], double arr_y[], int n, double x, double h){
	double P = 0;
	double arr_y1[n], arr_y2[n], arr_y3[n], arr_y4[n], arr_y5[n];
	for(int i = 0; i < n-1; i++){
    	arr_y1[i] = arr_y[i + 1] - arr_y[i];
	}
	for(int i = 0; i < n-2; i++){
    	arr_y2[i] = arr_y1[i + 1] - arr_y1[i];
	}
	for(int i = 0; i < n-3; i++){
    	arr_y3[i] = arr_y2[i + 1] - arr_y2[i];
	}
	for(int i = 0; i < n-4; i++){
    	arr_y4[i] = arr_y3[i + 1] - arr_y3[i];
	}
	for(int i = 0; i < n-5; i++){
    	arr_y5[i] = arr_y4[i + 1] - arr_y4[i];
	}

	double arr_a[] ={arr_y1[0], arr_y2[0], arr_y3[0], arr_y4[0], arr_y5[0]};
	for(int i = 0; i < n; i++){
    	if(i == 0){
        	P += arr_y[0];
    	}else{
            double el = 1;
            for (int k = 0; k < i; k++){
                el *= (x - arr_x[k]);
            }
            P += ((el * arr_a[i-1])/(factorial(i)*pow(h, i)));
    	}
	}
    /*
    for (int i = 0; i < 5; i++){
        cout<<"y"<<i<<" = "<<arr_a[i]<<'\n';
    }
    */
	return P;
}

double Newton2(double arr_x[], double arr_y[], int n, double x, double h){
	double P = 0;
	double arr_y1[n], arr_y2[n], arr_y3[n], arr_y4[n], arr_y5[n];
	for(int i = 0; i < n-1; i++){
    	arr_y1[i] = arr_y[i+1] - arr_y[i];
	}
	for(int i = 0; i < n-2; i++){
    	arr_y2[i] = arr_y1[i+1] - arr_y1[i];
	}
	for(int i = 0; i < n-3; i++){
    	arr_y3[i] = arr_y2[i+1] - arr_y2[i];
	}
	for(int i = 0; i < n-4; i++){
    	arr_y4[i] = arr_y3[i+1] - arr_y3[i];
	}
	for(int i = 0; i < n-5; i++){
    	arr_y5[i] = arr_y4[i+1] - arr_y4[i];
	}

	double arr_a[] ={arr_y1[4], arr_y2[3], arr_y3[2], arr_y4[1], arr_y5[0]};
	for(int i = 0; i < n; i++){
    	if(i == 0){
        	P += arr_y[n-1];
    	}else{
        	double el = 1;
        	for (int k = n-1; k > (n-i-1); k--){
            	el *= (x - arr_x[k]);
        	}
        	P += ((el * arr_a[i-1])/(factorial(i)*pow(h, i)));
    	}
	}
    /*
    for (int i = 0; i < 5; i++){
        cout<<"y"<<i<<" = "<<arr_a[i]<<'\n';
    }
    */
	return P;
}

double Approximation(double arr_x[], double arr_y[], int n, double x){
	double a, b;
	double sum_x = 0, sum_y = 0, sum_xy = 0, sum_dx = 0;
	for(int i = 0; i < n; i++){
    	sum_x += arr_x[i];
    	sum_y += arr_y[i];
    	sum_xy += (arr_x[i]*arr_y[i]);
    	sum_dx += pow(arr_x[i],2);
	}
	a = (n * sum_xy - sum_x * sum_y)/(n * sum_dx - pow(sum_x, 2));
	b = (sum_y - a * sum_x)/n;
	cout<<"\n"<<a<<" "<<b<<"\n";
	return a * x + b;

}

int main() {
	double arr_x[6] = {3.50, 4.10, 4.70, 5.30, 5.90, 6.50};
	double arr_y[6] = {0.39, 0.56, 0.99, 1.74, 2.53, 2.66};

	double x = 3.55;

	cout<<"F(x): "<<F(x)<<endl;
	cout<<"Lagrange: "<<Lagrange(arr_x, arr_y, 6, x)<<endl;
	cout<<"Newton_first: "<<Newton1(arr_x, arr_y, 6, x, 0.6)<<endl;
	cout<<"Newton_second: "<<Newton2(arr_x, arr_y, 6, x, 0.6)<<endl;
	cout<<"Approximation: "<<Approximation(arr_x, arr_y, 6, x)<<endl;

	return 0;
}
