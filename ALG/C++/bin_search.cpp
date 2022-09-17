#include <iostream>


class Bin_search{
    public:
        Bin_search(int elem, int size = 10) : size(size), elem(elem), arr(new int[size]){
            create_arr();
            print();
            std::cout << elem << " has index " << search(this->arr, this->elem, 0, this->size) << std::endl;
        };

    protected:
        void create_arr(){
            for (int i = 0; i < this->size; i++){
                this->arr[i] = i+1;
            }    
        };
        void print(){
            for (int i = 0; i < this->size; i++){
                std::cout << this->arr[i] << " ";
            }
            std::cout << std::endl;
        };
        int search(int *arr, int elem, int start, int end){
            if (start <= end){
                int mid = (start + end) / 2;
                if (arr[mid] == elem){
                    return mid;
                }
                if (arr[mid] > elem){
                    return search(arr, elem, start, mid - 1);
                }
                if (arr[mid] < elem){
                    return search(arr, elem, mid + 1, end);
                }
            } else{
                return -1;
            }
        };

    private:
        int size;
        int *arr;
        int elem;
};


int main(){
    Bin_search bs(5);
    return 0;
}