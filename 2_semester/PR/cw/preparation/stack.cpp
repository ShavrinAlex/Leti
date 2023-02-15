#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


class CustomStack {
        public:
            CustomStack(){
                i = 0;
                N = 5;
            }
            ~CustomStack(){
                delete[] mData;
            }
            void push(int val){
                mData[i] = val;
                i++;
                if (i >= N){
                extend(5);
                }
            }
            void pop(){
                if (this->empty() == false){
                    mData[i] = 0;
                    i--;
                }
                else{
                    cout<<"error"<<endl;
                    exit(0);
                }
            }
            int top(){
                if (this->empty() == false){
                    return mData[i-1];
                }else{
                    cout<<"error"<<endl;
                    exit(0);
                }
            }
            size_t size(){
                return i;
            }
            bool empty(){
                return i == 0;
            }
        private:
            void extend(int n){
                int sz = size();
                int *newData = new int [sz+n];
                for (int j = 0; j < sz; j++){
                    newData[i] = mData[i];
                }
                delete[] mData;              
                mData = newData;
		N += n;
            }
        protected:
            int i;
            int N;
            int* mData = new int [N];
};

int main(){
    CustomStack cst;
    char str[101];
    fgets(str, 101, stdin);
    char *pch;
    pch = strtok(str, " ");
    while (pch != NULL){
        if (atoi(pch) || (*pch == '0')){
            cst.push(atoi(pch));
        }
        else{
            char action = *pch;
            if (cst.size() < 2){
                cout << "error" << endl;
                return 0;
            }
            int r = cst.top();
            cst.pop();
            int l = cst.top();
            cst.pop();
            if (action == '+'){
                cst.push(l+r);
                //cout << l+r << endl;
            }
            if (action == '-'){
                cst.push(l-r);
                //cout << l-r << endl;
            }
            if (action == '*'){
                cst.push(l*r);
                //cout << l*r << endl;
            }
            if (action == '/'){
                cst.push(l/r);
                //cout << l/r << endl;
            }
        }
        pch = strtok(NULL, " ");
    }
    
    if (cst.size() > 1){
        cout << "error" << endl;
        return 0;
    }else{
        cout << cst.top() << endl;
    }
    return 0;
}
