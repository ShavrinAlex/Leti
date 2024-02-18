#include <iostream>
#include <map>
#include <cstring>


using namespace std;

template <class T_key, class T_value> struct Map_elem{
        T_key key;
        T_value value;
};

template <class T_key, class T_value> class my_map{
        private:
        Map_elem <T_key, T_value> *data;
        int count;
        int size;
    public:
        my_map(){
            this->size = 100;
            this->data = new Map_elem<T_key, T_value>[this->size];
            this->count = 0;
        };

        void Set(T_key key, T_value value){
            if (count >= size){
                this->size *= 2;
                Map_elem <T_key, T_value> *new_data = new Map_elem<T_key, T_value> [this->size];
                memcpy(new_data, this->data, sizeof(Map_elem <T_key, T_value>)*count);
                delete [] this->data;
                this->data = new_data;
            }
            this->data[count].key = key;
            this->data[count].value = value;
            this->count += 1;
        };

        void Delete(T_key key){
            for (int i = 0; i < this->count; i++){
                if (this->data[i].key == key){
                    cout<<"delete "<<this->data[i].key<<" "<<this->data[i].value<<endl;
                    memmove(&data[i], &data[i+1], sizeof(Map_elem <T_key, T_value>)*(count-i-1));
                    this->count--;
                    break;
                }
            }
        };

        Map_elem <T_key, T_value> Get(T_key key){
            if (count != 0){
                for (int i = 0; i < count; i++){
                    if (this->data[i].key == key){
                        cout<<"get ";
                        return data[i];
                    }
                }
            }
            cout<<"end";
            Map_elem <T_key, T_value> err;
            return err;
        };

        ~my_map(){
            delete [] data;
        };
};



int main(){
    my_map<int, string> mp = my_map<int, string>();
    mp.Set(1, "one");
    mp.Set(2, "two");
    mp.Set(3, "three");
    cout<<mp.Get(1).value<<endl;
    mp.Delete(1);
    cout<<mp.Get(1).value<<endl;
    return 0;
}