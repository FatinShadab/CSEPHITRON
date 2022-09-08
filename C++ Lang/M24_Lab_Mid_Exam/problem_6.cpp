#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
    

class LinearLinkedList{
    public:
        Node* head;

        int size = 0;

        LinearLinkedList(){
            this->head = NULL;
        }

        void append(int data){
            Node* newNode = new Node(data);

            if (this->head == NULL){
                this->head = newNode;
                this->size++;
                return;
            }

            int i=1;
            Node* current_node = this->head;
            while(i != this->size){
                current_node = current_node->next;
                i++;
            }

            current_node->next = newNode;
            this->size++;
        }

        void replace_even(){
            Node* current_node = this->head;
            for (int i=0; i < this->size; i++){
                if (current_node->data % 2 == 0){
                    current_node->data = -1;
                }
                current_node = current_node->next;
            }
        }

        void printList(){
            Node* current_node = this->head;
            for (int i=0; i < this->size; i++){
                cout<<current_node->data;
                current_node = current_node->next;
                if (i < this->size-1){
                    cout<<" -> ";
                }
            }
            cout<<endl;
        }

        int get_size(){
            return this->size;
        }

};


int main(){
    int val;
    int size;
    cin>>size;

    LinearLinkedList list;

    for (int i=0; i<size; i++){
        cin>>val;
        list.append(val);
    }

    cout<<"Linked List size :"<<list.get_size()<<endl;
    cout<<"Linked List before doing the task : ";
    list.printList();
    cout<<"Linked List After doing the task : ";
    list.replace_even();
    list.printList();

    return 0;
}