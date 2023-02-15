#include <iostream>
#include <cstring>

#define BASE 10		//base array size
#define POCKET 3	//size shrink memory

#define FIRST_SIZE 100
#define SECOND_SIZE 10

using std::cout;
using std::endl;

template <class T>


class Array{
private:
	T *arr;
	int size_buf = 0;
	int len = 0;
protected:
	T *my_realloc(T *src, size_t new_size){
		T *tmp = new T[new_size];
		memcpy(tmp, src, new_size*sizeof(T));
		return tmp;
	};
public:
	Array(){
		this->arr = new T[size_buf];
	}
	void push_back(T &item){
		if (this->len == this->size_buf){
			this->size_buf += 2;
			my_realloc(this->arr, this->size_buf);
		}
		this->arr[len++] = item;	
	};

	void pop_back(){
		this->len--;
	};

	T get(size_t index){
		return this->arr[index];
	};

	void print(){
		for (int i = 0; i < len; i++){
			cout << this->arr[i] << endl;
		}
	}
};


int main(){
	Array <int> arr;
	int a = 10;
	int b = 20;
	int c = 30;
	arr.push_back(a);
	arr.push_back(c);
	arr.push_back(b);
	cout << arr.get(2) << endl;
	arr.pop_back();
	arr.print();
	return 0;
}
