#include <bits/stdc++.h>

using namespace std;


template <typename N> class NodeQ{
    public:
        N value;
        NodeQ<N> *next;

    public:
        NodeQ(N val){
            this->value = val;
            this->next = NULL;
        }
};


template <typename Q> class Queue{
    public:
        NodeQ <Q> *front;
        NodeQ <Q> *rear;

    public:
        Queue(){
            this->front = NULL;
            this->rear = NULL;
        }

        //enqueue  --> push
        void push(Q val){
            NodeQ<Q> *newNodeQ = new NodeQ<Q>(val);

            if (this->front == NULL){
                this->front = newNodeQ;
                this->rear = newNodeQ;
                return;
            }
            this->rear->next = newNodeQ;
            this->rear = this->rear->next;
        }

        //dequeue  --> pop
        Q pop(){
            Q data;

            if (this->rear == NULL){
                cout<<"Queue Underflow!"<<endl;
                return data;
            }

            
            NodeQ<Q> *delNodeQ;
            delNodeQ = this->front;
            this->front = this->front->next; 

            if (this->front == NULL){
                this->rear = NULL;
            }

            data = delNodeQ->value;

            delete delNodeQ;

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