#include <bits/stdc++.h>
#include "stack_v2.h"

using namespace std;

int main(){
    int n;
    int ele;
    int min = 10000000;
    cin>>n;

    Stack <int> eleStack;
    Stack <int> minStack;

    for (int i=0; i<n; i++){
        cin>>ele;
        if(ele<=min){
            minStack.push(ele);
            min = ele;
        }
        eleStack.push(ele);
    }

    while (!eleStack.empty()){
        ele = eleStack.pop();
        if (ele > minStack.get_top()){
            cout<<minStack.get_top()<<" ";
        }
        else if (ele == minStack.get_top()){
            //cout<<"Current top - "<<minStack.get_top()<<endl;
            cout<<minStack.pop()<<" ";
        }
    }

    return 0;
}