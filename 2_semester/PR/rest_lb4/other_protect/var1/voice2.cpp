#include <iostream>

using std::cout;
using std::endl;

class Animal{
public:
	void voice(){
		cout<<"I am Animal"<<endl;
	};
};

class Dog: public Animal{
public:
	void voice(){
		Animal::voice();
		cout<<"gav"<<endl;	
	}
};

class Cat: public Animal{
public:
	void voice(){
		Animal::voice();
		cout<<"myau"<<endl;	
	}
};

class Frog: public Animal{
public:
	void voice(){
		Animal::voice();
		cout<<"kva"<<endl;	
	}
};

int main(){
	Cat *cat = new Cat();
	Dog *dog = new Dog();
	Frog *frog = new Frog();

	cat->voice();
	dog->voice();
	frog->voice();

	return 0;
}
