#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node *next;

        Node(int val){
            this->value = val;
            this->next = NULL;
        }
};


void addTail(Node *&head, int val){
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return;
}

// reverse with non recursive
Node *reverse(Node *&head,int k){
    
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;
    

    if (head == NULL)
    {
        return head;
    }

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next!=NULL){
        head->next = reverse(next, k);
    }

    return prev;
}

void printList(Node *node){
    while (node != NULL)
    {
        cout<< node->value;
        if (node->next!=NULL)
        {
            cout<< " -> ";
        }
        
        node = node->next;
    }

    return;
}


int main(){
    Node *head = NULL;
    int size, data, k;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin>>data;
        addTail(head, data);
    }

    cin>>k;

    head = reverse(head, k);

    printList(head);

    return 0;
}