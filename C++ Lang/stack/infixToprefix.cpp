/*
    Task - Infix -> prefix
            ↓          ↓
    ex: (7+(4*5)) -> -+7*45+20

    step 1: Reverse the Infix string

    step 2: |--- if (0-9) --> print           [logic: 1]
            |--- if ')'   --> push to stack   [logic: 2]
            |--- if '('   --> pop from stack  [logic: 3]
            |--- [+, -,] [*, /,] [^], [...]   [logic: 4]
            |O.P -  1       2     3     -1    [logic: 5]

    step 3: reverse the new string
*/

#include <bits/stdc++.h>
#include "stack_v2.h"
#include <math.h>

using namespace std;

int precisionCalc(char op){
    if (op == '^'){
        return 3;
    }
    else if (op == '/' || op == '*'){
        return 2;
    }
    else if (op == '+' || op == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPrefix(string chk){
    string result;
    reverse(chk.begin(), chk.end());
    Stack <char> st;

    for (int i=0; i<chk.length(); i++){
        if (chk[i] >= '0' && chk[i] <= '9'){
            result += chk[i];
        }
        else if (chk[i] == ')'){
            st.push(chk[i]);
        }
        else if (chk[i] == '('){

            while (!st.empty() && st.get_top() != ')'){
                result += st.pop();
            }

            if (!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precisionCalc(st.get_top()) >= precisionCalc(chk[i])){
               result += st.pop(); 
            }
            st.push(chk[i]);
        }
    }

    while (!st.empty()){
        result += st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int prefixEvaluation(string chk){
    Stack <int> st;

    for (int i = chk.length()-1; i >= 0; i--){
        if (chk[i] >= '0' && chk[i] <= '9'){
            st.push(chk[i] - '0');
        }
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

    string infix = "(7+(4*5))-(2+0)";
    string prefix = infixToPrefix(infix);

    cout<<prefix<<" = "<<prefixEvaluation(prefix)<<endl;

    return 0;
}