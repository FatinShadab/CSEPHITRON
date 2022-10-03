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

    public:
        Stack(){
            this->head = NULL;
            this->top = NULL;
        }

        void push(S val){
            Node <S> *newNode  = new Node <S> (val);

            if (this->head == NULL){
                this->head = this->top = newNode;
            }
            else{
                this->top->next = newNode;
                newNode->prev = this->top;
                this->top = newNode;
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
                this->head = this->top = NULL;
            }

            else{
                this->top = delNode->prev;
                this->top->next = NULL;
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

        int get_size(void){
            return count;
        }

        bool empty(void){
            if (count > 0) return false;
            else return true;
        }

};