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

void levelOrderTraversal(treeNode *root, string &rStr){
    if (root == NULL){
        return;
    }

    queue <treeNode*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        treeNode* chkNode = q.front();
        q.pop();
        if(chkNode != NULL){
            //cout<< chkNode->data << " ";
            rStr += to_string(chkNode->data);

            if (chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
            }

            if (chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

int maxElementAtKlvl(treeNode *root, int K){
    int lvl = 0;
    int max = -999999;
    queue <treeNode*> q;

    if(root == NULL){
        return -1;
    }

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        treeNode * chkNode = q.front();
        q.pop();
        
        if (chkNode != NULL){
            if (lvl == K){
                if(chkNode->data > max){
                    max = chkNode->data;
                }
            }
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
            }
        }
    
    }
    
    cout<<"Exit from while loop with max - "<<max<<endl;

    return max;
}

int minElementAtKlvl(treeNode *root, int K){
    int lvl = 0;
    int min = 1000000000;
    queue <treeNode*> q;

    if (root == NULL){
        return -1;
    }

    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        treeNode *chkNode = q.front();
        q.pop();

        if (chkNode != NULL){
            if (lvl == K){
                if (chkNode->data < min){
                    min = chkNode->data;
                }
            }

            if (chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
            }

            if (chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{
            if (!q.empty()){
                lvl++;
                q.push(NULL);
            }
        }
    }

    return min;
}


int main(int argc, char const *argv[])
{
    int n, K;
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

    string lvlOrderTstr = ""; levelOrderTraversal(allNodes[0], lvlOrderTstr);

    cout<<"\nIn Order Tarversal : "<<inOrderTstr<<endl;
    cout<<"\nPre Order Tarversal : "<<preOrderTstr<<endl;
    cout<<"\nPost Order Tarversal : "<<postOrderTstr<<endl;
    cout<<"\nLevel Order Tarversal : "<<lvlOrderTstr<<endl;

    cout<<"\nEnter the level number to find the max, min element in K level : ";
    cin>>K;

    int max = maxElementAtKlvl(allNodes[0], K);
    int min = minElementAtKlvl(allNodes[0], K);

    cout<<"\nThe max element at level - '"<<K<<"' is - "<<max<<endl;
    cout<<"\nThe min element at level - '"<<K<<"' is - "<<min<<endl;


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