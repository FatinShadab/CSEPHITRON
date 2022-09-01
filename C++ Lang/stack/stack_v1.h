#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int val){
            value = val;
            next = NULL;
            prev = NULL;
        }
};

class Stack{
    Node* head;
    Node* top;
    int count = 0;

    public:
        Stack(){
            head = NULL;
            top = NULL;
        }
        // PUSH
        void push(int val){
            Node* newNode = new Node(val);

            if (head == NULL){
                head = top = newNode;
            }
            else{
                top->next = newNode;
                newNode->prev = top;
                top = newNode;
            }

            count ++;

            return;
        }

        // POP
        int pop (void){
            int temp_val = -1;
            Node* delNode = top;

            if(head == NULL){
                cout<<"Stack Underflow"<<endl;
                return temp_val;
            }

            if (head == top){
                head = top = NULL;
            }
            else{
                top = delNode->prev;
                top->next = NULL;
            }

            temp_val = delNode->value;
            delete delNode;

            count --;

            return temp_val;
        }

        // EMPTY
        bool empty(void){
            if (head == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        // TOP
        int get_top(void){
            if(top == NULL){
                cout<<"Stack Underflow. No value in top"<<endl;
                return -1;
            }
            else{
                return top->value;
            }
        }

        //SIZE
        int size(void){
            return count;
        }
};