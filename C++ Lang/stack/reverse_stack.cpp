#include <bits/stdc++.h>
#include "stack_v2.h"

using namespace std;

void insertAtBottom(Stack<int> &st, int ele){
    if (st.empty()){
        st.push(ele);
        return;
    }

    int topElement = st.get_top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topElement);

}

void reverseStack(Stack<int> &st){

    if (st.empty()){
        return;
    }

    int topElement = st.get_top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}

int main(){

    Stack <int> st;

    for(int i=1; i<=5; i++){
        st.push(i);
    }

    reverseStack(st);

    while (!st.empty()){
        cout<< st.pop() << endl;
    }

    return 0;
}