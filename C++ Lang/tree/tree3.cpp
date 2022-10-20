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

treeNode* invert_tree(treeNode* root){
    if (root == NULL){
        return root;
    }

    treeNode* tempNode = root->leftChild;
    root->leftChild = root->rightChild;
    root->rightChild = tempNode;

    invert_tree(root->leftChild);
    invert_tree(root->rightChild);

    return root;
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

int main(){
  /*int n = 5;
    int preOarr[] = {3, 9, 20, 15, 7};
    int inOarr[] = {9, 3, 15, 20, 7};*/

    int n = 7;
    int preOarr[] = {4, 2, 1, 3, 7, 6, 9};
    int inOarr[] = {1, 2, 3, 4, 6, 7, 9};

    treeNode *root = constructTree(preOarr, inOarr, 0, (n-1));

    cout<<"Original Tree :";
    printTree(root, 0);

    treeNode *invertedTroot = invert_tree(root);

    cout<<"Inverted Tree :";
    printTree(invertedTroot, 0);

    return 0;
}