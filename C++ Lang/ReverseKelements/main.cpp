#include <bits/stdc++.h>
#include "stack_v2.h"
#include "queue.h"

using namespace std;

int main(){
    int n, k;
    int step, extra_step;

    cin>>n;
    cin>>k;

    Queue <int> qObj;
    Stack <int> sObj;

    step = n/k;
    extra_step = n%k;

    for (int i=0; i<n; i++){
        int ele;
        cin>>ele;
        qObj.push(ele);
    }

    while(step-- != 0){
        for(int i=0; i<k; i++){
            int temp;
            temp = qObj.pop();
            sObj.push(temp);
        }
        for(int i=0; i<k; i++){
            qObj.push(sObj.pop());
        }
    }

    for(int i=0; i<extra_step; i++){
        int temp;
        temp = qObj.pop();
        sObj.push(temp);
    }
    while(!sObj.empty()){
        qObj.push(sObj.pop());
    }
    
    while(!qObj.empty()){
        cout<<qObj.pop()<<" ";
    }
    
    return 0;
}