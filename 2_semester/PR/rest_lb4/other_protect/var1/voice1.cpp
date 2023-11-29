#include <iostream>

using std::cout;
using std::endl;

class Animal{
public:
	virtual void voice() = 0;
};

class Dog: public Animal{
public:
	void voice(){
		cout<<"gav"<<endl;	
	}
};

class Cat: public Animal{
public:
	void voice(){
		cout<<"myau"<<endl;	
	}
};

class Frog: public Animal{
public:
	void voice(){
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
