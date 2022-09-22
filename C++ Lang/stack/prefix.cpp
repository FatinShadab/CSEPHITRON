#include <bits/stdc++.h>
#include "stack_v2.h"
#include <math.h>

using namespace std;

int prefixEvaluation(string chk){
    
    Stack<int> st;

    for (int i = chk.length()-1; i >= 0; i--){
        // case (1) : chk[i] in [0-9] --> Operand
        if (chk[i] >= '0' && chk[i] <= '9'){
            st.push(chk[i] - '0');
        }
        // case (2) : chk[i] in [+, -, *, %, /, ^] --> Operator
        else{
            int a = st.pop();
            int b = st.pop();

            switch (chk[i]){
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(a-b);
                    break;
                case '*':
                    st.push(a*b);
                    break;
                case '/':
                    st.push(a/b);
                    break;
                case '%':
                    st.push(a%b);
                    break;
                case '^':
                    st.push(pow(a, b));
                    break;
                default:
                    break;
            }
        }
    }
    
    return st.get_top();
}

int main(){
    cout<<"+*423 = "<<prefixEvaluation("+*423")<<endl;
    cout<<"+%423 = "<<prefixEvaluation("+%423")<<endl;
    cout<<"-+7*45+20 = "<<prefixEvaluation("-+7*45+20")<<endl;
    return 0;
}