#include <bits/stdc++.h>

using namespace std;

int task(void){
    int size;
    cin>>size;
    int arr[size];

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    int visited[size] = {0};
    int fr[size] = {0};       
        
    for(int i=0; i<size; i++){
        if(visited[i]!=1){
           int count = 1;
           for(int j=i+1; j<size; j++){
              if(arr[i]==arr[j]){
                count++;
                visited[j]=1;
              }
            }
            fr[i] = count;
        }
    }

    int max_frequency = 0;

    for(int i=0; i<size; i++){
        if (max_frequency < fr[i]){
            max_frequency = fr[i];
        }
    }

    return size - max_frequency;
}

int main(){
    int testcases;

    cin>>testcases;

    int testRes[testcases];

    for(int testcase=0; testcase<testcases; testcase++){
        testRes[testcase] = task(); 
    }

    for(int i=0; i<testcases; i++){
        cout<<testRes[i]<<endl;
    }

    return 0;
}