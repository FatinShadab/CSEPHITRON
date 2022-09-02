#include <bits/stdc++.h>
//#include "stack_v1.h"
#include "stack_v2.h"

using namespace std;

/*
void stack_v1_test(){
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    while (st.empty() != true){
        cout<<st.pop()<<endl;
    }
}
*/

int main(){

    Stack <pair<int, char>> st;

    cout<<"stack size -> "<<st.get_size()<<endl;
    st.push(make_pair(1, 'a'));
    cout<<"stack size -> "<<st.get_size()<<endl;
    st.push(make_pair(2, 'b'));
    cout<<"stack size -> "<<st.get_size()<<endl;
    st.push(make_pair(3, 'c'));
    cout<<"stack size -> "<<st.get_size()<<endl;

    while (!st.empty()){
        pair <int, char> chk;
        chk = st.pop();
        cout<<chk.first<<" | "<<chk.second<<endl;
    }

    return 0;
}