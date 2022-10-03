#include <bits/stdc++.h>
#include "stack_v2.h"

using namespace std;

bool isBalancedParenthesis(string s){
    int length = s.size();
    Stack <char> st;

    for(int i=0; i<length; i++){
        // Opening Bracket --> ({[
        if (s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }

        // Closing Bracket --> )}]
        else{
            if (s[i] == ')' && st.get_top() != '('){
                return false;
            }
            else if (s[i] == '}' && st.get_top() != '{'){
                return false;
            }
            else if (s[i] == ']' && st.get_top() != '['){
                return false;
            }
            st.pop();
        }
    }

    if (!st.empty()){
        return false;
    }

    return true;
}

int main(){

    string userInput;

    cin>>userInput;

    if (isBalancedParenthesis(userInput)){
        cout<<userInput<<" is balanced."<<endl;
    }
    else{
        cout<<userInput<<" isn't balanced."<<endl;
    }

    return 0;
}