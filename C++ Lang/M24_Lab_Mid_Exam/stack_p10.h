#include <bits/stdc++.h>

using namespace std;


template <typename N> class Node{
    public:
        N val;
        Node *next;
        Node *prev;

        Node(N val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};


template <typename S> class Stack{
    int count = 0;
    Node <S> *top;
    Node <S> *head;
    Node <S> *middle;

    public:
        Stack(){
            this->head = NULL;
            this->top = NULL;
            this->middle = NULL;

        }

        void push(S val){
            Node <S> *newNode  = new Node <S> (val);

            if (this->head == NULL){
                this->head = this->top = this->middle = newNode;
            }
            else{
                this->top->next = newNode;
                newNode->prev = this->top;
                this->top = newNode;

                if (count%2 == 1){
                    this->middle = this->middle->next;
                }
            }

            count++;

            return;
        }

        S pop(void){
            S stack_ele;
            Node <S> *delNode = this->top;

            if (this->head == NULL){
                cout<<"Stack Underflow. No element found in stack!"<<endl;
                return stack_ele;
            }

            else if (this->head == this->top){
                this->head = this->top = this->middle = NULL;
            }

            else{
                this->top = delNode->prev;
                this->top->next = NULL;

                if(count % 2 == 0){
                    this->middle = this->middle->prev;
                }
            }

            stack_ele = delNode->val;
            delete delNode;

            count--;

            return stack_ele;
        }

        S get_top(void){
            S invaild_return_val;
            if (this->top == NULL){
                cout<<"Stack Underflow. No value in top"<<endl;
                return invaild_return_val;
            }
            else{
                return this->top->val;
            }
        }

        S mid(void){
            S invaild_return_val;

            if (this->empty()){
                cout<<"Stack Underflow. No element in the stack"<<endl;
                return invaild_return_val;
            }
            else{
                return this->middle->val;
            }
        }

        int get_size(void){
            return count;
        }

        bool empty(void){
            if (count > 0) return false;
            else return true;
        }

};