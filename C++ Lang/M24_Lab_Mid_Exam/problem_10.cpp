#include <bits/stdc++.h>
#include "stack_p10.h"

using namespace std;

int main(){

    Stack <int> st;

    int range;
    cin>>range;

    for(int i=1; i<=range; i++){
        st.push(i);
    }

    cout<<"MID :"<<st.mid()<<endl;

    while (!st.empty()){
        cout<< st.pop() << endl;
    }

    cout<<"MID :"<<st.mid()<<endl;

    return 0;
}