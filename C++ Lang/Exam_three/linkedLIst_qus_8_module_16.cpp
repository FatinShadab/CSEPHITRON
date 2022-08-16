 #include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
 
class Node{
    public:
        int value;
        Node *Next;
 
    public:
        Node(int val){
            value = val;
            Next = NULL;
        }
};
 
void insertToHead(Node *&head, int val){
    Node  *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}
 
void insertToTail(Node *&head, int val){
    Node *newNode = new Node(val);
 
    if (head == NULL){
        head = newNode;
        return;
    }
 
    Node *temp = head;
    while(temp->Next != NULL){
        temp  = temp->Next;
    }
    temp->Next = newNode;
}
 
void reversedListPrint(Node *node){
 
    if (node == NULL){
        return;
    }
   
    reversedListPrint(node->Next);
 
    cout << node->value << " ";
}
 
void showLinkedList(Node *node){
    while(node != NULL){
        cout<< node->value<<" -> ";
        node = node->Next;
    }
    cout<<" NULL "<<endl;
}
 
int main() {
    int value;
    int user_choice = 0;
 
    Node *head = NULL;
 
    while (1){
 
        if (user_choice == 0){
            cout<<"Enter the element(int) : ";
            cin>>value;
            cout<<endl;
 
            insertToTail(head, value);
        }
        else if (user_choice == 1){
            cout<<"Enter the element(int) : ";
            cin>>value;
            cout<<endl;
            insertToTail(head, value);
        }
        else if (user_choice == 2){
            cout<<"Enter the element(int) : ";
            cin>>value;
            cout<<endl;
            insertToHead(head, value);
        }
        else if (user_choice == 3){
            break;
        }
 
        cout<<"\nThe Linkedlist : ";
        showLinkedList(head);
 
        cout<<"\n===============\n"<<"*** Valid Operations ***\n# 1 : Insert element at the Head\n# 2 : Insert element at the Tail\n# 3 : Exit"<<"\n===============\n"<<endl;
        cout<<"Enter operation code (1, 2, 3) : ";
        cin>>user_choice;
        cout<<endl;
    }
    cout<<"Loop breaked. The reversed linked list : ";
    reversedListPrint(head);
 
 
    return 0;
}

