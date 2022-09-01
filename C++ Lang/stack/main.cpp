#include <bits/stdc++.h>
#include "stack_v1.h"

using namespace std;

int main(){
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    while (st.empty() != true){
        cout<<st.pop()<<endl;
    }

    return 0;
}