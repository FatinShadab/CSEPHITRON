#include <bits/stdc++.h>

using namespace std;


class treeNode{
    public:
        int data;
        treeNode *leftChild;
        treeNode *rightChild;

    public:
        treeNode(int data){
            this->data = data;
            this->leftChild = NULL;
            this->rightChild = NULL;
        }
};


void printSpace(int lvl){
    for(int i=0; i<lvl; i++){
        cout<<"\t";
    }
}

void printTree(treeNode* root, int lvl){
    // case 1: to handle call for empty tree
    if (root == NULL){
        return;
    }
    // case 2: to handle call for leaf nodes
    if(root->leftChild == NULL && root->rightChild == NULL){
        cout<< root->data <<endl;
    }
    // case 3: to handle internal nodes
    else{
        cout<<endl;
        printSpace(lvl);
        cout<<"Root : "<< root->data << endl;
    }

    //to handle Left subtree
    if (root->leftChild != NULL){
        printSpace(lvl);
        cout<<"Left : ";
        printTree(root->leftChild, lvl+1);
    }
    //to handle right subtree
    if (root->rightChild != NULL){
        printSpace(lvl);
        cout<<"Right : ";
        printTree(root->rightChild, lvl+1);
    }

}

int searchInOrder(int inOarr[], int target, int start, int end){
    
    for(int i=start; i<=end; i++){
        if (inOarr[i] == target){
            return i;
        }
    }

    return -1;
}

treeNode * constructTree(int preOarr[], int inOarr[], int start, int end){
    static int id = 0;

    int current = preOarr[id++];
    treeNode* newNode = new treeNode(current);
    
    if (start == end){
        return newNode;
    }

    int pos = searchInOrder(inOarr, current, start, end);

    // To make the left sub tree
    newNode->leftChild = constructTree(preOarr, inOarr, start, pos-1);
    // To make the right sub tree
    newNode->rightChild = constructTree(preOarr, inOarr, pos+1, end);

    return newNode;
}

void average_level(treeNode *root){
    int lvl = 0;
    int nodesInlvl = 0;
    int sumInlvl = 0;

    queue <treeNode*> q;

    if(root == NULL){
        return;
    }

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        treeNode * chkNode = q.front();
        q.pop();
        
        if (chkNode != NULL){
            //cout<<chkNode->data<<" lvl -"<<lvl<<endl;
            sumInlvl += chkNode->data;
            nodesInlvl++;
            if (chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{
            if(!q.empty()){
                lvl++;
                q.push(NULL);
                cout<<((float)sumInlvl/nodesInlvl)<<" ";
                sumInlvl = 0;
                nodesInlvl = 0;
            }
        }
    }
    cout<<((float)sumInlvl/nodesInlvl)<<endl;

}

int second_minimum(treeNode *root){
    int flag = 1000000000;
    int secondMin;
    int min = 1000000000;

    queue <treeNode*> q;

    if (root == NULL){
        return -1;
    }

    q.push(root);

    while (!q.empty()){
        treeNode *chkNode = q.front();
        q.pop();

        if (chkNode->data < min){
            secondMin = min;
            min = chkNode->data;
        }else{
            if(secondMin > chkNode->data && chkNode->data != min){
                secondMin = chkNode->data;
            }
        }

        if (chkNode->leftChild != NULL){
            q.push(chkNode->leftChild);
        }

        if (chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
    }

    if (secondMin == flag){
        return -1;
    }

    return secondMin;
}


int main(){
    int n = 5;
    int preOarr[] = {3, 9, 20, 15, 7};
    int inOarr[] = {9, 3, 15, 20, 7};

    treeNode *root = constructTree(preOarr, inOarr, 0, n-1);

    printTree(root, 0);
    cout<<endl;
    average_level(root);
    cout<<endl;
    cout<<second_minimum(root);

    return 0;
}