#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

typedef struct Point{
	int x;
	int y;
} Point;

class Circle{
protected:
	Point center;
	float radius;
public:
	Circle(Point center, float radius){
		this->center = center;
		this->radius = radius;
	};
	float calcDist(Circle &cir){
		return trunc(sqrt((this->center.x-cir.center.x)*(this->center.x-cir.center.x) + (this->center.y-cir.center.y)*(this->center.y-cir.center.y))*10)/10.0;
	};
};

class Sector: Circle{
protected:
	int angle;
public:
	Sector(Point center, float radius, int angle):Circle(center, radius){
		this->angle = angle; 
	};
	float calcDist(Sector &sec){
		return trunc(sqrt((this->center.x-sec.center.x)*(this->center.x-sec.center.x) + (this->center.y-sec.center.y)*(this->center.y-sec.center.y))*10)/10.0;
	};
};

int main(){
	Point point1 = {0, 0};
	Point point2 = {30, 40};
	Point point3 = {5, 0};
	Point point4 = {20, 40};
	Circle circ1(point1, 10);
	Circle circ2(point2, 20);
	Sector sec1(point3, 10, 60);
	Sector sec2(point4, 20, 70);
	cout<<circ1.calcDist(circ2)<<endl;
	cout<<sec1.calcDist(sec2)<<endl;
	return 0;
}
