#include <iostream>

using namespace std;

class Stack{
        public:
                Stack(){
                       this -> head = nullptr;
                }

                void push(int val){
                        auto *newNode = new struct Node;
                        newNode -> value = val;
                        newNode -> next = this -> head;
                        this -> head = newNode;
                }

                void pop(){
                        struct Node *tmp = this->head;
                        this -> head = tmp -> next;
                        delete tmp;
                }

                bool isEmpty(){
                        if (head == nullptr){
                            return true;
                        }else{
                            return false;
                        }
                }

                int top(){
                        return this -> head -> value;
                }

        private:
                struct Node{
                    int value;
                    struct Node *next;
                };
                struct Node *head;
};
