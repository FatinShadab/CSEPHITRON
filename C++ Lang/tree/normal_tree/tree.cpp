#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class treeNode{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "\t";
    }
}

void printTree(treeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root : " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left : ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right : ";
        printTree(root->rightChild, level + 1);
    }
}

void inOrderT(treeNode *root, string &rStr){
    
    if (root == NULL){
        return;
    }

    inOrderT(root->leftChild, rStr);
    rStr += to_string(root->data);
    inOrderT(root->rightChild, rStr);

}

void preOrderT(treeNode *root, string &rStr){
    if (root == NULL){
        return;
    }

    rStr += to_string(root->data);
    preOrderT(root->leftChild, rStr);
    preOrderT(root->rightChild, rStr);
}

void postOrderT(treeNode *root, string &rStr){

    if (root == NULL){
        return;
    }

    postOrderT(root->leftChild, rStr);
    postOrderT(root->rightChild, rStr);
    rStr += to_string(root->data);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    treeNode *allNodes[n];
    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;

        allNodes[i]->data = value;

        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }
        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    printTree(allNodes[0], 0);


    string inOrderTstr = ""; inOrderT(allNodes[0], inOrderTstr);
    
    string preOrderTstr = ""; preOrderT(allNodes[0], preOrderTstr);

    string postOrderTstr = ""; postOrderT(allNodes[0], postOrderTstr);

    cout<<"\nIn Order Tarversal : "<<inOrderTstr<<endl;
    cout<<"\nPre Order Tarversal : "<<preOrderTstr<<endl;
    cout<<"\nPost Order Tarversal : "<<postOrderTstr<<endl;

    return 0;
}

/*
5
1 3 2 
3 -1 -1
2 5 4
5 -1 -1
4 -1 -1
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
Root : 0
Left :
        Root : 1
        Left : 3
        Right : 4
Right :
        Root : 2
        Left :
                Root : 5
                Left : 7
                Right : 8
        Right : 6
InOrder Traversal :314075826
PreOrder Traversal :013425786
PostOrder Traversal :341785620
 */