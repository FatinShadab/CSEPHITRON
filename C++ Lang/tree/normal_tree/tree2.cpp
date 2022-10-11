/*

Construct a Binary Tree using Preorder and Inorder Traversal

### We use PreOrderTraversal to select which Node we will make
### We use InOrderTraversal to determine the postion to insert the node. 

n - 9
Enter the elements of preOrderArr - 0 1 3 4 2 5 7 8 6
Enter the elements of inOrderArr - 3 1 4 0 7 5 8 2 6
*/

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

void printleaves(treeNode *root){
    if (root == NULL) return;
    
    if (root->leftChild == NULL && root->rightChild == NULL){
        cout<<root->data<<" ";
        return;
    }

    printleaves(root->leftChild);
    printleaves(root->rightChild);

    return;
}

void printLeftInternalNodes(treeNode *root){
    if (root == NULL) return;

    if (root->leftChild != NULL){
        cout<<root->data<<" ";
        printLeftInternalNodes(root->leftChild);
    }
    else if (root->rightChild != NULL){
        cout<<root->data<<" ";
        printLeftInternalNodes(root->rightChild);
    }

    return;
}

void printRightInternalNodes(treeNode *root){
    if (root == NULL) return;

    if (root->rightChild != NULL){
        cout<<root->data<<" ";
        printLeftInternalNodes(root->rightChild);
    }
    else if (root->leftChild != NULL){
        cout<<root->data<<" ";
        printLeftInternalNodes(root->leftChild);
    }

    return;
}

void boundaryNodes(treeNode *root){

    if (root == NULL) return;

    cout<<root->data<<" ";

    //print Left internal nodes
    printLeftInternalNodes(root->leftChild);
    //print Left leaves
    printleaves(root->leftChild);
    //print Right leafs
    printleaves(root->rightChild);
    //print Right internal nodes
    printRightInternalNodes(root->rightChild);
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
    int n;
    cin>>n;

    int preOrderArr[n], inOrderArr[n];

    cout<<"Enter the elements of preOrderArr - ";
    for (int i=0; i<n; i++){
        cin>>preOrderArr[i];
    }

    cout<<"Enter the elements of inOrderArr - ";
    for (int i=0; i<n; i++){
        cin>>inOrderArr[i];
    }

    treeNode *root = constructTree(preOrderArr, inOrderArr, 0, n-1);

    printTree(root, 0);
    
    cout<<endl<<"Boundary Nodes of the tree - ";

    boundaryNodes(root);

    return 0;
}