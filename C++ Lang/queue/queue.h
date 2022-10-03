#include <bits/stdc++.h>

using namespace std;


template <typename N> class Node{
    public:
        N value;
        Node<N> *next;

    public:
        Node(N val){
            this->value = val;
            this->next = NULL;
        }
};


template <typename Q> class Queue{
    public:
        Node <Q> *front;
        Node <Q> *rear;

    public:
        Queue(){
            this->front = NULL;
            this->rear = NULL;
        }

        //enqueue  --> push
        void push(Q val){
            Node<Q> *newNode = new Node<Q>(val);

            if (this->front == NULL){
                this->front = newNode;
                this->rear = newNode;
                return;
            }
            this->rear->next = newNode;
            this->rear = this->rear->next;
        }

        //dequeue  --> pop
        Q pop(){
            Q data;

            if (this->rear == NULL){
                cout<<"Queue Underflow!"<<endl;
                return data;
            }

            
            Node<Q> *delNode;
            delNode = this->front;
            this->front = this->front->next; 

            if (this->front == NULL){
                this->rear = NULL;
            }

            data = delNode->value;

            delete delNode;

            return data;
        }

        //peek     --> front() back()
        Q Front(){
            return this->front->value;
        }

        Q Back(){
            return this->rear->value;
        }

        //empty    --> empty()
        bool empty(){
            if(this->front == NULL && this->rear == NULL){
                return true;
            }
            return false;
        }
};