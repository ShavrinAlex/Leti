#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

template <class T>

T *my_realloc(T *src, size_t new_size){
	T *tmp = new T[new_size];
	memcpy(tmp, src, new_size*sizeof(T));
	return tmp;
}

class Test{
public:
	void print(){
		cout << "Test" << endl;
	};
};

int main(){
	int *a = new int[2];
	for (int i = 0; i < 2; i++){
		a[i] = i+5;
	}
	a = my_realloc(a, 5);
	for (int i = 2; i < 5; i++){
		a[i] = i+5;
	}
	for (int i = 0; i < 5; i++){
		cout << a[i] << " ";
	}

	cout << endl;
	Test *t = new Test[2];
	t = my_realloc(t, 5);
	for (int i = 0; i < 5; i++){
		t[i].print();
	}

	delete[] t;
	delete[] a;

	return 0;
}
