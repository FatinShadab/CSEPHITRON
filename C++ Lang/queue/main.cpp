#include <bits/stdc++.h>
#include "queue.h"

using namespace std;

int main(){
    Queue<char> q;

    for(int i=0; i<=5; i++){
        q.push('a');
    }

    if (!q.empty()){
        cout<<"Queue front - "<<q.Front()<<endl;
    }
    if (!q.empty()){
        cout<<"Queue back - "<<q.Back()<<endl;
    }

    while(!q.empty()){
        cout<<q.pop()<<" ";
    }

    if (!q.empty()){
        cout<<q.Front()<<endl;
    }
    if (!q.empty()){
        cout<<q.Back()<<endl;
    }

    return 0;
}